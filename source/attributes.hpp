/*!
 *
 * Copyright (c) 2021 Kambiz Asadzadeh
 * Copyright (c) 2023 Genyleap
 */

#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

//!Attributes in Clang
#if defined(__clang__)

/// The lifetimebound attribute indicates that a resource owned by a function parameter or implicit object
/// parameter is retained by the return value of the annotated function (or, for a parameter of a constructor, in the value of the constructed object).
/// It is only supported in C++.
#if __has_attribute(lifetimebound)
#define LIFETIMEBOUND [[clang::lifetimebound]]
#else
#define LIFETIMEBOUND
#endif


/// The reinitializes attribute can be applied to a non-static, non-const C++ member function to indicate
/// that this member function reinitializes the entire object to a known state, independent of the previous state of the object.
#if __has_attribute(reinitializes)
#define REINITIALIZES [[clang::reinitializes]]
#else
#define REINITIALIZES
#endif

/// The disable_tail_calls attribute instructs the backend to not perform tail call optimization inside the marked function.
#if __has_attribute(disable_tail_calls)
#define DISABLE_TAIL_CALLS [[clang::disable_tail_calls]]
#else
#define DISABLE_TAIL_CALLS
#endif

/// This attribute specifies that the variable to which it is attached is intended to have a constant initializer
/// according to the rules of [basic.start.static]. The variable is required to have static or thread storage duration.
/// If the initialization of the variable is not a constant initializer an error will be produced. This attribute may only be used in C++.
#if __has_attribute(require_constant_initialization)
#define REQUIRE_CONSTANT_INITIALIZATION [[clang::require_constant_initialization]]
#else
#define REQUIRE_CONSTANT_INITIALIZATION
#endif

#endif

//!Attributes in GCC
#if defined(__GNUC__)

#endif

//!Attributes in MSVC
#if defined(_MSC_VER)

#endif

#endif // ATTRIBUTES_HPP
