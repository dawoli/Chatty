#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,mem[2005][2005],n,a[200005];
ll colo(ll r,ll b){
	if(r==n||b==n)return 0;
	if(mem[r][b]!=0)return mem[r][b];
	else{
		ll pos=max(r,b)+1;
		if(a[pos]==a[r]){
			return mem[r][b]=max(colo(r,pos),colo(pos,b)+a[pos]);
		}
		else if(a[pos]==a[b]){
			return mem[r][b]=max(colo(pos,b),colo(r,pos)+a[pos]);
		}
		else{
			return mem[r][b]=max(colo(pos,b),colo(r,pos));
		}
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i=0;i<=n;i++){
			for(int k=0;k<=n;k++){
				mem[i][k]=0;
			}
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<colo(0,0)<<endl;
	}
	return 0;
}
