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

LibraryTest::LibraryTest()
{
}

void LibraryTest::testOpenSSL() const noexcept
{
    std::cout << "========OPENSSL TEST========" << std::endl;
    //!OpenSSL Library
#ifdef USE_OPENSSL
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

#else
    std::cout << "OpenSSL Library is not available.\n";
#endif
    std::cout << "========OPENSSL TEST========" << std::endl;
}

void LibraryTest::testOpenCV() const noexcept
{
    std::cout << "========OpenCV TEST========" << std::endl;
#ifdef USE_OPENCV
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
#else
    std::cout << "OpenCV Library is not available.\n";
#endif
    std::cout << "========OpenCV TEST========" << std::endl;
}


void LibraryTest::testBoost() const noexcept
{
std::cout << "========BOOST TEST========" << std::endl;
  //!Boost Library
#ifdef USE_BOOST
  std::cout << "Boost version: " << BOOST_VERSION << std::endl;
  std::cout << "Boost Lib Clock Test\n";
  boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
  for ( long i = 0; i < 10000000; ++i )
    std::sqrt( 123.456L ); // burn some time
  boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
  std::cout << "took " << sec.count() << " seconds\n";
#else
  std::cout << "Boost Library is not available.\n";
#endif
  std::cout << "========BOOST TEST========" << std::endl;
}
