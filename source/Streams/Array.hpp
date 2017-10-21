//
//  Array.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 22/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Expect.hpp"

#include <array>

namespace Streams
{
	/// Read an array from a std::istream
	template <typename T, std::size_t N>
	std::istream & operator>> (std::istream & input, std::array<T, N> & array)
	{
		input >> expect<'{'>;
		
		for (std::size_t i = 0; i < N; ++i) {
			if (i != 0) input >> expect<','>;
			input >> array[i];
		}
		
		input >> expect<'}'>;
		
		return input;
	}
}
