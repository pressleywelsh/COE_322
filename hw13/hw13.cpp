#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>
using std::cout;
using std::endl;
namespace rng   = std::ranges;
int main(){
	auto sumDivisors = 
		[] (int n){
			auto div = 
				rng::views::iota(1, n)
				| rng::views::filter

