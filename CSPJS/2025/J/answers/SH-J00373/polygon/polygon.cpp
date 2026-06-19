#include<bits/stdc++.h>
using namespace std;
long long s,ans=0,les=0;
int T[5010],H[5010];
void dfs(int sum,int MAX,int h,int ci,int hmax){
	if(ci>=2&&sum>MAX){
		ans++;
		ans%=998244353;
	}
	if(h==hmax){
		return ;
	}
	for(int i=h+1;i<=hmax;i++){
		dfs(sum+T[i],MAX,i,ci+1,hmax);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s;i++){
		cin>>T[i];
	}
	sort(T+1,T+s+1);
	ans=0;
	if(T[s]==1){
		for(int i=1;i<=s-1;i++){
			for(int j=1;j<i;j++){
				H[i]+=H[j];
			}
			for(int j=1;j<=i;j++){
				H[i]+=j*(i-j);
				H[i]%=998244353;
			}
		}
		cout<<H[s-1];
		return 0;
	}
	for(int i=s;i>=3;i--){
		for(int j=1;j<i-1;j++){
			dfs(T[j],T[i],j,1,i-1);
		}
	}
	cout<<ans;
	return 0;
}
