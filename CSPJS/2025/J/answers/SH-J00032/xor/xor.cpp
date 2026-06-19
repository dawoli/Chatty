#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000009],x,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		cout<<n/2;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==k) ans++;
			else if(a[i]^a[i+1]==k){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	return 0;
}
