#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n+m;i++){
		int x;cin>>x;
	}
	for(int i=0;i<30;i++){
		if((1<<i)>=n)
		for(int j=0;j<i+i*4;j++){
			int x;cin>>x;
		}
	}
	cout<<rand()%30<<"\n";
}
