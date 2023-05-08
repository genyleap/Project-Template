#include "librarytest.hpp"
#include "common.hpp"
#include <iostream>

#ifdef USE_BOOST
#   include <boost/chrono.hpp>
#endif

#ifdef USE_OPENSSL
#   include <openssl/evp.h>
#   include <openssl/sha.h>
#endif

#ifdef USE_OPENCV
#   include <opencv2/core.hpp>
#   include <opencv2/imgcodecs.hpp>
#   include <opencv2/highgui.hpp>
#endif

#ifdef USE_JWT
#   include <jwt-cpp/jwt.h>
#endif

LibraryTest::LibraryTest()
{
}

#ifdef USE_OPENSSL
void LibraryTest::testOpenSSL() const noexcept
{
    std::cout << "========OPENSSL TEST========" << std::endl;
    //!OpenSSL Library
    std::cout << "OpenSSL version: " << OPENSSL_VERSION_STR << std::endl;

    std::string str {"Hello, World!"};
    // Initialize the hash context
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_MD_CTX_init(ctx);

    // Set the hash algorithm
    const EVP_MD* md = EVP_sha256();

    // Initialize the digest buffer
    unsigned char digest[SHA256_DIGEST_LENGTH];

    // Hash the input string
    EVP_DigestInit_ex(ctx, md, nullptr);
    EVP_DigestUpdate(ctx, str.c_str(), str.length());
    EVP_DigestFinal_ex(ctx, digest, nullptr);

    // Convert the digest buffer to string
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }

    // Clean up the hash context
    EVP_MD_CTX_free(ctx);

    std::string hash = ss.str();

    std::cout << "Hash of " << str << " is " << hash << std::endl;
}
#endif

#ifdef USE_OPENCV
void LibraryTest::testOpenCV() const noexcept
{
    std::cout << "========OpenCV TEST========" << std::endl;
    std::string image_path = cv::samples::findFile("starry_night.jpg");
    cv::Mat img = imread(image_path, cv::IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
    }
    imshow("Display window", img);
    int k = cv::waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        imwrite("starry_night.png", img);
    }
}
#endif

#ifdef USE_BOOST
void LibraryTest::testBoost() const noexcept
{
    std::cout << "========BOOST TEST========" << std::endl;
    std::cout << "Boost version: " << BOOST_VERSION << std::endl;
    std::cout << "Boost Lib Clock Test\n";
    boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
    for ( long i = 0; i < 10000000; ++i )
        std::sqrt( 123.456L ); // burn some time
    boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
    std::cout << "took " << sec.count() << " seconds\n";
}
#endif

#ifdef USE_JWT
void LibraryTest::testJwt() const noexcept
{
    // Set the secret key used to sign and verify JWTs
    std::string secret_key = "my_secret_key";

    // Create a JWT with a payload
    std::string payload = R"({
        "user_id": 12345,
        "email": "user@example.com"
    })";
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point exp = now + std::chrono::seconds(30); // expires in 30 seconds
    std::string token = jwt::create()
                            .set_issuer("my_app")
                            .set_subject("auth_token")
                            .set_issued_at(now)
                            .set_expires_at(exp)
                            .set_payload_claim("data", jwt::claim(payload))
                            .sign(jwt::algorithm::hs256{ secret_key });

    // Print the JWT
    std::cout << "Token: " << token << std::endl;

    // Verify the JWT and extract the payload
    try {
        jwt::decoded_jwt decoded = jwt::decode(token);
        jwt::verify()
            .allow_algorithm(jwt::algorithm::hs256{ secret_key })
            .with_issuer("my_app")
            .with_subject("auth_token")
            .verify(decoded);
        std::string payload_str = decoded.get_payload_claim("data").as_string();
        std::cout << "Payload: " << payload_str << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}
#endif
