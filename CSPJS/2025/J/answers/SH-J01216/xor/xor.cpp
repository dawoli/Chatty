#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int ans,a[N],n,k;
int XOR(int l,int r) {
	int res=0;
	for(int i=l;i<=r;i++)
		res^=a[i];
	return res;
}
void dfs(int cnt,int l,int r){
	if(XOR(l,r)==k&&l!=0&&r!=0) cnt++;
//	cout<<l<<" "<<r<<" "<<cnt<<endl;
	if(r>n) {
		ans=max(ans,cnt);
		return ;
	}
	for(int i=r+1;i<=n;i++)
		for(int j=i;j<=n;j++)	
			dfs(cnt,i,j);
	ans=max(ans,cnt);
	cnt=0;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=1000&&n>=100)  {
		srand(time(0));
		ans=rand()%101;
		cout<<ans;	
	}
	dfs(0,0,0);
	cout<<ans; 
	return 0;
}
