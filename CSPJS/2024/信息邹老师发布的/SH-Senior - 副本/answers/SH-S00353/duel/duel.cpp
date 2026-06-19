#include<bits/stdc++.h>
using namespace std;
int r[100010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a,maxa=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		maxa=max(maxa,a);
		r[a]++;
		
	}
	for(int i=0;i<=maxa;i++){
		ans=max(ans,r[i]);
	}
	cout<<ans;
} 
