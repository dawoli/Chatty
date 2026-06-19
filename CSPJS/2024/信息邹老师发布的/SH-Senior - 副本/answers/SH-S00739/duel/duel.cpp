#include<bits/stdc++.h>
using namespace std;
int n,a[100001],s[100001],maxs=-1,idx;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
	}
	for(int i=1;i<=100000;i++){
		maxs=max(maxs,s[i]);
	}
	cout<<maxs;
	return 0;
}

