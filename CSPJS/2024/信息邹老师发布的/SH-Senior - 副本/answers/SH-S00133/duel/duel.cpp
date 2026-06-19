#include<bits/stdc++.h>
using namespace std;
int n,ans,k;
int s[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ans=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		s[k]++;
	}
	for(int i=100001;i>=1;i--){
	    ans=max(ans,s[i]);
	}
	cout<<ans;
	return 0;
} 
