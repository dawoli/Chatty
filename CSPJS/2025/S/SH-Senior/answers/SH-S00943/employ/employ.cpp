#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int f[1000005];
int n,m;string s;
int dfs(int num,int cnt){
	long long res=0;
	if(cnt==n){
		if(n-num>=m)
			return 1;
		else
			return 0;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			res+=dfs(((num>=a[i]||s[cnt]=='0')?num+1:num),cnt+1);
			res%=998244353;
			f[i]=0;
		}
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>s;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,0);
	return 0;
} 
