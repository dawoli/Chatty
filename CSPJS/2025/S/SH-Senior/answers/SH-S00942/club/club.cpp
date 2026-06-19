#include<bits/stdc++.h>
#define int long long
using namespace std;

//struct node{
//	int v,p;
//};
//void cmp(node x,node y){
//	return x.v<y.v;
//}

const int N=100010;
int t,n,ans;
int mx[N],vis[N];
int cha[N];
int d[3][N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		memset(cha,-1,sizeof(cha));
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				cin>>d[j][i];
				if(d[j][i]>d[mx[i]][i]){
					mx[i]=j;
				}
			}
			vis[mx[i]]++;
			ans+=d[mx[i]][i];
		}
		int k=-1,x,y;
		for(int j=0;j<3;++j){
			if(vis[j]>n/2){
				k=j;
			}
		}
		if(k==-1){
			cout<<ans<<endl;
			continue;
		}
		if(k==0){x=1,y=2;}
		if(k==1){x=0,y=2;}
		if(k==2){x=0,y=1;}
		for(int i=1;i<=n;++i){
			if(mx[i]==k){
				cha[i]=min(d[mx[i]][i]-d[x][i],d[mx[i]][i]-d[y][i]);
			}
		}
		sort(cha+1,cha+n+1);
		for(int i=1,j=1;i<=vis[k]-n/2;j++){
			if(cha[j]!=-1){
				ans-=cha[j];
				i++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
