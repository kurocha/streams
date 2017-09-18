//
//  Test.Safe.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 18/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Streams/Safe.hpp>

namespace Streams
{
	UnitTest::Suite SafeTestSuite {
		"Streams::Safe",
		
		{"it should escape characters",
			[](UnitTest::Examiner & examiner) {
				std::string text;
				
				for (std::size_t i = 0; i < 256; i += 1)
					text += static_cast<char>(i);
				
				std::stringstream buffer;
				buffer << safe(text);
				
				for (auto & c : buffer.str())
					examiner.expect(c) >= 32;
			}
		},
		
		{"it should print pointers",
			[](UnitTest::Examiner & examiner) {
				const char * text = "Hello World!";
				
				std::stringstream buffer;
				buffer << safe(text);
				
				examiner.expect(buffer.str()) != text;
			}
		},
		
		{"it should print nullptr",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				buffer << safe(nullptr);
				
				examiner.expect(buffer.str()) == "nullptr";
			}
		},
		
		{"it should print type info",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				buffer << safe(typeid(int));
				
				examiner.expect(buffer.str()) == "type_info(int)";
			}
		}
	};
}
