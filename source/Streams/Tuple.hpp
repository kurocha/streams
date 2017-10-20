//
//  Tuple.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 20/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Safe.hpp"

#include <tuple>

namespace Streams
{
	template <typename... Args>
	struct Safe<std::tuple<Args...>, void>
	{
		const std::tuple<Args...> value;
		
		template <std::size_t N, typename... T>
		typename std::enable_if<(N >= sizeof...(T))>::type
		print_tuple(std::ostream &, const std::tuple<T...> &) const {}

		template <std::size_t N, typename... T>
		typename std::enable_if<(N < sizeof...(T))>::type
		print_tuple(std::ostream & output, const std::tuple<T...> & tuple) const
		{
			if (N != 0)
				output << ", ";
			
			output << safe(std::get<N>(tuple));
			
			print_tuple<N+1>(output, tuple);
		}
		
		void print(std::ostream & output) const
		{
			output << '(';
			
			print_tuple<0>(output, value);
			
			output << ')';
		}
	};
}
