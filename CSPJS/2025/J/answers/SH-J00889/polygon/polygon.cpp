#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n; 
ll a[50010];
ll cnt;
bool flag=1;
void dfs(int id,int last,ll sum,ll maxn){
	if(id+n-last<3) return ;
	if(id>=3&&sum>maxn*2){
		cnt++;
		cnt%=mod;
	}
	for(int i=last+1;i<=n;i++){
		dfs(id+1,i,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1]){
			flag=0;
		}
	}
	if(!flag){
		dfs(0,0,0,0);
	}else{
		for(int i=1;i<=n-2;i++){
			cnt+=i;
			cnt%=mod; 
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
