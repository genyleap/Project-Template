#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

/*!
 * MIT License
 *
 * Copyright (c) 2021 Kambiz Asadzadeh
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!
 * namespace Preprocessor
 * This preprocessor helps you to detect compiler, platform, and architecture.
 */

namespace Preprocessor {


//!COMPILERS
#if defined(__clang__)
/* Clang/LLVM. ---------------------------------------------- */
#   undef  __COMPILER__
#   define __COMPILER__    "Clang/LLVM"
#   undef  __COMPILER_CLANG_LLVM_
#   define __COMPILER_CLANG_LLVM_    "Clang/LLVM"
#   undef  __COMPILER_VER__
#   define __COMPILER_VER__    __clang_version__
#elif (defined(__clang__) && !defined(__llvm__)) && !defined(__GNUC__)
#elif defined(__ICC) || defined(__INTEL_COMPILER)
/* Intel ICC/ICPC. ------------------------------------------ */
#   undef __COMPILER__
#   define __COMPILER__          "Intel ICC/ICPC"
#   undef __COMPILER_INTEL__
#   define __COMPILER_INTEL__    "Intel ICC/ICPC"
#   define __COMPILER_VER__    __INTEL_COMPILER_BUILD_DATE
#elif defined(__MINGW32__) && !defined (__amd64__) && !defined (__amd64) && !defined (__ia64__)
/* __MINGW32__. ------------------------------------------------- */
#   undef  __COMPILER__
#   define __COMPILER__    "MinGW-w86 (x86) 32 Bit"
#   undef  __COMPILER_MINGW__
#   define __COMPILER_MINGW__    "MinGW-w86 (x86) 32 Bit"
#   undef  __COMPILER_VER__
#   define __COMPILER_VER__    __MINGW32_MAJOR_VERSION << "." << __MINGW32_MINOR_VERSION
#elif defined(__MINGW32__)
/* __MINGW64_32__. ------------------------------------------------- */
#   undef  __COMPILER__
#   define __COMPILER__    "MinGW-w64 (x86_64) 32-64 Bit"
#   undef  __COMPILER_MINGW64_32__
#   define __COMPILER_MINGW64_32__    "MinGW-w64 (x86_64) 32-64 Bit"
#   undef  __COMPILER_VER__
#   define __COMPILER_VER__    __MINGW32_MAJOR_VERSION << "." << __MINGW32_MINOR_VERSION
#elif defined(__MINGW64__)
/* __MINGW64__. ------------------------------------------------- */
#   undef  __COMPILER__
#   define __COMPILER__    "MinGW-w64 (x64) 64 Bit"
#   undef  __COMPILER_MINGW_64__
#   define __COMPILER_MINGW_64__    "MinGW-w64 (x64) 64 Bit"
#   undef  __COMPILER_VER__
#   define __COMPILER_VER__    __MINGW64_MAJOR_VERSION << "." << __MINGW64_MINOR_VERSION
#elif defined(__GNUC__) || defined(__GNUG__) && !defined (__clang__)
#define GCC_VERSION __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__
/* GNU GCC/G++. --------------------------------------------- */
#   undef  __COMPILER__
#   define __COMPILER__        "GNU GCC/G++"
#   undef  __COMPILER_GNU__
#   define __COMPILER_GNU__    "GNU GCC/G++"
#   undef  __COMPILER_GCC__
#   define __COMPILER_GCC__    "GNU GCC/G++"
#   undef  __COMPILER_VER__
#   define __COMPILER_VER__    GCC_VERSION
#elif defined(__HP_cc) || defined(__HP_aCC)
/* Hewlett-Packard C/aC++. ---------------------------------- */
#   undef __COMPILER__
#   define __COMPILER__    "Hewlett-Packard C/aC++"
#   undef __COMPILER__HEWLETT_
#   define __COMPILER__HEWLETT_    "Hewlett-Packard C/aC++"
#   define __COMPILER_VER__    __HP_aCC
#elif defined(__IBMC__) || defined(__IBMCPP__)
/* IBM XL C/C++. -------------------------------------------- */
#   undef  __COMPILER__
#   define __COMPILER__    "IBM XL C/C++"
#   undef  __COMPILER_IBM__
#   define __COMPILER_IBM__    "IBM XL C/C++"
#   define __COMPILER_VER__    __xlC_ver__
#elif defined(_MSC_VER)
/* Microsoft Visual Studio. --------------------------------- */
#   undef  __COMPILER__
#   define __COMPILER__  "MSVC++ "
#   undef  __COMPILER_MSVC__
#   define __COMPILER_MSVC__  "MSVC++ "
#   undef  __COMPILER_VER__
#define    __COMPILER_VER__   _MSC_VER
#elif defined(__PGI)
/* Portland Group PGCC/PGCPP. ------------------------------- */
#   undef __COMPILER__    "PGCC/PGCPP"
#   define __COMPILER__    "PGCC/PGCPP"
#   undef __COMPILER_PGCC__    "PGCC/PGCPP"
#   define __COMPILER_PGCC__    "PGCC/PGCPP"
#   define __COMPILER_VER__    __VERSION__
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
/* Oracle Solaris Studio. ----------------------------------- */
#   undef __COMPILER__    "Oracle Solaris"
#   define __COMPILER__    "Oracle Solaris"
#   undef __COMPILER_ORACLE__    "Oracle Solaris"
#   define __COMPILER_ORACLE__    "Oracle Solaris"
#   define __COMPILER_VER__    __SUNPRO_CC
#endif

#if defined (_MSC_VER) && _MSC_VER == 1400
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 8.0"
#elif defined (_MSC_VER) && _MSC_VER == 1500
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 9.0"
#elif defined (_MSC_VER) && _MSC_VER == 1600
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 10.0"
#elif defined (_MSC_VER) && _MSC_VER == 1700
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 11.0"
#elif defined (_MSC_VER) && _MSC_VER == 1800
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 12.0"
#elif defined (_MSC_VER) && _MSC_VER == 1900
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 14.0"
#elif defined (_MSC_VER) && _MSC_VER == 1910
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 15.0"
#elif defined (_MSC_VER) && _MSC_VER == 1911
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 15.3"
#elif defined (_MSC_VER) && _MSC_VER == 1912
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 15.5"
#elif defined (_MSC_VER) && _MSC_VER == 1913
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 15.6"
#elif defined (_MSC_VER) && _MSC_VER == 1914
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 15.7"
#elif defined (_MSC_VER) && _MSC_VER == 1915
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 15.8"
#elif defined (_MSC_VER) && _MSC_VER == 1915
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 15.8"
#elif defined (_MSC_VER) && _MSC_VER == 1916
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 15.9"
#elif defined (_MSC_VER) && _MSC_VER == 1920
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ RTW 16.0"
#elif defined (_MSC_VER) && _MSC_VER == 1921
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.1"
#elif defined (_MSC_VER) && _MSC_VER == 1922
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.2"
#elif defined (_MSC_VER) && _MSC_VER == 1923
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.3"
#elif defined (_MSC_VER) && _MSC_VER == 1924
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.4"
#elif defined (_MSC_VER) && _MSC_VER == 1925
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.5"
#elif defined (_MSC_VER) && _MSC_VER == 1926
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.6"
#elif defined (_MSC_VER) && _MSC_VER == 1927
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.7"
#elif defined (_MSC_VER) && _MSC_VER == 1928
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.8, 16.9"
#elif defined (_MSC_VER) && _MSC_VER == 1929
#   undef  __MSVC__
#   define __MSVC__  "MSVC++ 16.10"
#endif

//!LANGUAGE STANDARD
#if __cplusplus == 199711L && !defined (_MSC_VER)
/* C++98:  __cplusplus is 19971L.*/
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__  "C++98"
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  "19971L"
#elif __cplusplus == 201103L
/* C++11:  __cplusplus is 201103L.*/
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__ "C++11"
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  "201103L"
#elif __cplusplus == 201402L
/* C++14:  __cplusplus is 201402L.*/
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__  "C++14"
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  "201402L"
#elif __cplusplus == 201702L || __cplusplus == 201703
/* C++17:  __cplusplus is c++1z.*/
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__  "C++17"
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  "201703"
#elif __cplusplus == 201707 || __cplusplus == 202002L || __cplusplus == 201709
/* C++20:  __cplusplus is c++2a.*/
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__  "C++20"
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  __cplusplus
#elif __cplusplus == 20120
/* C++23:  __cplusplus is c++2b.*/
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__  "C++23"
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  __cplusplus
#elif __embedded_cplusplus
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__ "Embedded C++"
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  "19971L"
#elif defined(__clang__)
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__  __cplusplus
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  __cplusplus
#elif defined(__GNUC__)
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__  __cplusplus
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  __cplusplus
#else
#   undef  __CPP_VERSION__
#   define __CPP_VERSION__  0
#   undef  __CPP_VALUE__
#   define __CPP_VALUE__  "Unknown"
#endif

//!EXPORTS & EXTRA
#if defined(__WINNT) || defined(__WINNT__) || defined(WIN32) || defined(_WIN32) \
    || defined(__WIN32) || defined(__WIN32__) || defined(WIN64) || defined(_WIN64) \
    || defined(__WIN64) || defined(__WIN64__)
//!Microsoft Windows
#define __project_export __declspec(dllexport)
#define __project_import __declspec(dllimport)
#elif defined(__GNUC__)
//!Define for Unix base OS such as: Linux, macOS, FreeBSD, etc...
#define __project_export __attribute__((visibility("default")))
#define __project_import __attribute__((visibility("default")))
#define __project_hidden __attribute__((visibility("hidden")))
#else
//  do nothing and hope for the best?
#define __PROJECT_export
#define __PROJECT_import
#pragma warning Unknown dynamic link import / export semantics.
#endif

#define __project_date_  __DATE__
#define __project_time_  __TIME__
#define __project_function_  __FUNCTION__
#define __project_line_  __LINE__
#define __project_file_  __FILE__
#define __project_counter_  __COUNTER__

/* NOTICE:  __attribute__ is Linux syntax; __declspec is the Windows syntax.*/
/*The __declspec(noinline) attribute suppresses the inlining of a function at the call points of the function.

__declspec(noinline) can also be applied to constant data, to prevent the compiler from using the value for optimization purposes, without affecting its placement in the object. This is a feature that can be used for patchable constants, that is, data that is later patched to a different value. It is an error to try to use such constants in a context where a constant value is required. For example, an array dimension.
*/

#if defined(__WINNT) || defined(__WINNT__) || defined(WIN32) || defined(_WIN32) \
    || defined(__WIN32) || defined(__WIN32__) || defined(WIN64) || defined(_WIN64) \
    || defined(__WIN64) || defined(__WIN64__)
#define __PROJECT_noInline __declspec(noinline)
#define __PROJECT_inline inline
#else
///Define for Unix base OS such as: Linux, macOS, FreeBSD, etc...
#define __project_noInline __attribute__((noinline))
#define __project_inline inline
#endif

//!ARCHITECTURE

/*
 * Classic Standard
 * 32-bit and 64-Bit systems
 * Developer:	Intel & AMD Holdings
 * Processors:	Intel & AMD Machine
 * (64-bit):	EM64T, IA-32e, Intel64, x64, x86-64
 * (32-bit):	IA-32, i386, x86, x86-32
 * Processors:	Athlon, Atom, Core, Core 2, Core i3/i5/i7, Opteron, Pentium, Phenom, Sempron, Turion, etc.
 */

#if (defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_IX86) || defined(_X86_)) && !defined(__amd64)
//!x86 based systems (32-bit)
#undef    __X86_64bit__
#define   __X86_64bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Intel"
#undef    __ARCHITECTURE__
#define   __ARCHITECTURE__ "x86 (32-Bit)"
#elif defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(_M_AMD64) || defined(_M_X64) && !defined(X86_32bit)
//!x64 based systems (64-bit)
#undef    __X64_64bit__
#define   __X64_64bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Intel"
#undef    __ARCHITECTURE__
#define   __ARCHITECTURE__ "x86_64 (64-Bit)"
#endif


/*
 * x86 and x86-64
 * (64-bit):	EM64T, IA-32e, Intel64, x64, x86-64
 * (32-bit):	IA-32, i386, x86, x86-32
 * Developers:	Intel only
 * Processors:	Athlon
 *
*/

#if defined(__i386__) && !defined(_M_AMD64)
/* x86 32-bit ----------------------------------------------- */
#undef    __INTEL_32bit__
#define   __INTEL_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Intel"
#undef __ARCHITECTURE_INTEL__
#define __ARCHITECTURE_INTEL__ "x86 (32-Bit)"
#elif defined(__x86_64__) && !defined(_M_AMD64)
/* x64 64-bit ----------------------------------------------- */
#undef    __INTEL_64bit__
#define   __INTEL_64bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Intel"
#undef __ARCHITECTURE_INTEL__
#define __ARCHITECTURE_INTEL__ "x86_64 (64-Bit)"
#endif

/*
 * x86 and x86-64
 * (32-bit):    i386, x86, x86-32
 * (64-bit):	AMD64, x64
 * Developers:	AMD only
 * Processors:	Athlon
 *
*/

#if defined(__i386__) && !defined(__x86_64__)
/* x86 32-bit ----------------------------------------------- */
#undef    __AMD_32bit__
#define   __AMD_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "AMD"
#undef __ARCHITECTURE__
#undef __ARCHITECTURE_AMD__
#define __ARCHITECTURE_AMD__ "x86 (32-Bit)"
#elif (defined(__amd64__) || defined(__amd64) || defined(_M_AMD64)) && !defined(__x86_64__)
/* x64 64-bit ----------------------------------------------- */
#undef    __AMD_64bit__
#define   __AMD_64bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "AMD"
#undef __ARCHITECTURE_AMD__
#define __ARCHITECTURE_AMD__ "x86_64 (64-Bit)"
#endif

/*
 * Alpha AXP
 * (64-bit):	x64
 * (32-bit):	x86
 * Developers:	Digital Equipment Corporation
 * Processors:	Alpha
 *
*/

#if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
/* Alpha ----------------------------------------------- */
#undef    __ALPHA_32bit__
#define   __ALPHA_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Alpha"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "Alpha (32-Bit)"
#endif

/*
 * ARM
 * 32-bit
 * Developer:	ARM Holdings
 * Processors:	Acorn RISC Machine
 */

#if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm)
/* ARM-x86 -------------------------------------------------- */
#undef    __ARM_32bit__
#define   __ARM_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Arm"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "Arm (32-Bit)"
#endif

/*
 * ARM
 * 64-bit
 * Developer:	ARM Holdings
 * Processors:	Acorn RISC Machine
 */

#if defined(__aarch64__)
/* ARM-x64 -------------------------------------------------- */
#undef    __ARM_64bit__
#define   __ARM_64bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Arm64"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "ARM64 (64-Bit)"
#endif

/*
 * PA-RISC
 * 32-bit
 * Developer:	Convex Computer Corporation
 * Processors:	PA-RISC
 */

#if defined(__convex__)
/* Blackfin -------------------------------------------------- */
#undef    __PA_RISC_32bit__
#define   __PA_RISC_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Convex PA-RISC"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "RISC (32-Bit)"
#endif

/*
 * Epiphany
 * 32-bit & 64-bit
 * Developer:	Adapteva
 * Processors:	Epiphany
 */

#if defined(__epiphany__)
/* Convex -------------------------------------------------- */
#undef    __EP_32bit__
#define   __EP_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Adapteva Epiphany"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "Epiphany (32-Bit)"
#endif

/*
 * Motorola 68000
 * 32-bit
 * Developer:	Motorola
 * Processors:	Motorola 68000
 */

#if defined(__m68k__) || defined(M68000) || defined(__MC68K__)
/* Convex -------------------------------------------------- */
#undef    __MOTOROLA_32bit__
#define   __MOTOROLA_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Motorola 68000"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "Motorola (32-Bit)"
#endif
/*
     * Notes:
     * "IA64" is the old name for the processor __ARCHITECTURE__. Intel now prefers "Itanium".
     * There is no single Itanium processor macro defined by all compilers on all OSes. An #if/#endif that checks multiple macros is required.
     * Microsoft's support for Itanium ended after Visual Studio 2010 and Windows Server 2008.
     * Clang/LLVM currently does not support Itanium processors.
     */

/*
 * POWER
 * PowerPC
 * Developer:	IBM, Freescale
 * Processors:	PowerPC, POWER 1/2/3/4/5/6/7, G1, G2, G3, G4, G5, etc.
 */

///Indicates that the target architecture is PowerPC®.
#if defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(__ppc__) || defined(_M_PPC) || defined(__PPC) || defined(__PPC__)
/* POWER ---------------------------------------------------- */
#undef    __POWER_PC_32bit__
#define   __POWER_PC_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Power PC"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "PowerPC (32-Bit)"
///Indicates that the target architecture is PowerPC and that 64-bit compilation mode is enabled.
#elseif defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(__64BIT__) || defined(_LP64) || defined(__LP64__)
/* POWER 64-bit --------------------------------------------- */
#undef    __POWER_PC_64bit__
#define   __POWER_PC_64bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Power PC"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "PowerPC (64-Bit)"
#endif

/*
 * Notes:
 * There is no single POWER processor macro defined by all compilers on all OSes. An #if/#endif that checks multiple macros is required.
 * GCC for AIX, NetBSD, and OpenBSD defines the same macros for 32-bit and 64-bit POWER processors.
 * For AIX, __64BIT__ is defined for 64-bit POWER. For OpenBSD, _LP64 and __LP64__ are defined for 64-bit POWER. For NetBSD, GCC doesn't provide a macro to check for 64-bit use.
 * Apple's OSX support for POWER processors ended after OSX 10.5 Leopard in 2007. The open source Darwin distribution, on which OSX is based, is still available for POWER processors.
 */

/*
 * SPARC
 * Developer:	Oracle, Fujitsu, Sun
 * Processors:	UltraSPARC I/II/III/IV/T1/T2, SPARC T3/T4, etc.
 */

/*
 *  Notes:
 *  GCC defines processor name macros depending upon the value of the -march command-line option.
 *  These include__sparclite__, __sparclet__, __sparc_v8__, __sparc_v9__, __supersparc__, __hypersparc__, and so forth.
 *  However, other compilers don't provide this level of detail and writing code that depends upon these macros is probably a bad idea.
 */

#if defined(sparc) || defined(__sparc) || defined(__sparc__) || defined(__sparc64__)
/* x86 32-bit ----------------------------------------------- */
#undef    __SPARC_32bit__
#define   __SPARC_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Sparc"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "Sparc (32-Bit)"
#elif defined(__sparc64__)
/* x64 64-bit ----------------------------------------------- */
#undef    __SPARC_64bit__
#define   __SPARC_64bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Sparc"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "Sparc (64-Bit)"
#endif

/*
 * ARM
 * 32-bit
 * Developer:	ARM Holdings
 * Processors:	Acorn RISC Machine
 */

#if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm)
/* ARM-x86 -------------------------------------------------- */
#undef    __ARM_32bit__
#define   __ARM_32bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Arm"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "Arm (32-Bit)"
#endif

/*
 * ARM
 * 64-bit
 * Developer:	ARM Holdings
 * Processors:	Acorn RISC Machine
 */

#if defined(__aarch64__)
/* ARM-x64 -------------------------------------------------- */
#undef    __ARM_64bit__
#define   __ARM_64bit__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Arm64"
#undef __ARCHITECTURE__
#define __ARCHITECTURE__ "Arm64 (64-Bit)"
#endif

//Embedded Architecture
#if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm)
#undef    __EMBEDDED__
#define   __EMBEDDED__
#undef    __PROCESSOR__
#define   __PROCESSOR__ "Ebedded Unknown!"
#undef IS_EMBEDDED
#define IS_EMBEDDED 1
#endif

//!PLATFORM

/*
        Supported platforms:
     *      - Mac OSX, iPhone, Darwin
     *      - Orbis
     *      - OpenBSD
     *      - Generic BSD
     *      - Atari ST TOS
     *      - AmigaOS
     *      - Windows
     *      - Flashplayer (Crossbridge)
     *      - QNX
     *      - TI-Nspire
     *      - Emscripten
     *      - Linux
     *      - Solaris
     *      - Generic POSIX
     *      - Cygwin
     *      - Generic UNIX
     *      - Generic fallback
     *      - Playstation
     *      - Xbox
     *  Supported architectures:
     *      - x86
     *      - x64
     *      - ARM 32-bit
     *      - ARM 64-bit
     *      - MIPS 32-bit
     *      - MIPS 64-bit
     *      - PowerPC 32-bit
     *      - PowerPC 64-bit
     *      - SPARC 32-bit
     *      - SPARC 64-bit
     *      - SuperH
     *      - Motorola 68k
     *      - Emscripten
     *      - Generic
     *
     *  Supported compilers:
     *      - Clang
     *      - GCC
     *      - MSVC
     *      - Emscripten
     *      - TinyC
     *      - VBCC
     *      - Bruce's C compiler
     *      - Generic
     *
     */


/*
     * AIX
     * Developer:	IBM
     * Distributions:	AIX
     * Processors:	POWER
     */


#if defined (X86_32bit) && defined(_AIX) || defined (__TOS_AIX__) || defined (__xlC__)
/* IBM AIX. ------------------------------------------------- */
#   define PLATFORM_OS      "AIX"
#   define PLATFORM_ARCH    "x86 (32-Bit)"
#   define PLATFORM_AIX     "AIX"
#   define PLATFORM_TYPE    "UNIX AIX"
#   elif defined (X64_64bit) && defined(_AIX) || defined (__TOS_AIX__) || defined (__xlC__)
/* IBM AIX. ------------------------------------------------- */
#   define PLATFORM_OS      "AIX"
#   define PLATFORM_ARCH    "x64 (64-Bit)"
#   define PLATFORM_AIX     "AIX"
#   define PLATFORM_TYPE    "UNIX AIX"
#endif

/*
     * HP-UX
     * Developer:	Hewlett-Packard
     * Distributions:	HP-UX
     * Processors:	Itanium
     */

#if defined (X86_32bit) && defined(hpux) || defined(__hpux) || defined(__hpux) || defined(__hpux)
/* Hewlett-Packard HP-UX. ----------------------------------- */
#   define PLATFORM_OS     "HP"
#   define PLATFORM_ARCH   "x86 (32-Bit)"
#   define PLATFORM_HP     "HP"
#   define PLATFORM_TYPE   "UNIX HP-UX"
#   elif defined (X64_64bit) && defined (X86_32bit) && defined(hpux) || defined(__hpux) || defined(__hpux) || defined(__hpux)
/* Hewlett-Packard HP-UX. ----------------------------------- */
#   define PLATFORM_OS     "HP"
#   define PLATFORM_ARCH   "x64 (64-Bit)"
#   define PLATFORM_HP     "HP"
#   define PLATFORM_TYPE   "UNIX HP-UX"
#endif

/*
     * Linux
     * Developer:	Open source
     * Distributions:	Centos, Debian, Fedora, OpenSUSE, RedHat, Ubuntu
     * Processors:	x86, x86-64, POWER, etc.
     */

#if defined(__linux__) && defined(linux) && !defined(__ANDROID__) && !defined(ANDROID)
/* Linux. --------------------------------------------------- */
#   define PLATFORM_OS        "Linux"
#   define PLATFORM_ARCH      "x86 (32-Bit)"
#   define PLATFORM_LINUX     "Linux"
#   define PLATFORM_DEVICE                 "Desktop"
#   define PLATFORM_TYPE      "Unix (Linux)"
#   elif defined (X64_64bit) && defined(__linux) && defined(__linux__) && defined(linux) && !defined(__ANDROID__) && !defined(ANDROID)
/* Linux. --------------------------------------------------- */
#   define PLATFORM_OS        "Linux"
#   define PLATFORM_ARCH      "x64 (64-Bit)"
#   define PLATFORM_LINUX     "Linux"
#   define PLATFORM_DEVICE                 "Desktop"
#   define PLATFORM_TYPE      "Unix (Linux)"
#endif

/*
     * OSX, iOS, and Darwin
     * Developer:	Apple and open source
     * Distributions:	OSX, iOS, Darwin
     * Processors:	x86, x86-64, ARM
     */


#if defined(__APPLE__) && defined(__MACH__)
//Detect for x86
/* Apple OSX and iOS (Darwin). ------------------------------ */
#include <TargetConditionals.h>
#if TARGET_OS_SIMULATOR == 1
/* iOS in Xcode simulator */
#   define PLATFORM_OS             "Apple iOS"
#   define PLATFORM_ARCH           "x86 (32-Bit)"
#   define PLATFORM_IOS_SIMULATOR  "iOS Simulator"
#   define PLATFORM_TYPE           "iOS-Emulator"
#   elif TARGET_OS_WATCH == 1
/* iOS on iWatch. */
#   define PLATFORM_OS             "Apple iOS"
#   define PLATFORM_ARCH           "x86 (32-Bit)"
#   define PLATFORM_IWATCH         "iOS (iWatch)"
#   define PLATFORM_TYPE           "iWatch"
#   elif TARGET_OS_TV == 1
/* Apple TV. */
#   define PLATFORM_OS             "Apple iOS"
#   define PLATFORM_ARCH           "x86 (32-Bit)"
#   define PLATFORM_APPLE_TV       "Apple (TV)"
#   define PLATFORM_TYPE           "Apple TV"
#   elif TARGET_OS_IPHONE == 1
/* iOS on iPhone, iPad, etc. */
#   define PLATFORM_OS             "Apple iOS"
#   define PLATFORM_ARCH           "ARM (32-Bit)"
#   define PLATFORM_IOS                     "iOS"
#   define PLATFORM_DEVICE                  "Mobile"
#   define PLATFORM_TYPE           "iPhone, iPad"
#   elif TARGET_OS_MAC == 1
/* macOS */
#   define PLATFORM_OS             "macOS"
#   define PLATFORM_ARCH           __ARCHITECTURE__
#   define PLATFORM_MAC            "Unix(Darwin)-macOS (X11)"
#   define PLATFORM_DEVICE         "Unix(Darwin)-macOS (X11)"
#   define PLATFORM_TYPE           "Macintosh"
#endif
#   elif defined (X64_64bit) && defined(__APPLE__) && defined(__MACH__)
//Detect for x64
/* Apple OSX and iOS (Darwin). ------------------------------ */
#include <TargetConditionals.h>
#   if TARGET_OS_SIMULATOR == 1
/* iOS in Xcode simulator */
#   define PLATFORM_OS             "Apple iOS"
#   define PLATFORM_ARCH           "x86_64"
#   define PLATFORM_IOS_SIMULATOR  "iOS Simulator"
#   define PLATFORM_DEVICE         "Simulator"
#   define PLATFORM_TYPE           "iOS-Emulator"
#   elif TARGET_OS_WATCH == 1
/* iOS on iWatch. */
#   define PLATFORM_OS             "Apple iOS"
#   define PLATFORM_ARCH           "x64 (64-Bit)"
#   define PLATFORM_IWATCH         "x64 (64-Bit)"
#   define PLATFORM_DEVICE         "iOS (iWatch)"
#   define PLATFORM_TYPE           "iWatch"
#   elif TARGET_OS_TV == 1
/* Apple TV. */
#   define PLATFORM_OS             "Apple iOS"
#   define PLATFORM_ARCH           "x64 (64-Bit)"
#   define PLATFORM_APPLE_TV       "Apple (TV)"
#   define PLATFORM_DEVICE         "Apple (TV)"
#   define PLATFORM_TYPE           "Apple TV"
#   elif TARGET_OS_IPHONE == 1
/* iOS on iPhone, iPad, etc. */
#   define PLATFORM_OS             "Apple iOS"
#   define PLATFORM_ARCH           "ARM (64-Bit)"
#   define PLATFORM_IOS            "iOS"
#   define PLATFORM_DEVICE         "Mobile"
#   define PLATFORM_TYPE           "iPhone, iPad"
#   elif TARGET_OS_MAC == 1
/* macOS */
#   define PLATFORM_OS             "macOS"
#   define PLATFORM_ARCH           "x64 (64-Bit)"
#   define PLATFORM_DEVICE         "Desktop"
#   define PLATFORM_MAC            "Unix-macOS (X11)"
#   define PLATFORM_TYPE           "Macintosh"
#endif
#endif
#   if defined(_APPLE) && defined(_LINUX) ||  defined(__APPLE__) && defined(__LINUX__)
#  error Conflicting operating system option selected, choose one.
#endif

/*
     * Solaris
     * Developer:	Oracle and open source
     * Distributions:	Oracle Solaris, Open Indiana
     * Processors:	x86, x86-64, SPARC
     */

#if defined (X86_32bit) && defined(__sun) && defined(__SVR4)
/* Solaris. ------------------------------------------------- */
#   define PLATFORM_OS             "Solaris"
#   define PLATFORM_ARCH           "x86 (32-Bit)"
#   define PLATFORM_SOLARIS        "Solaris"
#   define PLATFORM_TYPE           "SUN (Solaris)"
#   elif defined (X64_64bit) && defined(__sun) && defined(__SVR4)
/* Solaris. ------------------------------------------------- */
#   define PLATFORM_OS             "Solaris"
#   define PLATFORM_ARCH           "x64 (64-Bit)"
#   define PLATFORM_SOLARIS        "Solaris"
#   define PLATFORM_TYPE           "SUN (Solaris)"
#endif


/*
     * Android
     * Developer:	Google
     * Distributions:	Android
     * Processors:	x86, x86-64, ARM
     */

#if defined (X86_32bit) && defined(__linux) && defined(__linux__) && defined(linux) && defined(__ANDROID__) || defined(ANDROID)
/* Android. ------------------------------------------------- */
#   define PLATFORM_OS          "Linux"
#   define PLATFORM_ANDROID     "Linux (Android)"
#   define PLATFORM_DEVICE      "Mobile"
#   define PLATFORM_ARCH        "x86 (32-Bit)"
#   define PLATFORM_TYPE        "Android"
#   elif defined (X64_64bit) && defined(__linux) && defined(__linux__) && defined(linux) && defined(__ANDROID__) || defined(ANDROID)
/* Android. ------------------------------------------------- */
#   define PLATFORM_OS          "Linux"
#   define PLATFORM_ANDROID     "Linux (Android)"
#   define PLATFORM_DEVICE      "Mobile"
#   define PLATFORM_ARCH        "x64 (64-Bit)"
#   define PLATFORM_TYPE        "Android"
#endif


/*
     * Windows with Cygwin (POSIX)
     * Developer:	Open source
     * Distributions:	Cygwin
     * Processors:	x86
     */

#if defined (X86_32bit) && defined(__CYGWIN__) && !defined(_WIN32)
/* Cygwin POSIX under Microsoft Windows. -------------------- */
#   define PLATFORM_OS                 "Microsoft Windows"
#   define PLATFORM_ARCH               "x86 (32-Bit)"
#   define PLATFORM_POSIX_WINDOWS      "POSIX under Microsoft Windows"
#   define PLATFORM_TYPE               "POSIX under Microsoft Windows"
#   elif defined (X64_64bit) && defined(__CYGWIN__) && !defined(_WIN32)
/* Cygwin POSIX under Microsoft Windows. -------------------- */
#   define PLATFORM_OS                 "Microsoft Windows"
#   define PLATFORM_ARCH               "x64 (64-Bit)"
#   define PLATFORM_POSIX_WINDOWS      "POSIX under Microsoft Windows"
#   define PLATFORM_TYPE               "POSIX under Microsoft Windows"
#endif

/* FreeBSD */
#if defined (X86_32bit) && defined(__FreeBSD__) || defined(__FreeBSD)
#   define CELL_P_FREEBSD
#   define PLATFORM_OS          "FreeBSD"
#   define PLATFORM_ARCH        "x86 (32-Bit)"
#   define PLATFORM_FREEBSD     "Linux (FreeBSD)"
#   define PLATFORM_TYPE        "FreeBSD"
#   elif defined (X64_64bit) && defined(__FreeBSD__) || defined(__FreeBSD)
#   define CELL_P_FREEBSD
#   define PLATFORM_OS          "FreeBSD"
#   define PLATFORM_ARCH        "x64 (64-Bit)"
#   define PLATFORM_FREEBSD     "Linux (FreeBSD)"
#endif

/*
     * FreeBSD, ORBIS
     * Developer:	Sony
     * Distributions:	Orbis OS based on FreeBSD
     * Processors:	x86, x86-64
     */

/* Orbis (PS4) variant */
#if defined (X86_32bit) && defined(CELL_P_FREEBSD) && defined(__ORBIS__)
#   define PLATFORM_OS        "Orbis"
#   define PLATFORM_ARCH      "x86 (32-Bit)"
#   define PLATFORM_ORBIS     "Linux (Orbis)"
#   define PLATFORM_PLAYSTATION     "Playstation"
#   define PLATFORM_TYPE      "Playstation"
#   elif defined (X64_64bit) && defined(CELL_P_FREEBSD) && defined(__ORBIS__)
#   define PLATFORM_OS        "Orbis"
#   define PLATFORM_ARCH      "x64 (64-Bit)"
#   define PLATFORM_ORBIS     "Linux (Orbis)"
#   define PLATFORM_TYPE      "Playstation"
#endif

/* OpenBSD */
#if defined (X86_32bit) && defined(__OpenBSD__) || defined(__OpenBSD)
#   define PLATFORM_OS        "Unix-like (BSD)"
#   define PLATFORM_ARCH      "x86 (32-Bit)"
#   define PLATFORM_OPENBSD   "OpenBSD"
#   define PLATFORM_TYPE      "OpenBSD"
#   elif defined (X64_64bit) && defined(__OpenBSD__) || defined(__OpenBSD)
#   define PLATFORM_OS        "Unix-like (BSD)"
#   define PLATFORM_ARCH      "x64 (64-Bit)"
#   define PLATFORM_OPENBSD   "OpenBSD"
#   define PLATFORM_TYPE      "OpenBSD"
#endif


#if defined (_XBOX_ONE) && defined(_TITLE)
#   define PLATFORM_OS        "Windows 10.x"
#   define PLATFORM_ARCH      "AMD64 (x86-64)"
#   define PLATFORM_XBOX  "Windows 10 (Xbox)"
#   define PLATFORM_TYPE      "Xbox"
#endif


/* NetBSD */
#if defined (X86_32bit) && defined(__NetBSD__) || defined(__NetBSD)
#   define PLATFORM_OS             "Unix (NetBSD)"
#   define PLATFORM_ARCH           "x86 (32-Bit)"
#   define PLATFORM_BLACKBERRY     "NetBSD"
#   define PLATFORM_TYPE           "NetBSD"
#   elif defined (X64_64bit) && defined(__NetBSD__) || defined(__NetBSD)
#   define PLATFORM_OS             "Unix (NetBSD)"
#   define PLATFORM_ARCH           "x64 (64-Bit)"
#   define PLATFORM_BLACKBERRY     "NetBSD"
#   define PLATFORM_TYPE           "NetBSD"
#endif


/* QNX (Blackberry) variant */
#if defined (X86_32bit) && defined(__QNXNTO__) || defined (__QNX__)
#   define PLATFORM_OS             "Unix (RTOS)"
#   define PLATFORM_ARCH           "x86 (32-Bit)"
#   define PLATFORM_BLACKBERRY     "QNX"
#   define PLATFORM_TYPE           "Blackberry"
#   elif defined (X64_64bit) && defined(__QNXNTO__) || defined (__QNX__)
#   define PLATFORM_OS             "Unix (RTOS)"
#   define PLATFORM_ARCH           "x64 (64-Bit)"
#   define PLATFORM_BLACKBERRY     "QNX"
#   define PLATFORM_TYPE           "Blackberry"
#endif


/* VMS */
#if defined (X86_32bit) && defined(VMS) || defined (__VMS)
#   define PLATFORM_OS      "OpenVMS"
#   define PLATFORM_ARCH    "x86 (32-Bit)"
#   define PLATFORM_VMS     "DEC (OpenVMS)"
#   define PLATFORM_TYPE    "DEC"
#   elif defined (X64_64bit) && defined(VMS) || defined (__VMS)
#   define PLATFORM_OS      "OpenVMS"
#   define PLATFORM_ARCH    "x64 (64-Bit)"
#   define PLATFORM_VMS     "DEC (OpenVMS)"
#   define PLATFORM_TYPE    "DEC"
#endif

/* VXWORKS variant */
#if defined (X86_32bit) && defined(VXWORKS)
#   define PLATFORM_OS          "RTOS"
#   define PLATFORM_ARCH        "x86 (32-Bit)"
#   define PLATFORM_VXWORKS     "Monolithic"
#   define PLATFORM_TYPE        "VXWORKS"
#   elif defined (X64_64bit) && defined(VXWORKS)
#   define PLATFORM_OS          "RTOS"
#   define PLATFORM_ARCH        "x64 (64-Bit)"
#   define PLATFORM_VXWORKS     "Monolithic"
#   define PLATFORM_TYPE        "VXWORKS"
#endif

/* Motorola 68K.  Not defined by VBCC, so user must define one of these
     * manually when using VBCC.
     */
#if defined (X86_32bit) && defined(__m68k__) || defined(M68000) || defined(__MC68K__)
#   define PLATFORM_OS          "68K"
#   define PLATFORM_ARCH        "x86 (32-Bit)"
#   define PLATFORM_MOTOROLA    "Motorola (68K)"
#   define PLATFORM_TYPE        "Motorola 68K"
#   elif defined (X64_64bit) && defined(__m68k__) || defined(M68000) || defined(__MC68K__)
#   define PLATFORM_OS          "68K"
#   define PLATFORM_ARCH        "x64 (64-Bit)"
#   define PLATFORM_MOTOROLA    "Motorola (68K)"
#   define PLATFORM_TYPE        "Motorola 68K"
#endif

/* Ultrix */
#if defined (X86_32bit) && defined(ultrix) || defined (__ultrix) || defined (__ultrix__)
#   define PLATFORM_OS        "Ultrix Os"
#   define PLATFORM_ARCH       "x86 (32-Bit)"
#   define PLATFORM_ULTRIX    "Ultrix"
#   define PLATFORM_TYPE      "Ultrix"
#   elif defined (X86_32bit) && defined(unix) && defined (vax)
#   define PLATFORM_OS        "Ultrix Os"
#   define PLATFORM_ARCH      "x86 (32-Bit)"
#   define PLATFORM_ULTRIX    "Ultrix"
#   define PLATFORM_TYPE      "Ultrix"
#   elif defined (X64_64bit) && defined(ultrix) || defined (__ultrix) || defined (__ultrix__)
#   define PLATFORM_OS        "Ultrix Os"
#   define PLATFORM_ARCH       "x64 (64-Bit)"
#   define PLATFORM_ULTRIX    "Ultrix"
#   define PLATFORM_TYPE      "Ultrix"
#   elif defined (X64_64bit) && defined(unix) && defined (vax)
#   define PLATFORM_OS        "Ultrix Os"
#   define PLATFORM_ARCH      "x64 (64-Bit)"
#   define PLATFORM_ULTRIX    "Ultrix"
#   define PLATFORM_TYPE      "Ultrix"
#endif

/* Embedded */
#if defined (IS_EMBEDDED)
#   define PLATFORM_EMBEDDED    "Embedded"
#   define PLATFORM_RPI    "Embedded"
#endif



/* Microsoft DOS */
#if defined(MSDOS) || defined (__MSDOS__) || defined (_MSDOS) || defined (__DOS__)
#   define PLATFORM_OS      "Dos"
#   define PLATFORM_DOS     "Microsoft-DOS"
#   define PLATFORM_ARCH    "16-Bit"
#   define PLATFORM_TYPE    "MS-Dos"
#endif

/*
     * Windows, Cygwin (non-POSIX), and MinGW
     * Developer:	Microsoft
     * Distributions:	Windows XP, Vista, 7, 8
     * Processors:	x86, x86-64
     */


#if defined(_WIN32) || defined(_WIN32_WINNT ) && !defined(_WIN64) && !defined (WINAPI_FAMILY_PHONE_APP) && !defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
/* Microsoft Windows (32-bit). ------------------------------ */
#   define PLATFORM_OS              "Windows"
#   define PLATFORM_ARCH            "x86 (32-Bit)"
#   define PLATFORM_WINDOWS_X86     "Microsoft Windows (32-Bit)"
#   define PLATFORM_WINDOWS         "Microsoft Windows (32-Bit)"
#   define PLATFORM_DEVICE          "Desktop"
#   define PLATFORM_TYPE            "PC (Windows)"
#elif defined(_WIN64) && !defined(_WIN32) && !defined(_WIN32_WINNT ) && !defined (WINAPI_FAMILY_PHONE_APP) && (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
/* Microsoft Windows (64-bit). ------------------------------ */
#   define PLATFORM_OS              "Windows "
#   define PLATFORM_ARCH            "x64 (64-Bit)"
#   define PLATFORM_WINDOWS_X64     "Microsoft Windows"
#   define PLATFORM_DEVICE          "Desktop"
#   define PLATFORM_WINDOWS         "Microsoft Windows"
#   define PLATFORM_TYPE            "PC (Windows)"
/* Microsoft Phone ------------------------------ */
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
/* Microsoft Windows Store or Universal Windows Platform - (32-bit). ------------------------------ */
#   define PLATFORM_OS              "Windows"
#   define PLATFORM_ARCH            "x86 (32-Bit)"
#   define PLATFORM_WINDOWS_X86     "Microsoft Windows (32-Bit)"
#   define PLATFORM_WINDOWS_UWP     "Microsoft Windows UWP (32-Bit)"
#   define PLATFORM_DEVICE          "Desktop"
#   define PLATFORM_TYPE            "PC (Windows)"
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP) && defined(_WIN64) && !defined(_WIN32) && !defined(_WIN32_WINNT )
/* Microsoft Windows (64-bit). ------------------------------ */
#   define PLATFORM_OS              "Windows "
#   define PLATFORM_ARCH            "x64 (64-Bit)"
#   define PLATFORM_WINDOWS_X64     "Microsoft Windows x64"
#   define PLATFORM_WINDOWS_UWP     "Microsoft Windows UWP"
#   define PLATFORM_DEVICE          "Desktop"
#   define PLATFORM_WINDOWS         "Microsoft Windows"
#   define PLATFORM_TYPE            "PC (Windows)"
/* Microsoft Phone ------------------------------ */
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
/* Microsoft Windows (Phone). ------------------------------ */
#   define PLATFORM_OS              "WindowsRT"
#   define PLATFORM_ARCH            "x86 (32-Bit)"
#   define PLATFORM_WINDOWS_PHONE   "Windows Phone"
#   define PLATFORM_DEVICE           "Mobile"
#   define PLATFORM_TYPE            "Mobile (Windows Phone)"
#   elif defined(_WIN64) && defined(WINAPI_FAMILY_PHONE_APP)
/* Microsoft Windows (Phone). ------------------------------ */
#   define PLATFORM_OS              "WindowsRT"
#   define PLATFORM_ARCH            "x64 (64-Bit)"
#   define PLATFORM_DEVICE           "Mobile"
#   define PLATFORM_WINDOWS_PHONE   "Windows Phone"
#   define PLATFORM_TYPE            "Mobile (Windows Phone)"
#endif

//!Language Standard Macro
#if __cplusplus == 199711L
  #define CXX_STANDARD_98 199711L
  #elif __cplusplus == 201103L || __cplusplus == 201100
  #define CXX_STANDARD_11 201100
  #elif __cplusplus == 201402L
  #define CXX_STANDARD_14 201402L
  #elif __cplusplus == 201703L || __cplusplus == 201704L
  #define CXX_STANDARD_17 201703L
  #elif __cplusplus == 202002L
  #define CXX_STANDARD_20 202002L
#endif

}

#endif // PREPROCESSORS_HPP
