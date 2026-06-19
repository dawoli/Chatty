#include<bits/stdc++.h>
using namespace std;
int a[500007];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			continue;
		} 
		if(a[i]^a[i+1]==k) {
			ans++;
			i++;
			continue;
		}
	}
	cout<<ans;
	return 0;
}

