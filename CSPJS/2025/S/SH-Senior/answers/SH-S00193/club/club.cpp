#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Max_N=2e5+10;
int t,n,a[Max_N][5],bel[Max_N],del[Max_N],nuum[5],ans;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--){
		priority_queue<int,vector<int>,greater<int> >Q;
		
		ans=0;nuum[1]=nuum[2]=nuum[3]=0;
		
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int ls=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++)if(ls==a[i][j])bel[i]=j,nuum[j]++;
			del[i]=ls-max(a[i][(bel[i]+1)%3+1],a[i][(bel[i])%3+1]);
			ans+=ls;
		}
		for(int k=1;k<=3;k++){
			if(nuum[k]>(n>>1)){
				for(int i=1;i<=n;i++){
					if(bel[i]==k)Q.push(del[i]); 
				}
				while(Q.size()>(n>>1)){
					int u=Q.top();Q.pop();ans-=u;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
//End OF File
