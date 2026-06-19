#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
const int MAXA=1e6+5;
int T,n,p[MAXA];
long long a[MAXN],t[MAXN],f[MAXN];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T-->0){
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>a[i];
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			t[i]=t[i-1];
			if(p[a[i]]==0){
				f[i]=f[i-1];
				p[a[i]]=i;	continue;
			}
			if(p[a[i]]==i-1){
				f[i]=f[i-1]+a[i];
				t[i]+=a[i];
			}
			else	f[i]=max(f[i-1],f[p[a[i]]+1]+a[i]+t[i-1]-t[p[a[i]]]);
			p[a[i]]=i;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
