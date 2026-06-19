#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,k,a[500005],to[500005],lst[500005];
int f[500005];
signed main(){//xor
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	
	int s=0;
	for(int i=1;i<=n;i++){
		s^=a[i];
		if(lst[s^k]){
			to[i]=lst[s^k];
		}
		else if(s==k){
			to[i]=0;
		}
		else to[i]=-1;
		lst[s]=i;
	}
	
	f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(to[i]!=-1)f[i]=max(f[i],f[to[i]]+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}
