#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool check(int l,int r,int k){
	int c=a[l];
	for(int i=l+1;i<=r;i++){
		c=(c^a[i]);
	}
	if(c==k) return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j,k)) ans++;
 		}
	}
	cout<<ans;
	return 0;
}
