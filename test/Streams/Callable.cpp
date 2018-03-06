//
//  Callable.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 7/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Streams/Callable.hpp>

namespace Streams
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite CallableTestSuite {
		"Streams::Callable",
		
		{"it should print lambda",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				buffer << safe([&]{});
				
				examiner.expect(buffer.str()).to(include("lambda"));
			}
		},
	};
}
