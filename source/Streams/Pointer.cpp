//
//  Type.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 6/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#include "Pointer.hpp"

namespace Streams
{
	std::ostream & operator<<(std::ostream & output, const Safe<std::nullptr_t> & safe)
	{
		return output << "nullptr";
	}
}
