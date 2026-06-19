#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int f[1<<19][19],a[505];
bool flag[1<<19][19];
string s;int n,m,ans;
int dfs(int pos,int used,int fire,int sum){
	if(pos>n){
		if(sum>=m){
			return 1;
		}
		return 0;
	}
	if(flag[used][sum]){
		return f[used][sum];
	}
	int ret=0;
	for(int i=1;i<=n;i++){
		if(used&(1<<(i-1))){
			continue;
		}
		if(a[i]<=fire){
			//cout<<1<<" "<<i<<" "<<a[i]<<" "<<fire<<endl;
			ret+=dfs(pos+1,used|(1<<(i-1)),fire+1,sum);
			ret%=mod;
		}
		else{
			//cout<<2<<" "<<i<<" "<<a[i]<<" "<<fire<<endl;
			if(s[pos-1]=='0'){
				ret+=dfs(pos+1,used|(1<<(i-1)),fire+1,sum);
				ret%=mod;
			}
			else{
				ret+=dfs(pos+1,used|(1<<(i-1)),fire,sum+1);
				ret%=mod;
			}
		}
	}
	f[used][sum]=ret;
	flag[used][sum]=1;
	return ret;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,0,0)%mod;
}

