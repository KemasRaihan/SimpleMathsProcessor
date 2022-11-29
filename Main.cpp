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
	return MathFuncs[choice - 1];
}

void askUser() {


	char option, symbol;

	int(*mathFunc)(int, int);
	bool invalid;

	do {
		invalid = false;
		std::cout << "\nPlease choose a mathematical operation:\n";
		std::cout << "1. Addition\n";
		std::cout << "2. Subtraction\n";
		std::cout << "3. Multiplication\n";
		std::cout << "4. Division\n";

		std::cout << "Please enter an option: ";
		std::cin >> option;

		// user enters a valid index
		switch (option) {
		case '1':
			symbol = '+';
			break;
		case '2':
			symbol = '-';
			break;
		case '3':
			symbol = 'x';
			break;
		case '4':
			symbol = '/';
			break;
		default:
			invalid = true;
			std::cout << "\nInvalid input please try again....\n";
		}
	} while (invalid);

	// convert char of option to int 
	int intOp = (int)(option - '0');
	mathFunc = getMathFunc(intOp);

	int x, y, res;

	while (true) {
		std::cout << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		res = mathFunc(x, y);
		std::cout << x << " " << symbol << " " << y << " = " << res << "\n";
	}


}



int main()
{
#ifdef _DEBUG
	//  _CrtSetBreakAlloc(87);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	askUser();

	return 0;
}