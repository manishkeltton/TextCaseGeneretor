//Below code is used to generate array filled with pair of random numbers in specified range

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int lim_n = 100000;
map<ll,ll>mp;
//Output of each pair is on different line
//Each test is "not" separated by new line
void generate_pair_numbers(int n, ll x1, ll y1, ll x2, ll y2) {
	ll mod1 = (y1 - x1 + 1);
	ll displace1 = x1;
	ll mod2 = (y2 - x2 + 1);
	ll displace2 = x2;

	for(int i=1; i<=n; ++i) {
		ll first = ((ll)rand() * rand()) % mod1 + displace1;

		assert(first >= (x1) && first <= (y1));
		
		ll second = ((ll)rand() * rand()) % mod2 + displace2;

		assert(second >= (x2) && second <= (y2));
		
		printf("%lld %lld\n", first, second);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "w", stdout);
	#endif
	srand(unsigned(time(0)));

	int test_cases = 6;
	//Comment below line if not needed
	printf("%d\n", test_cases);
	
	for(int t=1; t<=test_cases; ++t) {
	
		//get random value of "n" between (1, lim_n)
		int n = rand() % lim_n + 1;
		//Comment below line if not needed
		 
	    
	    printf("%d\n", n);
		//set the limits of the range array elements
		//works even with negative numbers
		ll range_low_first = 1;
		ll range_high_first = (ll)1e8;
		ll range_low_second = 1;
		ll range_high_second = (ll)1e18;
		generate_pair_numbers(n, range_low_first, range_high_first, range_low_second, range_high_second);
	}
	
	return 0;
}