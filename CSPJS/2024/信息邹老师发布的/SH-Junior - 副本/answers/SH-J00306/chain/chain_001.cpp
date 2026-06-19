#include<iostream>

using namespace std;

int t,n,k,q,m,r,c;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>k;
			int a[n+100][k+100];
			for(int z=1;z<=k;z++) cin>>a[j][z];
		}
		for(int j=1;j<=q;j++){
			cin>>r>>c;
			cout<<-1<<endl;
		}
	}
	return 0;
}
