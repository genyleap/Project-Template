#ifndef LIBRARYTEST_HPP
#define LIBRARYTEST_HPP

class LibraryTest
{
public:
    LibraryTest();
#ifdef USE_OPENSSL
    void testOpenSSL() const noexcept;
#endif
#ifdef USE_BOOST
    void testBoost() const noexcept;
#endif
#ifdef USE_OPENCV
    void testOpenCV() const noexcept;
#endif
#ifdef USE_JWT
    void testJwt() const noexcept;
#endif
};

#endif // LIBRARYTEST_HPP
