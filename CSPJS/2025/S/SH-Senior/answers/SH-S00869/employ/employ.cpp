#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,c[N];
int sc1[N],sc2[N];//sc1[i]表示耐心不超过i的人数 sc2[i]表示耐心超过i的人数 
int ez[N],easy;//每场简单面试的编号 
string s;
int jc[N]={1};
void ycl(){
	for(int i=1;i<=500;i++){
		jc[i]=jc[i-1]*i;
		jc[i]%=MOD;
	}
}
void solve1(){
	int ans=0,cnt=0;
	for(int it=0;it<n;it++){
		while(s[it]=='0') it++;//总面试次数 
		cnt++;//已有几次简单面试 
		int res=1;
		for(int i=1;i<cnt;i++){
			res*=sc1[ez[i]]-i+1;//前i场简单面试不通过 
			res%=MOD;
		}
		res*=sc2[it]; res%=MOD; res*=jc[n-cnt]; res%=MOD;
		ans+=res; ans%=MOD;
	}
	cout<<ans<<endl;
}
void solve(){
	s="0"+s; int ans=0,d[N]={};
	for(int i=1;i<=n;i++) cin>>c[i],d[i]=i;
	do{
		int cnt=0,cnt_f=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt_f>=c[d[i]]) cnt_f++;
			else cnt++;
		}
		if(cnt>=m){
			ans++;
			ans%=MOD;
		}
	}while(next_permutation(d+1,d+1+n));
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n<=18) solve();
	for(int i=0;i<n;i++){
		if(s[i]==1) ez[++easy]=i;
	}
	for(int i=1;i<=n;i++) cin>>c[i],sc1[c[i]]++,sc2[c[i]-1]++;
	for(int i=1;i<=n;i++) sc1[i]+=sc1[i-1];
	for(int i=n-1;i>=0;i--) sc2[i]+=sc2[i+1];
	ycl();
	if(n>18&&m==1) solve1();
	else if(m==n){
		if(s.find("0")==-1&&sc2[0]==n) cout<<jc[n]<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
