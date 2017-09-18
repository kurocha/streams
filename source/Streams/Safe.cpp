//
//  Safe.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 18/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include "Safe.hpp"

#include <iomanip>

namespace Streams
{
	using UC = typename std::make_unsigned<char>::type;
	
	std::ostream & operator<<(std::ostream & output, const Safe<std::string> & safe)
	{
		auto i = safe.value.begin(), end = safe.value.end();
		
		output << '"';
		
		std::ios::fmtflags initial_flags{output.flags()};
		output << std::hex << std::uppercase << std::setw(2) << std::setfill('0');
		
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
}
