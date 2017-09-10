# Streams

Provides enhanced stream manipulation, including basic support for parsing incoming character data, and TTY color formatting.

[![Build Status](https://travis-ci.org/kurocha/streams.svg?branch=master)](https://travis-ci.org/kurocha/streams)

## Setup

The build tool [teapot] needs to be installed (which requires [Ruby]):

	$ gem install teapot

[teapot]: https://teapot.nz/
[Ruby]: https://www.ruby-lang.org/en/downloads/

### Dependencies

Fetch all the necessary project dependencies:

	$ cd streams
	$ teapot fetch

### Tests

Run the tests to confirm basic functionality:

	$ cd streams
	$ teapot Test/Streams

## Usage

### Formatted Output

Here is a simple example which will write formatted output when running on a TTY:

	// Associate TTY terminal data with the stream:
	TTY tty(std::cout, terminal_type(std::cout));

	// Setup the desired color/style:
	Color color(Color::RED);
	
	// Write formatted data to the stream:
	std::cout << color << "Hello World!";

### Parsing Data

Here is an example of how to perform basic data parsing using a delimeter:

	std::stringstream buffer("1,2");
	int x = 0, y = 0;
	
	buffer >> x >> expect<','> >> y;

## Contributing

1. Fork it.
2. Create your feature branch (`git checkout -b my-new-feature`).
3. Commit your changes (`git commit -am 'Add some feature'`).
4. Push to the branch (`git push origin my-new-feature`).
5. Create new Pull Request.

## License

Released under the MIT license.

Copyright, 2017, by Samuel Williams. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.