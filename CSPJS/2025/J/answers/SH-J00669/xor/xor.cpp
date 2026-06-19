#include<bits/stdc++.h>
using namespace std;
int n,p;
int a[500009],b[500009];
struct qwq{
	int v,l;
}dp[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		bool op=0;
		if(a[i]==p) op=1;
		else{
			for(int j=i-1;j>=dp[i-1].l;j--){
				if((b[i]^b[j])==p){
					//cout<<i<<" "<<j<<endl;
					op=1;
					break;
				}
			}
		}
		if(op==1){
			dp[i].v=dp[i-1].v+1;
			dp[i].l=i;
		}
		else{
			dp[i].v=dp[i-1].v;
			dp[i].l=dp[i-1].l;
		}
		//cout<<dp[i].l<<endl;
	}
	cout<<dp[n].v<<"\n";
	return 0;
}
