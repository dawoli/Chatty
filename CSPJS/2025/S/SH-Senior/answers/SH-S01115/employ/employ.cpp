#include<bits/stdc++.h>
using namespace std;
int n,m,flag[1005],a[1005],c[10005];
string s;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||c[a[i]]<=cnt) cnt++;
	}
	return m<=(n-cnt);
}
int dfs(int pos){
	if(pos==n+1) return check();
	int ret=0;
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			a[pos]=i;
			ret+=dfs(pos+1);
			flag[i]=0;
		}
	}
	return ret;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	cout<<dfs(1)<<endl; 
}
