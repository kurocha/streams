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
			UNDERLINE = 4,
			BLINK = 5,
			REVERSE = 7,
			HIDDEN = 8,
		};
		
		enum Colors {
			BLACK = 0,
			RED = 1,
			GREEN = 2,
			YELLOW = 3,
			BLUE = 4,
			MAGENTA = 5,
			CYAN = 6,
			WHITE = 7,
			DEFAULT = 9,
		};
		
		static const int UNSPECIFIED = -1;
		
		// Specific color style:
		Color(int foreground, int background = UNSPECIFIED, int attributes = UNSPECIFIED) : foreground(foreground), background(background), attributes(attributes) {}
		
		// Reset style back to default.
		Color() : foreground(UNSPECIFIED), background(UNSPECIFIED), attributes(NORMAL) {}
		
		int foreground, background, attributes;
	};
	
	std::ostream & operator<<(std::ostream & output, const Color & color);
}
