//
//  Callable.hpp
//  This file is part of the "Streams" project and released under the MIT License.
//
//  Created by Samuel Williams on 6/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Type.hpp"

namespace Streams
{
	template <typename T, typename = void>
	struct is_callable : std::false_type {};
	// template<typename R, typename... Args>
	// struct is_callable<R (*)(Args...)> : std::true_type {};
	
	template<typename R, typename... Args>
	struct is_callable<R (&)(Args...)> : std::true_type {};
	
	template <typename T>
	struct is_callable<
		T,
		typename std::conditional<false, decltype(&T::operator()), void>::type
	> : public std::true_type {};
	
	template <typename T>
	struct Safe<T, typename std::enable_if<is_callable<T>::value>::type>
	{
		const T & value;
		
		void print(std::ostream & output) const
		{
			output << typeid(value);
		}
	};
}
