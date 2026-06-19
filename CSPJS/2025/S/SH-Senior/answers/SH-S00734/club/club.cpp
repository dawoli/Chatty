#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int t,n,x,y,z,ans,srt[maxn],srr[maxn],sre[maxn];
vector<int> v[4];
void dfs(int dep,int fi,int se,int th,int sum){
	if(dep==n){
		ans=max(ans,sum);
		return ;
	}
	if(fi+1<=n/2)
		dfs(dep+1,fi+1,se,th,sum+v[1][dep]);
	if(se+1<=n/2)
		dfs(dep+1,fi,se+1,th,sum+v[2][dep]);
	if(th+1<=n/2)
		dfs(dep+1,fi,se,th+1,sum+v[3][dep]);	
}
bool cmp(int a,int b){
	return a>b;
}
bool checkA(){
	for(int i=0;i<n;i++){
		if(v[2][i]!=0||v[3][i]!=0){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(v,0,sizeof(v));
		memset(srr,0,sizeof(srr));
		memset(srt,0,sizeof(srt));
		memset(sre,0,sizeof(sre));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			v[1].push_back(x);
			v[2].push_back(y);
			v[3].push_back(z);
		}
		if(n<=10){//三决策枚举 
			dfs(0,0,0,0,0);//深度，一部门，二部门，三部门 
		}
		else if(checkA()){
			for(int i=0;i<n;i++){
				srt[i]=v[1][i];
			}
			sort(srt,srt+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=srt[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
