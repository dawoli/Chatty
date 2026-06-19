#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	 
	if(n==2){
		int ans=0;
		if(a[1]==k){
			ans++;
			if(a[2]==k)ans++;
		}
		else if(a[2]==k)ans++;
		else if(a[1]==a[2])ans++;
		cout<<ans;
	} 
	return 0;
}
