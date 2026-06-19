#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	}
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
	}
	
	for(int i=2;i<n;i*=2){
		int x;
		cin>>x;
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<rand()%(n*n)<<endl;
	}
	return 0;
}

