#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5010],c[5010],n,m,t,x[4],r[5010];
string s[14];
signed main(){
	freopen("arena.in","r",stdin); 
	freopen("arena.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	for(int i=0;i<ceiling(log2(n));i++)
		cin>>s;
	cin>>t;
	while(t--){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		int ans=0;
		for(int b=1;b<=m;b++){
			for(int i=1;i<=n;i++)
				a[i]=r[i]^x[i%4];
			int cp=c[b];
			for(_=0;c[b];c[b]/=2,_++)
				for(int i=1;i<=c[b]/2;i++)
					if(s[_][i])
						if(a[2*i]>_)
							a[i]=a[2*i];
						else
							a[i]=a[2*i-1];
					else
						if(a[2*i-1]>_)
							a[i]=a[2*i-1];
						else
							a[i]=a[2*i];
			c[b]=cp;
			ans^=b*a[1];
		}
		cout<<ans;
	}
} 
