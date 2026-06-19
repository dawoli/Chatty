#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	else {
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
	}
	cout<<ans;
	return 0;
} 
