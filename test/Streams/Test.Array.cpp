//
//  Test.Container.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 22/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Streams/Array.hpp>

namespace Streams
{
	UnitTest::Suite ArrayTestSuite {
		"Streams::Array",
		
		{"it should read array",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer("{1, 2, 3, 4}");
				std::array<int, 4> values;
				
				buffer >> values;
				
				examiner.expect(values) == std::array<int, 4>{1, 2, 3, 4};
			}
		},
	};
}
