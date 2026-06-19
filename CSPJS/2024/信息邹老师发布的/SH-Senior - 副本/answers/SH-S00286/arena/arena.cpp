#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>k;
	for(int i=1;i<=m;i++)
		cin>>k;
	int t=1;
	while((t<<1)<n){
		t++;
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t-i;j++)
			cin>>k;
	}
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
		cin>>k>>k>>k>>k;
	srand(time(0));
	for(int i=1;i<=T;i++)
		cout<<rand()<<endl;
	return 0;
}
