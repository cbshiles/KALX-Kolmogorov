// function.cpp - Rename this file and replace this description.
#include "k.h"

using namespace xll;

#ifdef _DEBUG

int xll_test_k(void)
{
	try {
		put<> p = {1, 110};
		black<> m = {100, 0.2};
		double v = value(p, m);
		ensure (v == (std::max<double>)(p.k - m.f,0));
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());

		return 0;
	}

	return 1;
}
static Auto<OpenAfter> xao_test_k(xll_test_k);

#endif // _DEBUG