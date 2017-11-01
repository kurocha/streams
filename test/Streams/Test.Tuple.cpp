//
//  Test.Tuple.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 20/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Streams/Tuple.hpp>

namespace Streams
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite TupleTestSuite {
		"Streams::Tuple",
		
		{"it should print tuple",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				auto tuple = std::make_tuple(5, "cats");
				
				buffer << safe(tuple);
				
				examiner.expect(buffer.str()).to(be == "(5, \"cats\")");
			}
		},
	};
}
