#include<bits/stdc++.h>
using namespace std;
long long n,k,a[210001],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cin>>n>>k;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==1){
			if(a[i]==1)ans++;
		}
		if(k==0){
			if(a[i]==0)ans++;
			if(a[i]==a[i-1]&&a[i]!=0){
				ans++;
				a[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
