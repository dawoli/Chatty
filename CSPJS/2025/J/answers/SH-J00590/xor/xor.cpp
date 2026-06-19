#include <bits/stdc++.h>
using namespace std;
long long mx,mn=1048576;
long long n,k,ans;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx<=1){
		if(k==1){
			for(int i=1;i<=n;++i){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}else{
			for(int i=1;i<=n;++i){
				if(a[i]==0){
					ans++;
				}
				if(a[i]==1){
					if(a[i+1]==1){
						ans++;
						i++;
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
