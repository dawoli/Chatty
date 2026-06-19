#include <bits/stdc++.h>
using namespace std;
const int N=1007;
int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
int data,n,m,k,x,y,d;
char a[N][N]; 
bool b[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> data;
	int ans=1;
	for(int s=1;s<=data;s++){
		ans=1;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> a[i][j];
				b[i][j]=0;
			}
		}
		for(int i=1;i<=k;i++){
			if(a[x+fx[d][0]][y+fx[d][1]]=='x'||x+fx[d][0]<1||x+fx[d][0]>n||y+fx[d][1]<1||y+fx[d][1]>m){
				d=(d+1)%4;
				continue;
			}
			else{
				x+=fx[d][0],y+=fx[d][1];
				if(!b[x][y]){
					ans++;
					b[x][y]=1;
				}
			}
		}
		cout << ans << endl;
	} 
	return 0;
}
