//
//  Test.Color.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Streams/Color.hpp>
#include <Streams/Terminal.hpp>

#include <sstream>

namespace Streams
{
	UnitTest::Suite ColorTestSuite {
		"Streams::Color",
		
		{"it outputs color",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				TTY tty(buffer, Terminal::XTERM);
				
				Color color(Color::RED);
				
				buffer << color << "Hello World!";
				
				examiner.expect(buffer.str()) == "\033[31mHello World!";
			}
		},
		
		{"it doesn't outputs color",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				
				Color color(Color::RED);
				
				buffer << color << "Hello World!";
				
				examiner.expect(buffer.str()) == "Hello World!";
			}
		},
	};
}
