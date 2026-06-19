#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int f[1000005],a[1000005],maxn,base;
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=1e6;i++) f[i]=-1e9;
		maxn=0,base=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==a[i-1]){
				base+=a[i];
			    f[a[i-1]]=max(f[a[i-1]],maxn-a[i]);
			}
			else f[a[i-1]]=max(f[a[i-1]],max(maxn,f[a[i]]+a[i]));
			maxn=max(maxn,f[a[i-1]]);
		}
		cout<<maxn+base<<endl;
	}
}
