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
	// Provides a way to output data which isn't guaranteed to contain only printable characters. It also includes additional helpers for outputting data-structures in a nested fashion.
	template <typename ValueT, typename = void>
	struct Safe
	{
		const ValueT & value;
		
		void print(std::ostream & stream) const
		{
			stream << value;
		}
	};
	
	template <typename ValueT>
	Safe<ValueT> safe(const ValueT & value)
	{
		return {value};
	}
	
	std::ostream & operator<<(std::ostream & output, const Safe<std::nullptr_t> & safe);
	std::ostream & operator<<(std::ostream & output, const Safe<std::type_info> & safe);
	
	// Always output pointers as raw values, don't try to print them!
	template <typename ValueT>
	std::ostream & operator<<(std::ostream & output, const Safe<ValueT *> & safe)
	{
		return output << static_cast<const void *>(safe.value);
	}
	
	// TODO: This should eventually be std::string_view.
	std::ostream & operator<<(std::ostream & output, const Safe<std::string> & safe);
	std::ostream & operator<<(std::ostream & output, const Safe<const char *> & safe);
	
	template <std::size_t N>
	std::ostream & operator<<(std::ostream & output, const Safe<char[N]> & safe)
	{
		return output << Safe<std::string>{safe.value};
	}
	
	template <typename T>
	std::ostream & operator<<(std::ostream & output, const Safe<T> & safe)
	{
		safe.print(output);
		
		return output;
	}
}
