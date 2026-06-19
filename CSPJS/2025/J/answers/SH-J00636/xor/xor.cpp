#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<20;++j){
			int on=1<<j;
			if(a[i]/on%2){
				if(a[i-1]/on%2){
					a[i]-=on;
				}
			}
			else{
				if(a[i-1]/on%2){
					a[i]+=on;
				}
			}
		}
		if(a[i]==k){
			a[i]=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
