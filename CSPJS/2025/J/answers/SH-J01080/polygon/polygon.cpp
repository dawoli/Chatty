#include<bits/stdc++.h>//ÎßºþT4Æ­ÁË64·Ö 
using namespace std;
const int P=998244353;
long long n,a[5005],m,ans;
void dfs(long long sum,long long ma,int last,int cnt){
	if(last==n){
		if(sum>ma*2 && cnt>=3) ans=(ans+1)%P;
		return;
	}
	dfs(sum+a[last+1],max(ma,a[last+1]),last+1,cnt+1);
	dfs(sum,ma,last+1,cnt);
}
long long c(long long p,long long q){
	long long ans_=1;
	for(int i=p;i>=p-q+1;i--) ans_=ans_*i%P;
	for(int i=1;i<=q;i++) ans_=ans_/i%P;
	return ans_;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma!=1) dfs(0,0,0,0);
	else{
		for(int i=3;i<=n;i++) ans=(ans+c(n,i))%P; 
	}
	cout<<ans;
	return 0;
}
