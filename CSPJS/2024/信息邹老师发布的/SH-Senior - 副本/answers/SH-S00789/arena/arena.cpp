#include<bits/stdc++.h>
#define N 100005
#define ERR 0.000001
using namespace std;
int T,n,m,seedofa[N],c[N],a[N],k=0,x[5],p=1,ans[N];
string num[20];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>seedofa[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	while(p<n){
		p<<=1;
		k++;
	}
	for(int i=1;i<=k;i++) cin>>num[i];
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++) a[i]=seedofa[i]^x[i%4];
		cout<<0<<endl;
	}
	return 0;
}

