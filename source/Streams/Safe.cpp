//
//  Safe.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 18/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include "Safe.hpp"

#include <iomanip>
#include <cxxabi.h>

namespace Streams
{
	using UC = typename std::make_unsigned<char>::type;
	
	std::ostream & operator<<(std::ostream & output, const Safe<std::string> & safe)
	{
		auto i = safe.value.begin(), end = safe.value.end();
		
		output << '"';
		
		std::ios::fmtflags initial_flags{output.flags()};
		output << std::hex << std::uppercase;
		
		for (; i != end; ++i) {
			if (*i == '\0') output << "\\0"; else
			if (*i == '"') output << "\\\""; else
			if (*i == '\\') output << "\\\\"; else
			if (*i == '\a') output << "\\a"; else
			if (*i == '\b') output << "\\b"; else
			if (*i == '\f') output << "\\f"; else
			if (*i == '\n') output << "\\n"; else
			if (*i == '\r') output << "\\r"; else
			if (*i == '\t') output << "\\t"; else
			if (*i == '\v') output << "\\v"; else
			if (*i < 32 || static_cast<UC>(*i) > 128) output << "\\x" << +static_cast<UC>(*i);
			else output << *i;
		}
		
		output << '"';
		output.flags(initial_flags);
		
		return output;
	}
	
	std::ostream & operator<<(std::ostream & output, const Safe<std::nullptr_t> & safe)
	{
		return output << "nullptr";
	}

	std::string demangle(const char* name)
	{
		int status = 0; // some arbitrary value to eliminate the compiler warning

		std::unique_ptr<char, void(*)(void*)> result{
			abi::__cxa_demangle(name, NULL, NULL, &status),
			std::free
		};

		return (status == 0) ? result.get() : name;
	}

	std::ostream & operator<<(std::ostream & output, const Safe<std::type_info> & safe)
	{
		return output << "type_info(" << demangle(safe.value.name()) << ")";
	}
	
	std::ostream & operator<<(std::ostream & output, const Safe<const char *> & safe)
	{
		return output << Safe<std::string>{safe.value};
	}
}
