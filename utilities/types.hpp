/*!
 *
 * Copyright (c) 2021 Kambiz Asadzadeh
 * Copyright (c) 2023 Genyleap
 */

#ifndef PROJECT_TYPES_HPP
#define PROJECT_TYPES_HPP

#ifdef __has_include
# if __has_include(<precompiled/pch.hpp>)
#   include <precompiled/pch.hpp>
# endif
#else
#   include <precompiled/pch.hpp>
#endif

namespace Types {

using schar        = signed char;
using uchar        = unsigned char;
using ushort       = unsigned short;
using uint         = unsigned int;
using ulong        = unsigned long;
using ullong       = unsigned long long;
using llong        = long long;

//! Fixed width integer types (since C++11)
//! Signed integer type
using s8  = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

//! Fastest signed integer type with width of at least 8, 16, 32 and 64 bits respectively.
using fs8  = std::int_fast8_t;
using fs16 = std::int_fast16_t;
using fs32 = std::int_fast32_t;
using fs64 = std::int_fast64_t;

//! Smallest signed integer type with width of at least 8, 16, 32 and 64 bits respectively.
using ss8  = std::int_least8_t;
using ss16 = std::int_least16_t;
using ss32 = std::int_least32_t;
using ss64 = std::int_least64_t;

using smax = std::intmax_t; //! Maximum-width signed integer type.
using sptr = std::intptr_t; //! Signed integer type capable of holding a pointer to void.

//! Unsigned integer type with width of exactly 8, 16, 32 and 64 bits respectively.
using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

//! Fastest unsigned integer type with width of at least 8, 16, 32 and 64 bits respectively.
using fu8  = std::uint_fast8_t;
using fu16 = std::uint_fast16_t;
using fu32 = std::uint_fast32_t;
using fu64 = std::uint_fast64_t;

//! Smallest unsigned integer type with width of at least 8, 16, 32 and 64 bits respectively.
using su8  = std::uint_least8_t;
using su16 = std::uint_least16_t;
using su32 = std::uint_least32_t;
using su64 = std::uint_least64_t;

using f32  = float;
using f64  = double;

using b8   = bool;

using umax = std::uintmax_t; //! Maximum-width unsigned integer type
using uptr = std::uintptr_t; //! Unsigned integer type capable of holding a pointer to void.

using VariantTypes      = std::map<std::string, std::variant<std::string, std::string_view, int, double, bool>>;
using MapList           = std::pair<std::string, std::map<std::string, std::string>>;
using MapVector         = std::pair<std::string, std::vector<std::string>>;
using IteratorConfig    = std::map<std::string, std::string>::iterator;
using LanguageType      = std::map<std::string, std::string>;
using MetaList          = std::map<std::string, std::string>;
using ResourceType      = std::map<std::string, std::string>;
using MapConfig         = std::map<std::string, std::string>;
using MapString         = std::map<std::string, std::string>;
using PairString        = std::pair<std::string, std::string>;
using SettingType       = std::map<int, std::string>;
using VectorString      = std::vector<std::string>;
using VectorSection     = std::vector<std::string>;
using OptionalString    = std::optional<std::string>;

using OptionalNumeric   = std::optional<int>;
using OptionalBool      = std::optional<bool>;

#if defined(USE_JSON) && !defined(USE_BOOST)
namespace JSon      = Json;
#   elif defined(USE_BOOST)
namespace JSon      = boost::json;
#   elif !defined(USE_JSON) && !defined(USE_BOOST)
#if __cpp_lib_json
namespace JSon      = std::json;
#endif
#endif

using TableNames        = std::vector<std::string>;
using QueryType         = std::vector<std::string>;
using TranslateType     = std::string;

template<typename T1, typename T2> using Map      = std::map<T1, T2>;
template<typename T1, typename T2> using MultiMap = std::multimap<T1, T2>;
template<typename T1, typename T2> using Pair     = std::pair<T1, T2>;

template<typename T> using Vector        = std::vector<T>;
template<typename T> using Optional      = std::optional<T>;
template<typename T> using Variant       = std::variant<T>;


using Function          = std::function<void(void)>;
using PackagedTask      = std::packaged_task<void(void)>;
using MultiThreadVector = std::vector<std::thread>;
using StringStream      = std::basic_stringstream<char>;
using String            = std::string;
using IfStreamer        = std::ifstream;
using StringStream      = std::stringstream;

}

#endif // PROJECT_TYPES_HPP
