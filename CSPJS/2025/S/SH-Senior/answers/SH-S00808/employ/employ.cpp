#include<bits/stdc++.h>
#define ll long long;
using namespace std;
const int N=510,mod=998244353;
string s;
int di[N],c[N],flag[N];
int n,m,cnt,ans,f;
int A(int a){
	int p=1;
	for(int i=1;i<=a;i++){
		p=p*i%mod;
	}
	return p;
}
void dfs(int day,int m0){
	if(m0+n-day+1<m) return;
	if(m0>=m){
		ans=(ans+A(n-day+1))%mod;
		return ;
	} 
	if(day==n+1){
		ans=(ans+1)%mod;
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(flag[i]==1) continue;
		if(f<c[i] && di[day]==1){
			flag[i]=1;
			dfs(day+1,m0+1);
			flag[i]=0;
		}else if( (f>=c[i] || di[day]==0) && day!=n){
			f++;
			flag[i]=1;
			dfs(day+1,m0);
			flag[i]=0;
			f--;
		} 
	}
}//10pts
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	getline(cin,s);
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	for(int i=0;i<n;i++){
		di[i+1]=s[i]-'0';
		if(di[i+1]==0) cnt++;
	} 
	if(cnt+m>n){
		cout<<0;
		return 0;
	} 
	dfs(1,0);
	cout<<ans;
	return 0;
}
