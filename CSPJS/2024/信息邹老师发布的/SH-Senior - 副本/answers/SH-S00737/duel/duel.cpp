#include<bits/stdc++.h>
using namespace std;
int n,r,d[100005],maxn,maxs;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r;
		d[r]++;
		if(r>maxn) maxn=r;
	}
	for(int i=1;i<=maxn;i++){
		if(d[i]>maxs) maxs=d[i];
	}
	cout<<maxs;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
