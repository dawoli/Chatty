#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],cnt[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	ll mxa=0,lst=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxa=max(mxa,a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=mxa;i++){
		if(lst>cnt[i])continue;
		lst=cnt[i];
	}
	cout<<lst;
	return 0;
}
