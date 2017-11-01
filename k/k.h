// header.h - header file for project
// Uncomment the following line to use features for Excel2007 and above.
//#define EXCEL12
#include "xll/xll.h"

#ifndef CATEGORY
#define CATEGORY _T("K")
#endif

typedef xll::traits<XLOPERX>::xcstr xcstr; // pointer to const string
typedef xll::traits<XLOPERX>::xword xword; // use for OPER and FP indices

template<class T = double, class K = double>
struct put {
	T t;
	K k;
};

template<class T = double, class K = double>
struct call {
	T t;
	K k;
};

// F = f exp(-sigma^2 t/2 + sigma B(t)
template<class F = double, class S = double>
struct black {
	F f;
	S sigma;
	template<class T>
	F cdf(T t, F k)
	{
		return 1*(f <= k); //!!! sigma = 0 case
	}
	template<class T>
	F cdf_(T t, F k)
	{
		return cdf(t, k*exp(-sigma*sigma*t));
	}
};

// instrument, model
template<
	template<typename,typename> class I, typename T, typename K
	,
	template<typename,typename> class M, typename F, typename S
>
// E(k - F)+ = k P(F <= k) - f P*(F <= k)
inline F value(I<T,K> i, M<F,S> m)
{
	return i.k * m.cdf(i.t, i.k) - m.f * m.cdf_(i.t, i.k);
}
