//
//  Color.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include <iosfwd>

namespace Streams
{
	struct Color {
		enum Attributes {
			NORMAL = 0,
			BOLD = 1,
			FAINT = 2,
			ITALIC = 3,
			UNDERLINE = 4
		};
		
		enum Colors {
			BLACK = 0,
			RED = 1,
			GREEN = 2,
			YELLOW = 3,
			BLUE = 4,
			MAGENTA = 5,
			CYAN = 6,
			WHITE = 7
		};
		
		static const int UNSPECIFIED = -1;
	
		Color(int foreground = UNSPECIFIED, int background = UNSPECIFIED, int attributes = UNSPECIFIED) : foreground(foreground), background(background), attributes(attributes) {}
		
		int foreground, background, attributes;
	};
	
	std::ostream & operator<<(std::ostream & output, const Color & color);
}
