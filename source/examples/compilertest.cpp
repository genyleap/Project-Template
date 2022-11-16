#include "compilertest.hpp"
#include "common.hpp"
#include <iostream>

using namespace std;

CompilerTest::CompilerTest() {
}

void CompilerTest::getCompilerInfo() const noexcept {
  cout << "Compiler Name : " << COMPILER << endl;
  cout << "Compiler Version : " << COMPILER_VER << endl;
}

void CompilerTest::checkByCompiler() const noexcept {
  std::cout << "========COMPILER TEST========" << std::endl;
  //! Compiler Stataement
#if defined(COMPILER_CLANG_LLVM)
  cout << "Clang compiler has been detected!\n";
#elif defined(COMPILER_INTEL)
  cout << "Intel compiler has been detected!\n";
#elif defined(COMPILER_MINGW)
  cout << "MinGW compiler has been detected!\n";
#elif defined(COMPILER_MINGW_64)
  cout << "MinGW64 compiler has been detected!\n";
#elif defined(COMPILER_GCC)
  cout << "GCC compiler has been detected!\n";
#elif defined(COMPILER__HEWLETT)
  cout << "Hewlett compiler has been detected!\n";
#elif defined(COMPILER_IBM)
  cout << "IBM compiler has been detected!\n";
#elif defined(COMPILER_MSVC)
  cout << "MSVC compiler has been detected!\n";
#elif defined(COMPILER_PGCC)
  cout << "PGCC compiler has been detected!\n";
#elif defined(COMPILER_ORACLE)
  cout << "Oracle compiler has been detected!\n";
#endif
  std::cout << "========COMPILER TEST========" << std::endl;
}
