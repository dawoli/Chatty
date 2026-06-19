#include <bits/stdc++.h>
using namespace std;
int n,m,k,x0,y0,d0,cnt=0,T;
bool f[1005][1005];
bool ma[1005][1005];
char t;
int p[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);freopen("explore.out","w",stdout);
	cin >> T;
	while(T--){
		cnt=0;
		memset(f,0,sizeof(f));
		memset(ma,0,sizeof(ma));
		cin >> n>>m>>k>>x0>>y0>>d0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin >> t;if(t=='x')ma[i][j]=0;else ma[i][j]=1; 
			}
		f[x0][y0]=1;cnt=1;
		while(k--){
			//cout << "-";
			//if(ma[p[d0][0]+x0][p[d0][1]+y0]&&p[d0][0]+x0>=1&&p[d0][0]+x0<=n&&p[d0][1]+y0>=1&&p[d0][1]+y0<=m){ 
			if(ma[p[d0][0]+x0][p[d0][1]+y0]){ 
				if(!f[p[d0][0]+x0][p[d0][1]+y0]){
					cnt ++;f[p[d0][0]+x0][p[d0][1]+y0]=1;
				}
				x0+=p[d0][0];y0+=p[d0][1];
			}
			else d0=(d0+1)%4;
		}
		/*for(int i=1;i<=n;i++){
		
			for(int j=1;j<=m;j++)
				cout << f[i][j];
			cout <<endl;
	    }*/
		cout << cnt<<endl;
	}

	return 0;
} 
