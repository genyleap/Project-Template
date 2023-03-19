/*!
 *
 * Copyright (c) 2021 Kambiz Asadzadeh
 * Copyright (c) 2023 Genyleap
 */

#ifndef PROJECT_PREFUNCS_HPP
#define PROJECT_PREFUNCS_HPP

#ifdef __has_include
# if __has_include(<utilities/preprocessor.hpp>)
#   include <utilities/preprocessor.hpp>
# endif
#else
#   include <utilities/preprocessor.hpp>
#endif

namespace Prefuncs {

int is_compiler_clang() {
#if defined(COMPILER_CLANG_LLVM)
    return 1;
#else
    return 0;
#endif
}

int is_compiler_mingw() {
#if defined(COMPILER_MINGW)
    return 1;
#else
    return 0;
#endif
}

int is_compiler_mingw64() {
#if defined(COMPILER_MINGW64_32)
    return 1;
#else
    return 0;
#endif
}

int is_compiler_gcc() {
#if defined(COMPILER_GCC)
    return 1;
#else
    return 0;
#endif
}

int is_compiler_hewlett() {
#if defined(COMPILERHEWLETT)
    return 1;
#else
    return 0;
#endif
}

int is_compiler_ibm() {
#if defined(COMPILER_IBM)
    return 1;
#else
    return 0;
#endif
}

int is_compiler_msvc() {
#if defined(COMPILER_MSVC)
    return 1;
#else
    return 0;
#endif
}

int is_compiler_pgcc_pgcpp() {
#if defined(COMPILER_PGCC)
    return 1;
#else
    return 0;
#endif
}

int is_compiler_oracle() {
#if defined(COMPILER_ORACLE)
    return 1;
#else
    return 0;
#endif
}

int is_intel() {
#if defined(INTEL)
    return 1;
#else
    return 0;
#endif
}

int is_arm() {
#if defined(ARM)
    return 1;
#else
    return 0;
#endif
}

int is_amd() {
#if defined(AMD)
    return 1;
#else
    return 0;
#endif
}

int is_alpha() {
#if defined(ALPHA)
    return 1;
#else
    return 0;
#endif
}

int is_risc() {
#if defined(PA_RISC)
    return 1;
#else
    return 0;
#endif
}

int is_epiphany() {
#if defined(EPIPHANY)
    return 1;
#else
    return 0;
#endif
}

int is_motorola() {
#if defined(MOTOROLA)
    return 1;
#else
    return 0;
#endif
}

int is_powerpc() {
#if defined(POWER_PC)
    return 1;
#else
    return 0;
#endif
}

int is_sparc() {
#if defined(SPARC)
    return 1;
#else
    return 0;
#endif
}

int is_embedded() {
#if defined(EMBEDDED)
    return 1;
#else
    return 0;
#endif
}

int is_aix() {
#if defined(AIX)
    return 1;
#else
    return 0;
#endif
}

int is_hpux() {
#if defined(HPUX)
    return 1;
#else
    return 0;
#endif
}

int is_linux() {
#if defined(PLATFORM_LINUX)
    return 1;
#else
    return 0;
#endif
}

int is_android() {
#if defined(PLATFORM_IS_ANDROID)
    return 1;
#else
    return 0;
#endif
}

int is_ios_simulator() {
#if defined(PLATFORM_IS_IOS_EMULATOR)
    return 1;
#else
    return 0;
#endif
}

int is_ios_iwatch() {
#if defined(PLATFORM_IS_IWATCH)
    return 1;
#else
    return 0;
#endif
}

int is_ios_apple_tv() {
#if defined(PLATFORM_IS_IOS_APPLE_TV)
    return 1;
#else
    return 0;
#endif
}

int is_ios() {
#if defined(PLATFORM_IS_IOS)
    return 1;
#else
    return 0;
#endif
}

int is_mac() {
#if defined(PLATFORM_IS_MAC)
    return 1;
#else
    return 0;
#endif
}

int is_windows() {
#if defined(PLATFORM_IS_WINDOWS)
    return 1;
#else
    return 0;
#endif
}

int is_freebsd() {
#if defined(PLATFORM_IS_FREEBSD)
    return 1;
#else
    return 0;
#endif
}

int is_openbsd() {
#if defined(PLATFORM_IS_OPENBSD)
    return 1;
#else
    return 0;
#endif
}

int is_netbsd() {
#if defined(PLATFORM_IS_NETBSD)
    return 1;
#else
    return 0;
#endif
}

int is_playstation() {
#if defined(PLATFORM_IS_PLAYSTATION)
    return 1;
#else
    return 0;
#endif
}

int is_xbox() {
#if defined(PLATFORM_IS_XBOX)
    return 1;
#else
    return 0;
#endif
}

int is_blackberry() {
#if defined(PLATFORM_IS_BLACKBERRY)
    return 1;
#else
    return 0;
#endif
}

int is_openvms() {
#if defined(PLATFORM_IS_OPENVMS)
    return 1;
#else
    return 0;
#endif
}

int is_vxworks() {
#if defined(PLATFORM_IS_VXWORKS)
    return 1;
#else
    return 0;
#endif
}

int is_ultrix() {
#if defined(PLATFORM_IS_ULTRIX)
    return 1;
#else
    return 0;
#endif
}

int is_msdos() {
#if defined(PLATFORM_IS_MSDOS)
    return 1;
#else
    return 0;
#endif
}

int is_pc() {
#if defined(PLATFORM_IS_PC)
    return 1;
#else
    return 0;
#endif
}

int is_windows_phone() {
#if defined(PLATFORM_IS_WINDOWS_PHPNE)
    return 1;
#else
    return 0;
#endif
}

}

#endif // PROJECT_PREFUNCS_HPP
