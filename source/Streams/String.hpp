//
//  String.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 7/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Safe.hpp"

#include <string>

namespace Streams
{
	// TODO: This should eventually be std::string_view.
	std::ostream & operator<<(std::ostream & output, const Safe<std::string> & safe);
	std::ostream & operator<<(std::ostream & output, const Safe<const char *> & safe);
	
	template <std::size_t N>
	std::ostream & operator<<(std::ostream & output, const Safe<char[N]> & safe)
	{
		return output << Safe<std::string>{safe.value};
	}
}
