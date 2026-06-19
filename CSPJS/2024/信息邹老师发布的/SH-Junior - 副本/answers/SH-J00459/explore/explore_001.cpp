#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore5.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		long long n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		char a[n][m];
		long long b[n][m],ans=1;
		for (int j=0;j<n;j++){
			for (int k=0;k<m;k++){
				char f;
				cin>>f;b[j][k]=0;
				a[j][k]=f;
			}
		}
		x--;y--;
		b[x][y]=1;
		for (int j=0;j<k;j++){
			if (d==3){
				if (a[x-1][y]!='x'&&x-1>=0){
					if(!b[x-1][y]){
						b[x-1][y]=1;
						ans++;
					}
					x--;
				}
				else{
					d=0;
				}
			}
			else if (d==2){
				if (a[x][y-1]!='x'&&y-1>=0){
					if(!b[x][y-1]){
						b[x][y-1]=1;
						ans++;
					}
					y--;
				}
				else{
					d++;
				}
			}
			else if (d==1){
				if (a[x+1][y]!='x'&&x+1<n){
					if(!b[x+1][y]){
						b[x+1][y]=1;
						ans++;
					}
					x++;
				}
				else{
					d++;
				}
			}
			else if (d==0){
				if (a[x][y+1]!='x'&&y+1<m){
					if(!b[x][y+1]){
						b[x][y+1]=1;
						ans++;
					}
					y++;
				}
				else{
					d++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
