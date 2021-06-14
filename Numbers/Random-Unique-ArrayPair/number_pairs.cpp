// code for generating random string consisting of either lowercase or uppercase letters

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int len = 100;
map<ll,ll>mp;
//Output of each pair is on different line
//Each test is "not" separated by new line
void generate_pair_number(int n, ll x1, ll y1, ll x2, ll y2) {
	ll mod1 = (y1 -  x1 + 1);
	ll start1 = x1;
	ll mod2 = (y2 - x2  + 1);
	ll start2 = x2;

	for(int i=1; i<=n; ++i) {
		ll first = ((ll)rand() * rand()) % mod1 + start1;
		mp[first]++;
		while(mp[first]>1){
           mp[first]--;   
        first = ((ll)rand() * first) % mod1 + start1;
		mp[first]++;
		}
		assert(first >= (x1) && first <= (y1));
		
		ll second = ((ll)rand() * rand()) % mod2 + start2;
 
		mp[second]++;
		while(mp[second]>1){
           mp[second]--;   
        second = ((ll)rand() * second) % mod1 + start2;
		mp[second]++;
		}
		assert(second >= (x2) && second <= (y2));
		printf("%lld %lld\n", first, second);
	}
}

int main() {
	freopen("input.txt", "w", stdout);
	srand(unsigned(time(0)));

	int t= 20; // number of test cases 
	//comment below line if required
	printf("%d\n", t);
	for(int t1=1; t1<=t; t1++) {
		//get random value of "n" between (1, lim_n)
		int n = rand() % len + 1;
		//Comment below line if not needed
	    printf("%d\n", n);
		//set the limits of the range array elements
		ll range_low_first = -1000000000;
		ll range_high_first = (ll)1e9;
		ll range_low_second = -1000000000;
		ll range_high_second = (ll)1e9;
		generate_pair_number(n, range_low_first, range_high_first, range_low_second, range_high_second);
	}
	
	return 0;
}
