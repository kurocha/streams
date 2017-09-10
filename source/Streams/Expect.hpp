//
//  Expect.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include <iostream>

namespace Streams
{
	// std::cin >> x >> expect<','> >> y;
	template <char C>
	std::istream & expect(std::istream & input)
	{
		char c;
		
		if (input >> c && c != C) {
				input.setstate(std::ios_base::failbit);
		}
		
		return input;
	}
}
