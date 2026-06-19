#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define N 5005
int n,stk[N],v[N];
int cnt;
void dfs(int k,int d,int len,int mx){
	for(int i=k+1;i<=n;i++){
		if(d>=3&&!v[i]){
			int m=mx;
			mx=max(mx,stk[i]);
			len+=stk[i];
			v[i]=1;;
			if(len>2*mx){
				cnt++;
			} 
			dfs(i,++d,len,mx);
			v[i]=0;
			len-=stk[i];
			mx=m;
		}else if(d<3&&!v[i]){
			v[i]=1;
			dfs(i,++d,len+stk[i],max(mx,stk[i]));
			v[i]=0;
		}else if(d>=3){
			continue;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stk[i];
	}
	sort(stk+1,stk+n+1);
	dfs(-1,0,0,-1);
	cout<<cnt/2%MOD;
	return 0;
}
