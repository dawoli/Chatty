#include<bits/stdc++.h>
using namespace std;
const int maxn=100009;
typedef long long ll;
ll t,n,a[maxn][4],b[maxn][4];
bool flag;
ll ans=0;
void dfs(ll pos,ll as,ll na,ll nb,ll nc){
	if(pos>n){
		if(as>ans)ans=as;
		return;
	}
	if(na<n/2)dfs(pos+1,as+a[pos][1],na+1,nb,nc);
	if(nb<n/2)dfs(pos+1,as+a[pos][2],na,nb+1,nc);
	if(nc<n/2)dfs(pos+1,as+a[pos][3],na,nb,nc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		flag=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0) flag=0;
		}
		if(n==2){
			ll ans1=a[1][1]+max(a[2][2],a[2][3]);
			ll ans2=a[1][2]+max(a[2][1],a[2][3]);
			ll ans3=a[1][3]+max(a[2][1],a[2][2]);
			ans=max(ans1,max(ans2,ans3));
			cout<<ans<<endl;
		}
		else if(flag==1){
			ll tmp[maxn];
			for(int i=1;i<=n;i++)tmp[i]=a[i][1];
			sort(tmp+1,tmp+1+n);
			ans=tmp[n]+tmp[n-1];
			cout<<ans<<endl;
		}
		else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		
	} 
	return 0;
}
