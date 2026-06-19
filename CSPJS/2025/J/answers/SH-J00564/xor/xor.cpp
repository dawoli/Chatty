#include<bits/stdc++.h>
using namespace std;
int n,k,a[110],ans=0,vn[110];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int k0=0;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			ans++;
		}
		if(a[i]==1&&a[i-1]==1&&vn[i-1]!=1&&vn[i]!=1){
			k0++;
			vn[i]=1;
			vn[i-1]=1;
		}
		if(a[i]==0&&vn[i]!=1){
			k0++;
			vn[i]=1;
		}
	}
	if(k==0){
		ans=k0;
	}
	cout<<ans;
	return 0;
}
