//
//  Type.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 6/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#include "Type.hpp"

#include <cxxabi.h>

namespace Streams
{
	std::ostream & operator<<(std::ostream & output, const std::type_info & type_info)
	{
		int status = 0; // some arbitrary value to eliminate the compiler warning
		const auto & name = type_info.name();

		std::unique_ptr<char, void(*)(void*)> result{
			abi::__cxa_demangle(name, NULL, NULL, &status),
			std::free
		};

		if (status == 0) {
			output << result.get();
		} else {
			output << name;
		}

		return output;
	}
	
	std::ostream & operator<<(std::ostream & output, const Safe<std::type_info> & safe)
	{
		return output << "type_info(" << safe.value << ")";
	}
}
