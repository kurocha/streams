//
//  String.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 7/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#include "String.hpp"

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
	
	std::ostream & operator<<(std::ostream & output, const Safe<const char *> & safe)
	{
		return output << Safe<std::string>{safe.value};
	}
}
