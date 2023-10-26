#pragma once

#include <iostream>
#include <vector>
#include <string>

template<int N>
struct Factorial
{ enum { value = N * Factorial<N-1>::value }; };

template<>
struct Factorial<1>
{ enum { value = 1 }; };