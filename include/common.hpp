#ifndef COMMON_HPP
#define COMMON_HPP

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
 * C++20 introduces modules, a modern solution for componentization of C++ libraries and programs.
 * A module is a set of source code files that are compiled independently of the translation units that import them.
 * Modules eliminate or greatly reduce many of the problems associated with the use of header files, and also potentially reduce compilation times.
 * Macros, preprocessor directives, and non-exported names declared in a module are not visible and therefore have no effect on the compilation of the translation unit that imports the module.
 * You can import modules in any order without concern for macro redefinitions. Declarations in the importing translation unit do not participate in overload resolution or name lookup in the imported module.
 * After a module is compiled once, the results are stored in a binary file that describes all the exported types, functions and templates. That file can be processed much faster than a header file, and can be reused by the compiler every place where the module is imported in a project.
 *
!*/

#include "utilities/preprocessor.hpp"
#include "utilities/featuretest.hpp"
#include "utilities/types.hpp"

#ifdef USE_LATEST_STANDARD
////TODO use module...
#else
///!
#endif

#ifdef __has_cpp_attribute
#  if __has_cpp_attribute(__cpp_modules)
#   pragma message("Your project is based on modern solution for componentization of C++ libraries and programs.")
#  endif
#else
#   pragma message("Your project is based on classic precompiled-header system. [enable module technique in C++]")
#endif

#if __cplusplus > 201703
#include <version>
#ifdef __has_include
#  if __has_include("precompiled/pch.hpp")
#    include "precompiled/pch.hpp"
#  else
#     pragma message("Your project is based on classic precompiled-header system.")
#  endif
#endif
#else
# include "precompiled/pch.hpp"
#endif

#endif // COMMON_HPP
