#include<bits/stdc++.h>
using namespace std;
int n,k,b1;
int a[1005];
int sum[1005];
int dp[1005];
struct node{
	int x,y;
}b[1000005];
bool cmp(node p,node q){
	if(p.x==q.x){
		return p.y<q.y;
	}
	else{
		return p.x<q.x;
	}
}
void solve(int m){
    dp[m]=max(dp[m],dp[m-1]);
	for(int j=1;j<=b1;j++){
		if(b[j].x>m){
			break;
		}
		if(b[j].x<m){
			continue;
		}
		if(b[j].x==m){
			dp[b[j].y]=max(dp[b[j].y],dp[m]+1);
			break;
		}
	}
	if(m==n){
		return;
	}
	solve(m+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				b1++;
				b[b1].x=j;
				b[b1].y=i;
			} 
		}
	}
	sort(b+1,b+b1+1,cmp);
	for(int i=1;i<=b1;i++){
		if(b[i].x==b[i-1].x){
			continue;
		}
	}
	solve(1);
	cout<<dp[n];
	return 0;
}
