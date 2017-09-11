//
//  Terminal.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/9/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include <ios>

namespace Streams
{
	enum class Terminal : int {
		NONE = 0,
		XTERM = 1,
	};
	
	Terminal terminal_type(int descriptor);
	Terminal terminal_type(std::ios & stream);
	
	// Bind to an output stream to control TTY escape codes.
	class TTY
	{
	public:
		// Bind a stream to a terminal.
		TTY(std::ios_base & stream, Terminal terminal) : _stream(stream), _terminal(terminal)
		{
			stream.iword(INDEX) = static_cast<int>(_terminal);
			
			//assert(stream.pword(INDEX) == nullptr);
			//stream.pword(INDEX) = this;
		}
		
		// Query a stream for TTY details.
		TTY(std::ios_base & stream) : _stream(stream), _terminal(static_cast<Terminal>(stream.iword(INDEX)))
		{
		}
		
		~TTY()
		{
			//_stream.iword(INDEX) = 0;
		}
		
		explicit operator bool() const {return _terminal != Terminal::NONE;}
		Terminal terminal() const noexcept {return _terminal;}
		
	protected:
		std::ios_base & _stream;
		Terminal _terminal;
		
		static const int INDEX;
	};
}
