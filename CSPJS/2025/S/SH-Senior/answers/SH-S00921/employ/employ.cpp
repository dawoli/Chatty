#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[20];
long long f[20][1<<20],ans;
bool cache[20][1<<20];
string s;
long long dfs(int pos,int used,int num){
	if(cache[num][used])return f[num][used];
	if(num>n-m)return 0;
	if(pos==n)return 1;
	long long ret=0;
	for(int i=1;i<=n;i++){
		int mask=(1<<(i-1));
		if((mask&used)!=0)continue;
		if(s[pos]-'0'==0||num>=a[i])ret+=dfs(pos+1,used^mask,num+1);
		else ret+=dfs(pos+1,used^mask,num);
		ret%=mod;
	}
	cache[num][used]=true;
	f[num][used]=ret;
	return ret;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<dfs(0,0,0)<<endl;
	return 0;
}
