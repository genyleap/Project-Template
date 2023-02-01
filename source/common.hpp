#ifndef COMMON_HPP
#define COMMON_HPP

/*!
 * Gen3 License
 *
 * Copyright (c) 2021 Kambiz Asadzadeh
 * Copyright (c) 2023 Genyleap
 */

#ifdef __has_include
# if __has_include(<utilities/preprocessor.hpp>)
#   include <utilities/preprocessor.hpp>
# endif
#else
#   include <utilities/preprocessor.hpp>
#endif

#ifdef __has_include
# if __has_include(<utilities/featuretest.hpp>)
#   include <utilities/featuretest.hpp>
# endif
#else
#   include <utilities/featuretest.hpp>
#endif

#ifdef __has_include
# if __has_include(<utilities/types.hpp>)
#   include <utilities/types.hpp>
# endif
#else
#   include <utilities/types.hpp>
#endif

#ifdef __has_cpp_attribute
#  if __has_cpp_attribute(__cpp_modules)
#   pragma message("Your project is based on modern solution for componentization of C++ libraries and programs.")
#  endif
#else
#   pragma message("Your project is based on classic precompiled-header system. [enable module feature in C++]")
#endif

#if __cplusplus > 201703
#ifdef __has_include
#  if __has_include(<precompiled/pch.hpp>)
#    include <precompiled/pch.hpp>
#  else
#     pragma message("Your project is based on classic precompiled-header system.")
#  endif
#endif
#else
# include "precompiled/pch.hpp"
#endif

#endif // COMMON_HPP
