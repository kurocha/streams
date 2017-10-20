//
//  Container.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 20/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Safe.hpp"

#include <iostream>
#include <type_traits>

namespace Streams
{
	template <typename T, typename _ = void>
	struct is_container : std::false_type {};

	template <typename... Ts>
	struct is_container_helper {};

	template <>
	struct is_container<std::string> : public std::false_type {};

	template <typename T>
	struct is_container<
		T,
		typename std::conditional<
			false,
			is_container_helper<
				decltype(std::begin(std::declval<T>())),
				decltype(std::end(std::declval<T>()))
			>,
			void
		>::type
	> : public std::true_type {};
	
	template <typename T>
	struct Safe<T, is_container<T>>
	{
		const T & value;
		
		template <typename T>
		void print(std::ostream & output)
		{
			output << '{';
			bool first = true;
			
			for (auto i = std::begin(value); i != std::end(value); i += 1) {
				if (!first) output << ", ";
				else first = false;
				
				output << safe(*i);
			}
			
			output << '}';
		}
	}
}
