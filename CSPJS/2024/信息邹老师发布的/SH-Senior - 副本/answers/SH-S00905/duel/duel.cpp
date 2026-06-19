#include<bits/stdc++.h>
using namespace std;
long long buc[114514],ans=0,n=0,maxn=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long curn;
		cin>>curn;
		maxn=max(maxn,curn);
		buc[curn]++;
	}
	for(long long i=1;i<=maxn;i++){
		ans=max(ans,buc[i]);
	}
	cout<<ans;
	return 0;
}
