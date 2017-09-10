//
//  Test.Terminal.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Streams/Terminal.hpp>

namespace Streams
{
	UnitTest::Suite TerminalTestSuite {
		"Streams::Terminal",
		
		{"it can detect terminal type",
			[](UnitTest::Examiner & examiner) {
				examiner.check(terminal_type(0) == Terminal::XTERM);
				examiner.check(terminal_type(1) == Terminal::XTERM);
			}
		},
	};
}
