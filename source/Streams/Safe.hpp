//
//  Safe.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 18/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include <iostream>
#include <type_traits>

namespace Streams
{
	template <typename ValueT>
	class Safe
	{
	public:
		Safe(const ValueT & value) : value(value) {}
		
		const ValueT & value;
	};
	
	template <typename ValueT>
	Safe<ValueT> safe(const ValueT & value)
	{
		return {value};
	}
	
	template <typename ValueT>
	std::ostream & operator<<(std::ostream & output, const Safe<ValueT> & safe)
	{
		return output << safe.value;
	}
	
	// Always output pointers as raw values, don't try to print them!
	template <typename ValueT>
	std::ostream & operator<<(std::ostream & output, const Safe<ValueT *> & safe)
	{
		return output << static_cast<const void *>(safe.value);
	}
	
	std::ostream & operator<<(std::ostream & output, const Safe<std::string> & safe);
}
