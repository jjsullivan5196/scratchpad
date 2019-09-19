#include <cstdio>
#include <utility>
#include <string>

template<typename InputIt, typename UnaryPredicate, typename UnaryFunction>
UnaryFunction for_if(InputIt first, InputIt last, UnaryPredicate cond, UnaryFunction f) {
	for(; first != last; ++first) {
		if(cond(*first)) f(*first);
	}

	return f;
}

template<typename T1, typename T2>
struct pair_struct {
	pair_struct(T1 first, T2 second) : first(first), second(second) {}
	T1 first;
	T2 second;
};

int main() {
	auto p = pair_struct { 22, "some string" };
	auto const& [num, str] = p;

	std::printf("%d %s\n", num, str);
} 
