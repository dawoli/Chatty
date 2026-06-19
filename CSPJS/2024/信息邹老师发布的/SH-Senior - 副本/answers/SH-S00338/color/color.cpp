#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9,M=1e6+9;
int n;
int a[N];
int la[N],b[M],c[N],f[N];
void mem(){
	memset(a,0,sizeof(a));
	memset(b,-1,sizeof(b));
	memset(c,0,sizeof(c));
	memset(la,-1,sizeof(la));
	memset(f,0,sizeof(f));
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		mem();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			la[i]=b[a[i]];
			b[a[i]]=i;
			if(a[i]==a[i-1])
				c[i]=a[i];
			c[i]+=c[i-1];
		}
		for(int i=1;i<=n;i++){
			if(la[i]==-1)
				f[i]=max(f[i],f[i-1]);
			else{
				if(la[i]==i-1)
					f[i]=f[i-1]+a[i];
				else{
					f[i]=max(f[i-1],f[la[i]+1]+a[i]+c[i-1]-c[la[i]]);
				}
			}
//			cout<<f[i]<<' ';
		}
		cout<<f[n]<<'\n';
	}
	cout<<endl;
	return 0;
}
