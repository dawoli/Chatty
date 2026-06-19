#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500005],k,c1,c0,ans,ck;
bool f;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==1) c1++;
		if(!a[i]) c0++;
		if(a[i]>255) f=1;
		if(a[i]==k) ck++;
	}
	if(c1==n&&k==0) ans=c1/2;
	else if(c1+c0==n){
		if(k==0){
			for(int i=1;i<=n;++i){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			ans+=c0;
		}
		else ans=c1;
	}
	else if(!f){
		ans+=ck;
		
	}
	cout<<ans<<"\n";
	return 0;
}
