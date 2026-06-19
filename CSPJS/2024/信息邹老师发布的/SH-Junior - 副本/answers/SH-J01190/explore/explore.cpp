#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,x,y,d,ans;
	char a[1009][1009];
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>a[j][l];
			}
		}
		a[1][1]='o';
		ans=1;
		for(int j=0;j<k;j++){
			int x5,y5;
			if(d==0){
				x5=x;
				y5=y+1;
			}else if(d==1){
				x5=x+1;
				y5=y;
			}else if(d==2){
				x5=x;
				y5=y-1;
			}else{
				x5=x-1;
				y5=y;
			}
			if(x5<1||x5>n||y5<1||y5>m||a[x][y]=='x'){
				d=(d+1)%4;
			}else{
				x=x5;
				y=y5;
				if(a[x][y]=='.'){
					ans++;
				}
				a[x][y]='o';
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

