#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,r[MAXN],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;	cin>>x;
		r[x]++;
	}
	for(int i=1;i<=100000;i++)	ans=max(ans,r[i]);
	cout<<ans;
	return 0;
}
