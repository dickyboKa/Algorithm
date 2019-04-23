#pragma once
#include "GCD.h"

int lcm(int a, int b)
{
	return (a * b) / gcdEuclidean(a, b);
}