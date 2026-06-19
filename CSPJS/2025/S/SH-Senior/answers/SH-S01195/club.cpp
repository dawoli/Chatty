#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,n;
int a[N][3];
vector<int>vt[3],k;
int ans;
signed main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int mx=0;
			for(int j=0;j<3;j++)
				cin>>a[i][j],mx=max(mx,a[i][j]);
			for(int j=0;j<3;j++)
				if(mx==a[i][j]){
					vt[j].push_back(i);
					break;
				}
			ans+=mx;
		}
		for(int j=0;j<3;j++){
			if(vt[j].size()>n/2){
				int jk=vt[j].size()-n/2;
				for(int i:vt[j]){
					int mx2=0;
					for(int k=0;k<3;k++)
						if(k!=j)
							mx2=max(mx2,a[i][k]);
					k.push_back(a[i][j]-mx2);
				}
				sort(k.begin(),k.end());
				for(int i=0;i<jk;i++)
					ans-=k[i];
				break;
			}
		}
		k.clear();vt[0].clear();vt[1].clear();vt[2].clear();
		cout<<ans<<"\n";
		ans=0;
	}
}
