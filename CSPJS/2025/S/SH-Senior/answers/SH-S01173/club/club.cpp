#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T,n,a[N][5],ans,f,s;
priority_queue<int>q[5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=3;i++)
			while(q[i].size())q[i].pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]>a[i][f])f=j;
			}
			s=0;
			for(int j=1;j<=3;j++){
				if(j==f)continue;
				if(a[i][j]>a[i][s])s=j;
			}
			ans+=a[i][f];
			q[f].push(a[i][s]-a[i][f]);
		}
		for(int i=1;i<=3;i++){
			while(q[i].size()>n/2){
				ans+=q[i].top();
				q[i].pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
