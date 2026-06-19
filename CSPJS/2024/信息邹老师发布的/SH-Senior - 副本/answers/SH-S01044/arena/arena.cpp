#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, m, tmp, T;
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	srand(time(0));
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>tmp;
	}
	for(int i=1; i<=m; i++){
		cin>>tmp;
	}
	cin>>tmp;
	cin>>T;
	for(int i=1; i<=T; i++){
		cout<<(rand() % 20);
	}
	return 0;
}
