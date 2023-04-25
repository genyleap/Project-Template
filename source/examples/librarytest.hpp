#ifndef LIBRARYTEST_HPP
#define LIBRARYTEST_HPP

class LibraryTest
{
public:
  LibraryTest();
  void testOpenSSL() const noexcept;
  void testOpenCV() const noexcept;
  void testBoost() const noexcept;
};

#endif // LIBRARYTEST_HPP
