#include<bits/stdc++.h>
#define N 1000009
using namespace std;
typedef long long ll;
ll f[N],a[N],s[N],tmp[N],lst[N],pre[N],n;//lst not= pre yes=
ll mmax(ll a,ll b){
	return a>b?a:b;
}
ll con(int x){
	int px=pre[x];
	if(px+1==x)return 0;
	return (a[px+1]==a[lst[px]]?a[px+1]:0);
}
int dfs(int x,int rec0,int rec1,int now){
//	cout<<x<<' '<<rec0<<' '<<rec1<<' '<<now<<endl;
	if(x==n){
		if(now==0)return (a[rec0]==a[x]?a[x]:0);
		else return (a[rec1]==a[x]?a[x]:0);
	}
	int score=0;
	if(now==0)score=(a[rec0]==a[x]?a[x]:0);
	else score=(a[rec1]==a[x]?a[x]:0);
	if(now==0)return score+max(dfs(x+1,x,rec1,1),dfs(x+1,x,rec1,0));
	return score+max(dfs(x+1,rec0,x,1),dfs(x+1,rec0,x,0));
}
void solvebf(){
	cout<<max(dfs(1,0,0,1),dfs(1,0,0,0))<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		f[0]=-1e18;
		for(int i=1;i<=1e6;i++)f[i]=a[i]=tmp[i]=lst[i]=pre[i]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=23){solvebf();continue;}
		for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[i]==a[i-1]?a[i-1]:0);
		for(int i=1;i<=n;i++){
			pre[i]=tmp[a[i]];
			tmp[a[i]]=i;
			bool flag=1;
			for(int j=i-1;j>pre[a[i]];j--){
				if(a[j]!=a[i]){
					flag=0;
					lst[i]=j;
					break;
				}
			}
			if(flag)lst[i]=lst[pre[i]];
		}
//		for(int i=1;i<=n;i++){
//			cout<<pre[i]<<' '<<lst[i]<<' '<<s[i]<<endl;
//		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++)f[i]=mmax(f[i],f[j]+s[i]-s[j]);
			f[i]=mmax(f[i],f[pre[i]]+s[i-1]-s[pre[i]]+con(i)+a[i]);
//			cout<<f[i]<<' ';
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=mmax(ans,f[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
