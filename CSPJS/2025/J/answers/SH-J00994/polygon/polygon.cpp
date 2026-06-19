#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005];
long long ans; 
void DFS(int now,int sum,int MAX,int cnt){
	if(now>n){
		if(cnt>2){
			ans+=(sum>MAX*2);
			ans%=MOD;
		}
		return;
	}
	DFS(now+1,sum,MAX,cnt);
	DFS(now+1,sum+a[now],max(MAX,a[now]),cnt+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=20){
		DFS(1,0,-1,0);
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=MOD;
		}
		ans=ans-n*(n-1)/2-n-1;		
		if(ans<0)ans+=MOD;
	}
	printf("%d",ans);
	return 0;
}
