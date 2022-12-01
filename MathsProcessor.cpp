#include "MathsProcessor.h"

MathsProcessor::MathsProcessor()
{

}
MathsProcessor::~MathsProcessor()
{

}


int MathsProcessor::add(int x, int y) { return (x + y); }
int MathsProcessor::sub(int x, int y) { return (x - y); }
int MathsProcessor::mul(int x, int y) { return (x * y); }
int MathsProcessor::division(int x, int y) {
	if (y == 0)
		return 0;
	else
		return div(x, y).quot;
}
