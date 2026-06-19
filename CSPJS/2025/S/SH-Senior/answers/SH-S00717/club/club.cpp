#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int t,n,ans,tmp;
vector<int>f[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		f[1].clear(),f[2].clear(),f[3].clear();
		ans=tmp=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			tmp=max(x,max(y,z)),ans+=tmp;
			if(x==tmp)f[1].push_back(max(y,z)-tmp);
			else if(y==tmp)f[2].push_back(max(z,x)-tmp);
			else f[3].push_back(max(x,y)-tmp);
		}
		for(int j=1;j<=3;j++){
			if(f[j].size()>n/2){
				sort(f[j].begin(),f[j].end());
				for(int i=f[j].size();i>n/2;i--){
					ans+=f[j][i-1];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
