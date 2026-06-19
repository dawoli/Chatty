#include<bits/stdc++.h>
using namespace std;
int n,a[100005],s[100005],h,x,y,mx;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;mx=max(mx,a[i]);
	}
	for(int i=1;i<=mx;i++){
		if(!s[i]) continue;
		if(h<=s[i]) h=s[i];
	}
	cout<<h;
	return 0;
} 
