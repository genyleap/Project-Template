#ifndef PROJECT_TYPES_HPP
#define PROJECT_TYPES_HPP

//!JSON Config
#ifdef USE_NONE_STL_JSON
#include <nlohmann/json.hpp>
using JSon = nlohmann::json;
using JSonException = nlohmann::detail::exception;
#else
#endif

#include "precompiled/pch.hpp" //get some header.

namespace Types {

using MapString = std::pair<std::string, std::string>;
using MapVector = std::pair<std::string, std::vector<std::string>>;
using MapList   = std::pair<std::string, std::map<std::string, std::string>>;

template<typename T1, typename T2>
using Map = std::map<T1, T2>;

template<typename T>
using Vector = std::vector<T>;

template<typename T>
using Optional = std::optional<T>;

template<typename T>
using Variant = std::variant<T>;

template<typename T1, typename T2>
using Pair = std::pair<T1, T2>;

using Function = std::function<void(void)>;
using PackagedTask = std::packaged_task<void(void)>;

using MultiThreadVector = std::vector<std::thread>;

using StringStream   =  std::basic_stringstream<char>;

using schar        = signed char;
using uchar        = unsigned char;
using ushort       = unsigned short;
using uint         = unsigned int;
using ulong        = unsigned long;
using ullong       = unsigned long long;
using llong        = long long;

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using s8  = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

#if __APPLE__
using uptr = std::uint64_t;
#else
using uptr = std::uintptr_t;
#endif


using if_streamer    = std::ifstream;
using string_stream  = std::stringstream;

}

#endif // PROJECT_TYPES_HPP
