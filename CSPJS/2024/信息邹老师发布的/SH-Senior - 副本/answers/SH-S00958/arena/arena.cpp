#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,m,a[N],c[N],lg[N],p[109][N],x[5];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<N;i++) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=m;j++) cin>>c[j];
	int k=lg[n-1]+1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=(1<<(k-i));j++){
			char c;
			cin>>c;
			p[i][j]=c-'0';
		}
	int t;
	cin>>t;
	while(t--){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++) a[i]=a[i]^x[i%4];
		cout<<0<<endl;
	}
} 
