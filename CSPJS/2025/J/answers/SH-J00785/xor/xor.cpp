#include<bits/stdc++.h>
using namespace std;
struct qujian{
	int l,r;
}quj[500005];
int n,k,m,p,idx=1,idy=1,a,qian[1100000],dp[500005],mx=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	a=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>m;
		a=a^m;
		p=k^a; 
		if(qian[p]!=0||p==0){
			quj[idx].l=qian[p]+1;
			quj[idx].r=i;
			idx++;
		}
		qian[a]=i;
	}
	for(int i=1;i<idx;i++){
		while(quj[idy].r<quj[i].l)idy++;
		dp[i]=max(dp[i-1],dp[idy-1]+1);
	}
	for(int i=1;i<idx;i++){
		mx=max(mx,dp[i]);
	}
	cout<<mx;
	return 0;
}
