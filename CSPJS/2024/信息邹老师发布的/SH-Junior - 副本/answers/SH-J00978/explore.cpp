#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,T,x,y,d,c = 0;
char a[1005][1005];
const int fx[] = {0,1,0,-1};
const int fy[] = {1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	for(int i = 1;i <= T;i++){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= m;k++){
				cin >> a[j][k];
			}
		}
		a[x][y] = '*';
		while(k--){
			int nx = x+fx[d],ny = y+fy[d];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && (a[nx][ny] == '.' || a[nx][ny] == '*')){
				x = nx;
				y = ny;
				if(a[nx][ny] == '.') c++;
				a[nx][ny] = '*';
			}else{
				d = (d+1)%4;
			}
		}
		cout << c+1 << endl;
		c = 0;
	}
	//x
	return 0;
}
