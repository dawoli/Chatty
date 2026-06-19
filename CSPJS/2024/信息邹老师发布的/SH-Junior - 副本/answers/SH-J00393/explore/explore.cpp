#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,x,y,d,ans=0;
ll mapsd[105][105];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	string p;
	cin>>t;
	while(t!=0){
			for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)mapsd[i][j]=0;
		}
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>p;
				if(p==".") mapsd[i][j]=2;
				else mapsd[i][j]=1;
			}
		} 
		if(n==1&&m<=2){
			if(m==1)cout<<1<<endl;
			else if(mapsd[x][y+1]==2||mapsd[x][y-1]==2)cout<<2<<endl;
			else cout<<1<<endl;
		}
		t--;
	}
	return 0;
}
