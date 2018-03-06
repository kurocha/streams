//
//  Pointer.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 6/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Safe.hpp"

namespace Streams
{
	std::ostream & operator<<(std::ostream & output, const Safe<std::nullptr_t> & safe);

	// Always output pointers as raw values, don't try to print them!
	template <typename ValueT>
	std::ostream & operator<<(std::ostream & output, const Safe<ValueT *> & safe)
	{
		return output << static_cast<const void *>(safe.value);
	}
}
