#include<bits/stdc++.h>
#define N 100009
using namespace std;
int dp[N][2],a[N],pr[N],ans,n,t;
int ask(int mask,int bit){
	return (mask&(1<<bit))!=0;
}
void solve1(){
	ans=0;
	for(int i=0;i<(1<<n);i++){
		int tmp=0; 
		for(int j=0;j<n;j++){
			for(int k=0;k<j;k++){
				int flg=1;
				for(int l=k+1;l<j;l++)if(ask(i,l)==ask(i,j)||ask(i,l)==ask(i,k))flg=0; 
			//	if(i==5&&j==2&&
				if(ask(i,j)==ask(i,k)&&a[k]==a[j]&&flg)tmp+=a[j];
			}
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<"\n";
}
void solve2(){
	
}
void clr(){
	memset(dp,0,sizeof(dp));
}
int solve(){
	cin>>n;int flg=1;
	for(int i=0;i<n;i++){cin>>a[i];if(a[i]>10)flg=0;}
	if(n>15&&0)solve2();
	else solve1();
	clr(); 
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}
