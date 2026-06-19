#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509;
const int MOD=998244353;
int n,m;
int s[N],c[N];
bool flag=1;
int cnt[N],sum[N],first1=-1;
int jiecheng(int k){
	int sum=1;
	for(int i=1;i<=k;++i){
		sum*=i;
		sum%=MOD;
	}
	sum%=MOD;
	return sum;
}
void solveA(){
	if(cnt[0]==0){
		cout<<jiecheng(n)<<endl;
	}
	else{
		int minus=n-m;
		if(cnt[0]>minus) cout<<0<<endl;
		int ans=jiecheng(n);
		ans-=1;
	}
}
void solven(){
	if(flag==1&&cnt[0]==0) cout<<jiecheng(n)<<endl;
	else cout<<0<<endl;
}
void solve1(){
	int ans=jiecheng(n);
	int nope=cnt[0],summ=1;
	for(int i=1;i<=n;++i){
		if(nope==0){
			summ=0;
			break;
		}
		if(s[i]==1){
			summ*=nope;
			nope-=1;
		}
		else summ*=(n-i+1);
		nope+=cnt[i];
		summ%=MOD;
	}
	cout<<(ans-summ+MOD)%MOD<<endl;
}
void solve(){
	
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	string qwe;
	cin>>qwe;
	for(int i=0;i<n;++i){
		s[i+1]=qwe[i]-'0';
		if(first1==-1&&s[i+1]==1) first1=i+1;
		if(s[i+1]!=1) flag=0;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		cnt[c[i]]++;
	}
	for(int i=0;i<=n;++i){
		for(int j=i+1;j<=n;++j)
			sum[i]+=cnt[j];		
	}
	if(first1==-1) cout<<0<<endl;
	else if(m==n) solven();
	else if(m==1) solve1();
	else if(flag==1) solveA();
	else solve();
	return 0;
}

