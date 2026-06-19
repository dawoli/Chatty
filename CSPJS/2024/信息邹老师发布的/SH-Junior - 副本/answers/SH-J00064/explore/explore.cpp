#include<bits/stdc++.h> 
using namespace std;
int T,n,m,k,x,y,d,ans;
bool check[1009][1009];
char q[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int p=0;p<T;p++){
		ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				check[i][j]=false;
			}
		}
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>q[i][j];
			}
		}
		check[x][y]=1;
		for(int i=1;i<=k;i++){
			int x1=x,y1=y;
			if(d==0)y1++;
			if(d==1)x1++;
			if(d==2)y1--;
			if(d==3)x1--;
			if(x1<1||x1>n||y1<1||y1>m||q[x1][y1]=='x'){
				d=(d+1)%4;
			}
			else{
				check[x1][y1]=true;
				x=x1;
				y=y1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(check[i][j]==true){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
