#include "examples/compilertest.hpp"
#include "common.hpp"
#include <iostream>

using namespace std;

CompilerTest::CompilerTest()
{

}

void CompilerTest::getCompilerInfo() const noexcept
{
  cout << "Compiler Name : " << __COMPILER__ << endl;
  cout << "Compiler Version : " << __COMPILER_VER__ << endl;
}

void CompilerTest::checkByCompiler() const noexcept
{
  //!Compiler Stataement
#if defined(__COMPILER_CLANG_LLVM_)
  cout << "Clang compiler has been detected!\n";
#elif defined(__COMPILER_INTEL__)
  cout << "Intel compiler has been detected!\n";
#elif defined(__COMPILER_MINGW__)
  cout << "MinGW compiler has been detected!\n";
#elif defined(__COMPILER_MINGW_64__)
  cout << "MinGW64 compiler has been detected!\n";
#elif defined(__COMPILER_GCC__)
  cout << "GCC compiler has been detected!\n";
#elif defined(__COMPILER__HEWLETT_)
  cout << "Hewlett compiler has been detected!\n";
#elif defined(__COMPILER_IBM__)
  cout << "IBM compiler has been detected!\n";
#elif defined(__COMPILER_MSVC__)
  cout << "MSVC compiler has been detected!\n";
#elif defined(__COMPILER_PGCC__)
  cout << "PGCC compiler has been detected!\n";
#elif defined(__COMPILER_ORACLE__)
  cout << "Oracle compiler has been detected!\n";
#endif


}
