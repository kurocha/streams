//
//  Terminal.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include "Terminal.hpp"

#include <unistd.h>
#include <iostream>

namespace Streams
{
	const int TTY::INDEX = std::ios_base::xalloc();
	
	Terminal terminal_type(int descriptor)
	{
		if (::isatty(descriptor)) {
			return Terminal::XTERM;
		} else {
			return Terminal::NONE;
		}
	}
	
	int descriptor_for(std::ios & stream)
	{
		if (stream.rdbuf() == std::cin.rdbuf()) {
			return fileno(stdin);
		}
		
		if (stream.rdbuf() == std::cout.rdbuf()) {
			return fileno(stdout);
		}
		
		if (stream.rdbuf() == std::cerr.rdbuf()) {
			return fileno(stderr);
		}
		
		return -1;
	}
	
	Terminal terminal_type(std::ios & stream)
	{
		auto descriptor = descriptor_for(stream);
		
		if (descriptor != -1) {
			return terminal_type(descriptor);
		} else {
			return Terminal::NONE;
		}
	}
}
