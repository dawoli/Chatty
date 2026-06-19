#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010],d[200010],e[200010],f[200010];
char c[400010];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	int k=1; 
	while((1<<k)<n) k++;
	for(int i=1;i<(1<<k);i++) cin>>c[i];
	int t; cin>>t;
	while(t>0){
		memset(d,0,sizeof(d));
		int x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++) d[i]=a[i]^x[i%4];
		int ans=0;
		for(int i=1;i<=m;i++){
			k=0;
			while((1<<k)<b[i]) k++;
			for(int j=1;j<=(1<<k);j++) e[j]=j;
			for(int j=1;j<=b[i];j++) f[j]=d[i];
			for(int j=1,iii=1,iiiii=1;k>0;j+=2,iii++,iiiii++){
				if(j>(1<<k)) k--,j=1,iiiii=1;
				if(k==0) break;
				int now=j+c[iii]-'0';
					if(e[now]>b[i]) e[iiiii]=e[j]+e[j+1];
					else if(f[now]) e[iiiii]=e[now],f[now]--;
					else e[iiiii]=e[j+1-c[iii]+'0'];
			}
			ans^=(e[1]*i);
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}

