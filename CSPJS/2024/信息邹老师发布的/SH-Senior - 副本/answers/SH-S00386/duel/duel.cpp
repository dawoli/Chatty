#include<bits/stdc++.h>
using namespace std;
int n;
long long  cnt[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1,x;i<=n;++i) {
		cin>>x;
		cnt[x]++;
	}
	long long mx=0;
	for(int i=1;i<=100000;i++) {
		mx=max(mx,cnt[i]);
	}
	cout<<mx;
	return 0;
}
