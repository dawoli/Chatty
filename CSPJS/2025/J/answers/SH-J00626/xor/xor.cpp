#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int c[n+1]={};
	bool a=true;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=1)a=false;
	}
	if(a){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=i;
		}
		cout<<ans;
		return 0;
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(abs(a[i]-a[i+1])==k)ans++;
		}
		cout<<ans;
		return 0; 
	}
	return 0;
}
