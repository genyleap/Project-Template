/*!
 *
 * Copyright (c) 2021 Kambiz Asadzadeh
 * Copyright (c) 2023 Genyleap
 */

#ifndef COMMON_HPP
#define COMMON_HPP

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

template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

#define PROJECT_BRACE_BEGIN {
#define PROJECT_BRACE_END }
#define PROJECT_USING_NAMESPACE using namespace
#define PROJECT_NAMESPACE_BEGIN(x) namespace x {
#define PROJECT_ANONYMOUS_NAMESPACE_BEGIN namespace {
#define PROJECT_NAMESPACE_END }
#define PROJECT_USING using
#define PROJECT_NAMESPACE namespace

/*
 * C++11 keywords and expressions
 */
#ifdef PROJECT_COMPILER_NULLPTR
# define __project_nullptr         nullptr
#else
# define __project_nullptr         NULL
#endif

# define __project_override override
# define __project_final final

# define __project_const const
# define __project_const_noexcept const noexcept
# define __project_const_noexcept_override const noexcept override
# define __project_noexcept noexcept
# define __project_noexcept_expr(x) noexcept(x)
# define __project_constexpr_virtual virtual constexpr
# define __project_constexpr constexpr
# define __project_static_constexpr static constexpr
# define __project_static_constexpr static constexpr
# define __project_inline_static_constexpr inline static constexpr
# define __project_inline_static_const inline static const
# define __project_inline_static inline static

#define __project_pure_const_noexcept const noexcept = 0

#define __project_no_return [[noreturn]]

#define __project_no_discard [[nodiscard]]
#define __project_no_discard_virtual [[nodiscard]] virtual
#define __project_no_discard_message(x) [[nodiscard(x)]]

#define __project_maybe_unused [[maybe_unused]]

#define __project_virtual virtual

//! EXPORTS & EXTRA
#if defined(__WINNT) || defined(__WINNT__) || defined(WIN32) || \
defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) ||    \
    defined(WIN64) || defined(_WIN64) || defined(__WIN64) ||    \
    defined(__WIN64__)
//! Microsoft Windows
#define __project_export __declspec(dllexport)
#define __project_import __declspec(dllimport)
#elif defined(__GNUC__)
//! Define for Unix base OS such as: Linux, macOS, FreeBSD, etc...
#define __project_export __attribute__((visibility("default")))
#define __project_import __attribute__((visibility("default")))
#define __project_hidden __attribute__((visibility("hidden")))
#else
//  do nothing and hope for the best?
#define __project_export
#define __project_import
#pragma warning Unknown dynamic link import / export semantics.
#endif

#define SCOPE :
#define SCOPE_LEFT (
#define SCOPE_RIGHT )
#define SCOPE_ENDS {}

#define __project_extern_c extern "C"

#define __project_export_pointer(Class, object)\
__project_extern_c __project_export Class* object = __project_nullptr;

#define PROJECT_DEFAULT_OCTORS_WITHOUT_IMPL(Class) \
    Class() = default;\
    ~Class() = default;

#define PROJECT_DEFAULT_INTERFACE_OCTORS_WITHOUT_IMPL(Class) \
Class() = default;\
    virtual ~Class() = default;

#define PROJECT_DEFAULT_OCTORS(Class) \
Class();\
    ~Class();

#define PROJECT_DEFAULT_OCTORS_IMPL(Class)\
Class::Class(){}\
    Class::~Class(){}\

#define PROJECT_DEFAULT_INTERFACE_OCTORS(Class) \
Class();\
    virtual ~Class();

#define PROJECT_DEFAULT_INTERFACE_OCTORS_IMPL(Class)\
Class::Class() {}\
    Class::~Class(){}\

/*!
 * \brief This struct represents a non-copyable object.
 */
struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable(NonCopyable const&) = delete;
    NonCopyable& operator=(NonCopyable const&) = delete;
};

/*!
 * \brief This struct represents a non-movable object.
 */
struct NonMovable
{
    NonMovable() = default;
    NonMovable(NonMovable&&) = delete;
    NonMovable& operator=(NonMovable&&) = delete;
};

/*!
 * \brief This struct represents a non-copyable or non-movable object.
 */
struct NonMovableOrCopyable : private NonCopyable, NonMovable
{
    NonMovableOrCopyable() = default;
};

//!Macro version of non-copyable.
#define PROJECT_DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;

//!Macro version of non-movable.

#define PROJECT_DISABLE_MOVE(Class) \
    Class(Class &&) = delete; \
    Class &operator=(Class &&) = delete;

//!Macro version of non-copyable and non-movable.
#define PROJECT_DISABLE_COPY_MOVE(Class) \
    PROJECT_DISABLE_COPY(Class) \
    PROJECT_DISABLE_MOVE(Class)

#endif // COMMON_HPP
