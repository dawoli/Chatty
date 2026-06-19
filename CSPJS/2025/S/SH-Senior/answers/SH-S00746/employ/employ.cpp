#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,i,a[15];
long long ans;
bool flag[15];
string s;
void dfs(int x,int y,int z){
	if(x==n){
		if(z>=m) ans++; 
		return;
	}
	if(s[x]=='0'){
		for(int j=1;j<=n;j++)
		if(!flag[j]){
			flag[j]=1; dfs(x+1,y+1,z); flag[j]=0;
		}
	}
	else{
		for(int j=1;j<=n;j++)
		if(!flag[j]){
			flag[j]=1; 
			if(a[j]>y) dfs(x+1,y,z+1);
			else dfs(x+1,y+1,z);
			flag[j]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
