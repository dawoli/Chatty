#include<bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	int a[200009];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(a[1]==a[n]){cout<<n;return 0;}
	for(int l=1;l<=n;l++){
		int r=n-l+1;
		if(a[l]==a[r]){cout<<r;return 0;}
	}
	cout<<n/2;
} 
