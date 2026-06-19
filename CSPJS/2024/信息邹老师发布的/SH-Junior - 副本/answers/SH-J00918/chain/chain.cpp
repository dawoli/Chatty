#include<bits/stdc++.h>
using namespace std;

int t,n,K,q,r,c;
int a[1005][200005],ans[1010];
bool vis[200010],flag;

void work(int x,int cc,int now){
	if(flag==true)return;
	if(now==r+2)return;
	if(now==r+1&&cc==c){
		flag=true;
		return;
	}
	for(int i=1;i<=a[x][0];i++){
		if(a[x][i]==cc){
			if(now==r){
				flag=true;
				return;
			}
			for(int j=i+1;j<=min(i+K-1,a[x][0]);j++){
				for(int k=1;k<=n&&k!=x;k++){
					work(k,a[x][j],now+1);
				}
			}
		}
	}
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis,false,sizeof(vis));
		cin>>n>>K>>q;
		for(int i=1;i<=n;i++){
			cin>>a[i][0];
			for(int j=1;j<=a[i][0];j++){
				cin>>a[i][j];
				vis[a[i][j]]=true;
			}
		}
		while(q--){
			flag=false;
			cin>>r>>c;
			if(vis[c]==false){
				cout<<0<<endl;
				continue;
			}
			if(r==1){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=a[i][0];j++){
						if(a[i][j]==1){
							for(int k=j+1;k<=min(j+K-1,a[i][0]);k++){
								if(a[i][k]==c){
									flag=true;
								}
								if(flag==true)break;
							}
						}
						if(flag==true)break;
					}
					if(flag==true)break;
				}
				if(flag==true)cout<<1<<endl;
				else cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				work(i,1,1);
				if(flag==true){
					cout<<1<<endl;
					break;
				}
			}
			if(flag==false)cout<<0<<endl;
			
		}
	}
	return 0;
}
