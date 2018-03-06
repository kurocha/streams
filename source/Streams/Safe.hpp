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
	
	template <typename T>
	std::ostream & operator<<(std::ostream & output, const Safe<T> & safe)
	{
		safe.print(output);
		
		return output;
	}
}

#include "String.hpp"
#include "Boolean.hpp"
#include "Pointer.hpp"
#include "Type.hpp"
