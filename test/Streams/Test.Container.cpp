//
//  Test.Container.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 20/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Streams/Container.hpp>

#include <array>
#include <vector>

namespace Streams
{
	UnitTest::Suite ContainerTestSuite {
		"Streams::Container",
		
		{"it shuold print array",
			[](UnitTest::Examiner & examiner) {
				int values[4] = {1, 2, 3, 4};
				std::stringstream buffer;
				
				buffer << safe(values);
				
				examiner.expect(buffer.str()) == "{1, 2, 3, 4}";
			}
		},
		
		{"it shuold print vector",
			[](UnitTest::Examiner & examiner) {
				std::vector<int> values = {1, 2, 3, 4};
				std::stringstream buffer;
				
				buffer << safe(values);
				
				examiner.expect(buffer.str()) == "{1, 2, 3, 4}";
			}
		},
	};
}
