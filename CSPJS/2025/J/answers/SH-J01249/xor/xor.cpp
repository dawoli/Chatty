#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=a[1];
	for (int i=1;i<=n;i++){
		s=a[i];
		if (a[i]==k) 
			ans=a[i];
		for (int j=i+1;j<=n;j++){
			int maxs=0;
			for (int k=i+1;k<=j;k++){
				s=s^a[k];
				maxs=max(maxs,a[k]);
			}
			if(s==k){
				ans=max(ans,maxs);
			}
		}
	}
	cout<<ans;
	return 0;
}
