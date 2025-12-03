#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>
using std::cout;
using std::endl;
namespace rng   = std::ranges;
int main(){
	//creating a lambda function to sum all of the divisors
	auto sumDivisors = 
		[] (int n){
			auto div = 
				rng::views::iota(1, n)
				//creates a range of numbers 1 to n
				| rng::views::filter 
				([n] (int i){
				 return n % i == 0; } );
				//filters to only have numbers that are divisors of n
			return std::accumulate
				(div.begin(), div.end(),0);
			//returns sum of all divisors of n
		};
	auto perfNums = 
		rng::views::iota(1, 10000)
		//creates a range of numbers 1 to 1000 to test
		| rng::views::filter
		([sumDivisors] (int n){
		 return ((sumDivisors(n))==n); } );
		//filters to only return numbers that are equal to sum of its divisors
	rng::for_each
		(perfNums, [] (int n) { cout << n << endl; } );
	//returns all the perfect divisors 1 to 10000 and prints each one (runs for each number in perfNums)
}
