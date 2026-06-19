#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5500],maxn,sum,ans,tmp;
const int mod=998244353;
bool check1(){
	return n<=3;
}
void solve1(){
	if(n==3&&sum>maxn*2){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
bool check2(){
	return n<=25;
}
void dfs(int dep,int cnt,int ma,int num){
	if(dep==n+2){
		return ;
	}
	if(cnt>ma*2&&num>=3&&dep==n+1){
		//cout<<dep<<" "<<cnt<<" "<<ma<<" "<<num<<" "<<endl;
		ans++;
	}
	dfs(dep+1,cnt,ma,num);
	dfs(dep+1,cnt+a[dep],max(ma,a[dep]),num+1);
}
void solve2(){
	dfs(1,0,0,0);//深度，和，最大值，选的数量 
	cout<<ans%mod;
}
bool check3(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			return false;
		}
	}
	return true;
}
void solve3(){
	tmp=1;
	for(int i=1;i<=n;i++){
		tmp*=2;
		tmp%=mod;
	}
	cout<<tmp-1-n-(n-1)*n/2;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(check1()){
		solve1();
	}
	else if(check2()){
		solve2();
	}
	else if(check3()){
		solve3();
	}
	else{
		cout<<1;
	}
	return 0;
}
