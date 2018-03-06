//
//  Boolean.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 7/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Safe.hpp"

namespace Streams
{
	std::ostream & operator<<(std::ostream & output, const Safe<bool> & safe);
}
