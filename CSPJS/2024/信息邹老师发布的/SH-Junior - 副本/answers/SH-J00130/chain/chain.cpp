#include<bits/stdc++.h>
using namespace std;
int t,n,q,k,r,c;
int mem[1010][1010];
bool flag;

void dfs(int r,int x,int y,vector<int> a[]){
	if(r==1){
		for(int i=y+1;i<=a[x][0] && i<=y+k-1;i++){
			if(a[x][i]==c && r==1){
				flag=1;
				return;
			}
		}
		return;
	}
	if(flag==1)return;
	for(int i=y+1;i<=a[x][0] && i<=y+k-1;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=a[j][0];k++){
				if(a[j][k]==a[x][i] && j!=x)dfs(r-1,j,k,a);
				if(flag==1)return;
			}
		}
	}
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		vector<int> a[100010];
		cin>>n>>k>>q;
		for(int i=1,p;i<=n;i++){
			cin>>p;
			a[i].push_back(p);
			for(int j=1;j<=a[i][0];j++){
				scanf("%d",&p);
				a[i].push_back(p);
			}
		}
		while(q--){
			flag=0;
			cin>>r>>c;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=a[i][0];j++){
					if(a[i][j]==c){flag=1;break;}
				}
			}
			if(flag==0){cout<<0<<endl;continue;}
			flag=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=a[i][0];j++){
					if(a[i][j]==1)dfs(r,i,j,a);
					if(flag==1)break;
				}
				if(flag==1)break;
			}
			if(flag==1)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}
