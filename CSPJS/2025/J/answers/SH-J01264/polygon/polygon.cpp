#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long s[5005],ans=0;
const long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(s[j]-s[i-1]>a[j]*2){
				cout<<i<<" "<<j<<endl;
				ans++;
				if(ans>=mod){
					ans-=mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
