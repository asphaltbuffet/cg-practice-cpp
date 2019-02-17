/*
 * Copyright (c) 2019 Ben Lechlitner (otherland@gmail.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "cg-practice-cpp/factorial.hpp"
#include "power-of-thor-episode-1.cpp"

int main( const int numberOfInputs, const char* inputArguments[ ] )
{
	try
	{
		const int factorial = cg_practice_cpp::computeFactorial( 10 );
		std::cout << "10! = " << factorial << std::endl;
	}
	catch( std::exception& error )
	{
		std::cout << error.what( ) << std::endl;
	}

	try
	{
		const int factorial = cg_practice_cpp::computeFactorial( -5 );
		std::cout << "5! = " << factorial << std::endl;
	}
	catch( std::exception& error )
	{
		std::cout << error.what( ) << std::endl;
	}

	return EXIT_SUCCESS;
}
