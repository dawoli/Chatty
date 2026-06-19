#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	char ch=getchar();
	ll ret=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
const int N = 2e5+20;
const int V = 1e6+20;
ll dp[N],a[N];
int pre[V],get_pre[N];
ll pre_max[N];
void multi_test(){
	ll n=read();
	ll ex_ans=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]==a[i-1]){
			ex_ans+=a[i];
			i--,n--;
		}
	}
	for(int i=1;i<=n;++i){
		get_pre[i]=pre[a[i]];
		pre[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		int j=get_pre[i];
		pre_max[i]=pre_max[i-1];
		if(j==0)
			continue;
		assert(j+1<i);
		dp[i]=pre_max[j+1]+a[i];
		pre_max[i]=max(pre_max[i],dp[i]);
//		cout<<"i="<<i<<" *"<<dp[i]<<endl;
	}
	cout<<pre_max[n]+ex_ans<<endl;
	for(int i=1;i<=n;++i){
		pre[a[i]]=0;
		get_pre[i]=0;
		pre_max[i]=0;
		dp[i]=0;
	}
	return ;
} 
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T=read();
	while(T--) multi_test();
	return 0;
}
