#include <iostream>
#include <cassert>
//You can
//compare function pointers(just like memory pointers)
//have arrays of function pointers
//float (*trigfunction[3])(float) = { NULL, NULL, NULL };
//pass them as parameters(use function pointer declaration as the type)
//return a function pointer from a function
//float (*getTrigFunctionPointer(int choice))(float) {
//	switch (choice) {
//	case 0: return &sin;
//	case 1: return &cos;
//	case 2: return &tan;
//	default: return NULL;
//	}
//}

//init

int add(int x, int y) { return (x + y); }
int sub(int x, int y) { return (x - y); }
int mul(int x, int y) { return (x * y); }
int divide(int x, int y) {
	if (y == 0) 
		return 0;
	else
	{
		double result = (double)(x) / (double)(y);
		return (int)result;
	}
}

int (*MathFuncs[4])(int, int) = {add, sub, mul, divide};

int (*getMathFunc(int choice))(int, int) {
	assert(choice > 0 && choice < 4);
	return MathFuncs[choice - 1];
}



int main()
{
#ifdef _DEBUG
	//  _CrtSetBreakAlloc(87);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	int x = 1;
	int y = 2;

	std::cout << getMathFunc(3)(x, y) << "\n";

	return 0;
}