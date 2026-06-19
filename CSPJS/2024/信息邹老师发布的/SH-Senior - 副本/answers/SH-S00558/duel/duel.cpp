#include<bits/stdc++.h>
using namespace std;
int n,cnt[100010],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		cnt[a]++;
	}
	for(int i=1;i<=100000;i++)
		ans=max(ans,cnt[i]);
	cout<<ans;
} 
