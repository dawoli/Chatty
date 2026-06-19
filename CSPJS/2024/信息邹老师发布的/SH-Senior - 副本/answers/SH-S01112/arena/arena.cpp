#include<iostream>
#include<cmath>
using namespace std;
const int N=1e5+7;
int n,m,t;
int a[N],b[N];
int x[17][N],w[17][N];
int o[4],na[N];long long ans;
long long getans(int xx){
	int y=pow(2,xx);
	for(int i=1;i<=y;i++)
		w[0][i]=i;
	for(int i=1,p=y/2;i<=xx;i++,p/=2)
		for(int j=1;j<=p;j++){
			int aa=w[i-1][j*2-1],bb=w[i-1][j*2];
			if(x[i][j]==0)
				w[i][j]=(na[aa]>=i?aa:bb);
			else
				w[i][j]=(na[bb]>=i?bb:aa);
		}
	return w[xx][1];
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	int k=log2(n-1)+1;
//	cout<<k<<endl;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	int xx=pow(2,k);
	for(int i=1,p=xx/2;i<=k;i++,p/=2)
		for(int j=1;j<=p;j++)
			scanf("%1d",x[i]+j);
	cin>>t;
	while(t--){
		for(int i=0;i<4;i++)
			cin>>o[i];
		for(int i=1;i<=n;i++)
			na[i]=a[i]^o[i%4];
		for(int i=1;i<=m;i++){
			int x=log2(b[i]);
			ans^=getans(x)*i;
		}
		printf("%lld\n",ans);
	}
}
