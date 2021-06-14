//Below code is used to generate undirected unweighted tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 ll x=1,  y=1000000000;

const int limit_n = 100000;

vector<int> adj[limit_n+1];
int visited[limit_n+1];

//check whether the graph is connected or not
void check_graph_connected(int n) {
	for(int i=0;i<limit_n;i++) visited[i]=false;
	queue<int> q;
	q.push(1);
	visited[1] = true;
    vector<int>::iterator it;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for( it = adj[u].begin(); it != adj[u].end(); ++it) {
			if (!visited[*it]) {
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	
	bool connected = true;
	for(int i=1; i<=n; ++i) {
		connected &= visited[i];
	}

	assert(connected); //if connected = false then assert will be false then 
	                    //  aborted (cor dump) i.e runtime error
}

//Output is space separated vertices pairs which contain an edge
//There is extra line after every test case
void generate_unweighted_tree(int n) {
	set< pair<int,int> > duplicates;
	vector< pair<int,int> > graph;
	
	for(int i=2; i<=n; ++i) {
		int x = i;
		int y = rand() % (i - 1) + 1;
		if (i % 10 == 0) {
			swap(x, y);
		}
		assert (1 <= x <= n);
		assert (1 <= y <= n);
		assert (x != y);
		if (duplicates.find(make_pair(x, y)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		if (duplicates.find(make_pair(y, x)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		duplicates.insert(make_pair(x, y));

		adj[x].push_back(y);
		adj[y].push_back(x);
		graph.push_back(make_pair(x, y));
	}

	random_shuffle(graph.begin(), graph.end());

	for(int i=0; i<n-1; ++i) {
		printf("%d %d\n", graph[i].first, graph[i].second);
	}

	//check whether the graph made is connected or not
	check_graph_connected(n);
	
	for(int i=1; i<=n; ++i) {
		adj[i].clear();
	}

	printf("\n");
}

void generate_numbers(int n) {
	ll mod = (y - x + 1);
	ll displace = x;

	for(int i=1; i<=n; ++i) {
		ll number = ((ll)rand() * rand()) % mod + displace;
		assert(number >= x && number <= y);
		printf("%lld", number);
		if (i < n) {
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
		freopen("inp.txt", "w", stdout);
	 
	srand(unsigned(time(0)));

	int t = 15; // test_cases
	printf("%d\n",t);
	int k;
	for(int i=1; i<=t; ++i) {
		int n = rand() % limit_n + 1; //get random value of "n" between (1, lim_n)
		k=rand() % 100;
		n=n%1000;
		
		printf("%d %d\n", n,k);
		generate_numbers(n);
		generate_unweighted_tree(n);
	}

	return 0;
}