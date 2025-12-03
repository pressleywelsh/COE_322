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
				([n] (int i){
				 return n % i == 0; } );
			return std::accumulate
				(div.begin(), div.end(),0);
		};
	//auto options = rng::views::iota(1, 10000);
	auto perfNums = 
		rng::views::iota(1, 10000)
		| rng::views::filter
		([sumDivisors] (int n){
		 return ((sumDivisors(n))==n); } );
	rng::for_each
		(perfNums, [], (int n) { cout << n << endl; } );
}
