#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=510;
const int mod=998244353;
int n,m;
string s;
int p[N],c[N];
ll ans;

bool check(){
	int fail_num=0, cnt=0;
	for(int i=1;i<=n;i++){
		if(fail_num < c[p[i]] && s[i-1]=='1') cnt++;
		else fail_num++;
	}
	return cnt>=m;
}

void dfs(int loc){
	for(int i=1;i<loc-1;i++){
		if(p[i]==p[loc-1]) return;
	}
	
	if(loc==n+1){
		if(check()){
			ans++;
			ans %= mod;
		} 
		return;
	}
	
	for(int i=1;i<=n;i++){
		p[loc] = i;
		dfs(loc+1);
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
