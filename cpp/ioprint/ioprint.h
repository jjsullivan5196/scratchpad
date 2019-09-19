#pragma once
#include <utility>
#include <string>
#include <string_view>
#include <ostream>

namespace ioprint {
	template<typename CharT>
	struct format_info;

	template<>
	struct format_info<char> {
		constexpr static auto field = u8"{}";
	};

	template<>
	struct format_info<wchar_t> {
		constexpr static auto field = L"{}";
	};

	template<>
	struct format_info<char16_t> {
		constexpr static auto field = u"{}";
	};

	template<>
	struct format_info<char32_t> {
		constexpr static auto field = U"{}";
	};

	// Print rest of format string
	template<class Stream, typename CharT, class Traits, typename... Args>
	void ioprintf(Stream& ostream, const std::basic_string_view<CharT, Traits> fmt, const Args&&... args) {
		ostream << fmt;
	}

	// Begin formatting
	template<class Stream, typename CharT, class Traits, typename ArgT, typename... Args>
	void ioprintf(Stream& ostream, const std::basic_string_view<CharT, Traits> fmt, const ArgT&& arg, const Args&&... args) {
		auto pos = fmt.find(format_info<CharT>::field);
		ostream << fmt.substr(0, pos);
		ostream << arg;
		ioprintf(ostream, fmt.substr(pos + 2), std::forward<const Args>(args)...);
	}

	// Construct view from basic_string<>
	template<class Stream, typename CharT, class Traits, class Allocator, typename... Args>
	void ioprintf(Stream& ostream, const std::basic_string<CharT, Traits, Allocator>&& fmt, const Args&&... args) {
		auto fmt_view = static_cast<std::basic_string_view<CharT, Traits>>(fmt);
		ioprintf(ostream, fmt_view, std::forward<const Args>(args)...);
	}

	// Construct view from C-Style string
	template<class Stream, typename CharT, typename... Args>
	void ioprintf(Stream& ostream, const CharT* fmt, const Args&&... args) {
		auto fmt_view = std::basic_string_view<CharT, std::char_traits<CharT>>(fmt);
		ioprintf(ostream, fmt_view, std::forward<const Args>(args)...);
	}
}
