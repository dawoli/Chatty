#include<bits/stdc++.h>
using namespace std;

int n,m,t,K,k,sum=1,a[100005],c[100005],r[100005];

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	for(K=1;sum<=n;K++) sum*=2;
	for(int i=1;i<=K;i++){
		string s;
		cin>>s;
	}
	while(t--){
		int x[5],res=1;
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++) r[i]=a[i]|x[i%4];
		for(int i=1;i<=m;i++){
			for(k=1;res<=c[i];k++) res*=2;
			cout<<sum/res+r[1]<<endl;
		}
	}
}
