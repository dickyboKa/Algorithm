#pragma once

// pow with 0(logn)
int power(int x, int raiseTo)
{
	int temp;
	if (raiseTo == 0)
		return 1;
	temp = power(x, raiseTo / 2);
	if (raiseTo % 2 == 0)
		return temp * temp;
	else
		return x * temp * temp;
}

int powerRecrusive(int x, int RaiseTo)
{
	if (RaiseTo == 0)
		return 1;
	else
		return x * powerRecrusive(x, RaiseTo - 1);
}
