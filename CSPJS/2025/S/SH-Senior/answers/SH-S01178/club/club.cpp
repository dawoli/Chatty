#include <bits/stdc++.h>
using namespace std;
int a[4][100001];
int ans;
void dfs(int i,int num,int club1,int club2,int club3,int upn){
	if(i>upn){
		ans=max(ans,num);
	}
	if(club1<upn/2)
		dfs(i+1,num+a[1][i],club1+1,club2,club3,upn);
	if(club2<upn/2)
		dfs(i+1,num+a[2][i],club1,club2+1,club3,upn);
	if(club3<upn/2)
		dfs(i+1,num+a[3][i],club1,club2,club3+1,upn);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		int n;
		cin>>n;
		if(n>30){
			int b[100001];
			for(int i=1;i<=n;i++){
				int p,q;
				cin>>b[i]>>p>>q;
			}
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=b[i];
			}
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		dfs(1,0,0,0,0,n);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			a[1][i]=0;
			a[2][i]=0;
			a[3][i]=0;
		}
	}
	return 0;
}
