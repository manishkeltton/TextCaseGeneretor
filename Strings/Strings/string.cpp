
#include <bits/stdc++.h>
using namespace std;

int len = 100;
void generateStringUpperCase(int n) {
	int length = 26;
	for(int i=1; i<=n; i++) {
		int a = rand() % length;
		char ch = a + 'A';
		cout<<ch;
	}
	cout<<endl;
}

void generateStringLowerCase(int n) {
	int length = 26;
	for(int i=1; i<=n; i++) {
		int a = rand() % length;
		char ch = a + 'a';
		cout<<ch;
	}
	cout<<endl;
}

int main() {
	freopen("input.txt", "w", stdout);

	srand(unsigned(time(0)));
	int t = 2;
	//cin>>2;
	for(int i=1;i<=t;i++){
		//for length of string between 1 to 100
		int n = (rand() % len) + 1;
		cout<<n<<endl;
		//for lower case string
		generateStringLowerCase(n);

		//for lower case string
		//generateStringUpperCase(n);
			
	}

	return 0;
}