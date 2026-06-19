#include<bits/stdc++.h>
using namespace std;
int n,r,zc[100001],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>r;
		zc[r]++;
	}
	for(int i=1;i<100001;i++) ans=max(zc[i],ans);
	cout<<ans;
	return 0;
}
