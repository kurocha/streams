//
//  Color.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include "Color.hpp"

#include "Terminal.hpp"

#include <iostream>

namespace Streams
{
	std::ostream & operator<<(std::ostream & output, const Color & color)
	{
		TTY tty(output);
		
		if (!tty) return output;
		
		output << "\033[";
		bool first = true;
		
		if (color.attributes != Color::UNSPECIFIED) {
			output << color.attributes;
			
			first = false;
		}
		
		if (color.foreground != Color::UNSPECIFIED) {
			if (first)
				first = false;
			else
				output << ';';
			
			output << 30 + color.foreground;
		}
		
		if (color.background != Color::UNSPECIFIED) {
			if (first)
				first = false;
			else
				output << ';';
			
			output << 40 + color.background;
		}
		
		output << 'm';
		
		return output;
	}
}
