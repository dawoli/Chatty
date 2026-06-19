#include<bits/stdc++.h>
using namespace std;
bool flagA,flagB;
long long n,k;
long long a[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flagA=1;
		}
		if(a[i]>1){
			flagB=1;
		}
	}
	if(flagA==0){
		cout<<n/2;
		return 0;
	}
	else if(flagB==0){
		if(k==1){
			int cnt1=0;
			for(int i=1;i<=n;i++){
				cnt1+=a[i]==1;
			}
			cout<<cnt1;
		}
		else{
			int cnt0=0;
			for(int i=1;i<=n;i++){
				cnt0+=a[i]==0;
			}
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					i++;
					cnt0++;
				}
			}
			cout<<cnt0;
		}
	}
	return 0;
}
