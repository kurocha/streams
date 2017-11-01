//
//  Test.Expect.cpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Streams/Expect.hpp>

#include <sstream>

namespace Streams
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite ExpectTestSuite {
		"Streams::Expect",
		
		{"it can parse packed numbers",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer("1,2");
				int x = 0, y = 0;
				
				buffer >> x >> expect<','> >> y;
				
				examiner.expect(buffer.eof()).to(be_true);
				examiner.expect(buffer.fail()).to(be_false);
				examiner.expect(x).to(be == 1);
				examiner.expect(y).to(be == 2);
			}
		},
		
		{"it ignores whitespace",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer(" 1 , 2 ");
				int x = 0, y = 0;
				
				buffer >> x >> expect<','> >> y;
				
				examiner.expect(buffer.fail()).to(be_false);
				examiner.expect(x).to(be == 1);
				examiner.expect(y).to(be == 2);
			}
		},
	};
}
