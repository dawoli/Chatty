#include <bits/stdc++.h>
using namespace std;
long long a[500007]={0},pre[500007]={0},cnt=0,dp[500007]={0};
struct Node{
	long long L,R;
}e[500007]; 
string to_2(long long x){
	string ans;
	while(x>0){
		ans+=(x%2+'0');
		x/=2;
	}
	return ans;
}
long long yihuo(long long xx,long long yy){
	string x=to_2(xx);
	string y=to_2(yy); 
	int len=max(x.size(),y.size());
	for(int i=x.size();i<len;i++){
		x+='0';
	}
	for(int i=y.size();i<len;i++){
		y+='0';
	}
	long long ans=0,zhi=1;
	for(int i=0;i<len;i++){
		if(x[i]!=y[i]){
			ans+=zhi; 
		}
		zhi*=2; 
	}
	return ans; 
}
bool cmp(Node a,Node b){
	if(a.L==b.L){
		return a.R<b.R;
	}else{
		return a.L<b.L;
	}
}
int main(){
	freopen("xor5.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=yihuo(pre[i-1],a[i]); 
	}
	for(int i=1;i<=n;i++){ 
		for(int j=i;j<=n;j++){
			if(yihuo(pre[i-1],pre[j])==k){
				e[cnt].L=i;
				e[cnt++].R=j;
			} 
		} 
	} 
	sort(e,e+cnt,cmp);
	for(int i=0;i<cnt;i++)dp[i]=1;
	for(int i=0;i<cnt;i++){
		for(int j=cnt;j>=i;j--){
			if(e[i].R<e[j].L){
				dp[j]=max(dp[i]+1,dp[j]);
			}
		}
	}
	long long MAX=0;
	for(int i=0;i<cnt;i++){
		MAX=max(dp[i],MAX);
	}
	cout<<MAX;
	return 0;
}
