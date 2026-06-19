#include<iostream>
using namespace std;
int n,m;
string s;
int c[510];
int ans;
bool vis[510];
const int mod=998244353;
void dfs(int num,int loser,int day,int flag){
	if(num==m){
		long long t=1;
		for(int i=2;i<=n-day;i++) t*=i,t%=mod;
		ans+=t;
		ans%=mod;
		return;
	}
	if(flag==18) return;
	if(s[day]=='1') flag++;
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(loser>=c[i]||s[day]=='0') dfs(num,loser+1,day+1,flag);
		else dfs(num+1,loser,day+1,flag); 
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	bool sp=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') sp=0;
	}
	if(sp){
		long long t=1;
		for(int i=2;i<=n;i++){
			t*=i;
			t%=mod;
		}
		cout<<t;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	} 
	if(m==n){
		bool sp0=1;
		for(int i=0;i<n;i++){
			if(s[i]!='1'||c[i]==0){
				sp0=0;
				break;
			}
		}
		if(sp0) cout<<1;
		else cout<<0; 
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
} 
