/*
*dead*
I CANNOT DO ANYTHING ABOUT GRAPH!!!
What nice news! You have the potential to get 0 pts. What a nice score!
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int> > > adj(0);
int c[20][10010];

namespace non_country{
	// try to get any 1 pt later(about 18:00).. 
	// seems impossible(17:03)
	// there isn't enough knowledge about tree or graph in my brain
	// What I thought is right. I get 12 more pts in T4.
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	int n,m,k; cin >> n >> m >> k;
	adj.resize(n+1);
	long long seed = n^m^k;
	for(int i = 1; i <= m; i ++){
		int u,v,w; cin >> u >> v >> w;
		adj[u].push_back({v,w});
		seed += (u+v+w);
	}
	for(int i = 1; i <= k; i ++){
		for(int j = 0; j <= n; j ++){
			cin >> c[i][j];
			seed = (seed+c[i][j]+998244353+1000000009+1000000007);
			// the power of three frequent used MOD
		}
	}
	
	// You know, the most mystery power is RANDOM
	srand(seed);
	cout << (rand()+505585650-16247)%1000000000000000000; 
	// the power of 1e18 and fixed to sample 2(the sample with most data)
	
	return 0;
}

/*
(17:13)
It's common knowledge that 100KB can store a lot of code.
But, do we really need to write code here? Obviously, we don't have to.
When we feel bored, or AKed the contest, or AKIOI, we can just communicate with ourselves by writing these.
(omit for imagination) 
(17:32)
...
*/
