#include <bits/stdc++.h>
using namespace std;
long a[50005];
int xr(int l,int r){
	int ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=(ans^a[i]);
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
//	int a[n+1];
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	cout<<ans<<endl;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(k==xr(l,r)){
				ans++;
				l=r+1;
				r++;
			}
		}
	}
	//cout<<xr(2,4)<<endl;
	cout<<ans;
	return 0;
}
