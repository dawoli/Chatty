#include<bits/stdc++.h>
using namespace std;
int a[500009];
int pre[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=(pre[i-1] xor a[i]);
	}
	int ans=0;
	int minl=1;
	for(int r=1;r<=n;r++)
		for(int l=minl;l<=r;l++)
			if((pre[r] xor pre[l-1])==k){
				ans++;
				minl=r+1;
				break;
			}
	cout<<ans;
	return 0;
}
//rp++
