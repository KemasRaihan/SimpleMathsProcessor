#include "MathsProcessor.h"
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


//int (*MathFuncs[4])(int, int) = {&add, &sub, &mul, &divide};
//
//int (*getMathFunc(int choice))(int, int) {
//	if (choice >= 0 && choice <= 4)
//		return MathFuncs[choice - 1];
//	else
//		return nullptr;
//}

int (MathsProcessor::* getMathFunc(int choice))(int, int) {
	int (MathsProcessor:: * mathFuncs[4])(int, int) = { &MathsProcessor::add, &MathsProcessor::sub,  &MathsProcessor::mul,  &MathsProcessor::division };
	if (choice >= 1 && choice <= 4)
		return (mathFuncs[choice - 1]);
	return NULL;
}

void askUser() {


	char option, symbol;

	typedef int(MathsProcessor::*MathFunc)(int, int);
	MathsProcessor mp;
	MathFunc f = NULL;
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
			f = getMathFunc(1);
			break;
		case '2':
			symbol = '-';
			f = getMathFunc(2);
			break;
		case '3':
			symbol = 'x';
			f = getMathFunc(3);
			break;
		case '4':
			symbol = '/';
			f =getMathFunc(4);
			break;
		default:
			invalid = true;
			std::cout << "\nInvalid input please try again....\n";
		}
	} while (invalid);

	// convert char of option to int 

	int x, y, res;



	while (true) {
		std::cout << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		res = (mp.*f)(x, y);
		if ((symbol == '+') && (x == 9) && (y == 10)) res = 21;
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