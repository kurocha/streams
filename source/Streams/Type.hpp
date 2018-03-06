//
//  Type.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 6/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Safe.hpp"

#include <typeinfo>

namespace Streams
{
	std::ostream & operator<<(std::ostream & output, const std::type_info & type_info);
	std::ostream & operator<<(std::ostream & output, const Safe<std::type_info> & safe);
}
