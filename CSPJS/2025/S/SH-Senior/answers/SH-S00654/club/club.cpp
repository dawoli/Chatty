#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],f[100001][3];
struct NODE{
	int id,c;
	bool operator<(const NODE &a)const{
		return c>a.c;
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		priority_queue<NODE>q[4];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				f[i][1]=1;
				if(a[i][2]>=a[i][3])f[i][2]=2;
				else f[i][2]=3;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				f[i][1]=2;
				if(a[i][1]>=a[i][3])f[i][2]=1;
				else f[i][2]=3;
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				f[i][1]=3;
				if(a[i][1]>=a[i][2])f[i][2]=1;
				else f[i][2]=2;
			}
			ans+=a[i][f[i][1]];
			q[f[i][1]].push(NODE{i,a[i][f[i][1]]-a[i][f[i][2]]});
		}
		while(q[1].size()>n/2){
			ans-=q[1].top().c;
			q[1].pop();
		}
		while(q[2].size()>n/2){
			ans-=q[2].top().c;
			q[2].pop();
		}
		while(q[3].size()>n/2){
			ans-=q[3].top().c;
			q[3].pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}

