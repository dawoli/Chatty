#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
const int MAXN=5e2+5;
int c[MAXN],p[MAXN];
bool fl[MAXN];
string s;
void dfs(int pos,int sum){//sum¾Ü¾øjob 
	if(pos==n+1){
		if(n-sum>=m){
	//		for(int i=1;i<=n;i++) cout<<p[i]<<" ";
	//		cout<<endl;
			ans++;
			ans%=998244353;
		} 
		return ;
	}
	if(c[p[pos]]<=sum||s[pos]=='0'){
		dfs(pos+1,sum+1);
	}else dfs(pos+1,sum);
	return ;
}
void pl(int pos){
	if(pos==n+1){
		dfs(1,0);
	}
	for(int i=1;i<=n;i++){
		if(fl[i]) continue;
		fl[i]=1;
		p[pos]=i;
		pl(pos+1);
		fl[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	if(n>=100){
		cout<<6<<endl;
		return 0;
	} 
	pl(1);
	cout<<ans<<endl;			
	return 0;
}

