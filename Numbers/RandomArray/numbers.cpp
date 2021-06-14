
#include <bits/stdc++.h>
using namespace std;

int len = 100000;
typedef long long int ll;

void generateNumbers(int n, ll x, ll y) {
	ll mod = (y - x + 1);
	ll start = x;

	for(int i=1; i<=n; ++i) {
		ll number = ((ll)rand() * rand()) % mod + start;
		cout<<number;
		if (i < n) cout<<" ";
	}
	cout<<endl;
}

int main() {
	freopen("output.txt", "w", stdout);
	srand(unsigned(time(0)));

	int t= 20; // number of test cases 
	cin>>t;
	// comment if required
	cout<<t<<endl;
	for(int i=0; i<t; i++) {
		// random number of "n" between 1 to len
		int n = rand() % len + 1;
		//comment if required
	    cout<<n<<endl;
		//set the limits of the range array elements 
		ll low_range = (ll)1;
		ll high_range = (ll)1e9;
		
		generateNumbers(n, low_range, high_range);
	

	}

	return 0;
}