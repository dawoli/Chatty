#include<bits/stdc++.h>
using namespace std;
int t;
char s[1003][1003];
bool vis[1003][1003];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t--){
		int n, m, k,x,y,d,num=1;
		cin >> n >> m >> k;
		cin>>x>> y >> d;
		memset(vis,0,sizeof(vis));
		vis[x][y] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> s[i][j];
			}
		}
		while(k--){
			if(d == 0 && y + 1 <= m && s[x][y + 1] != 'x'){
				if(!vis[x][++y]){
					num++;
				}
				vis[x][y]=1;
			}
			else if(d == 1 && x + 1 <= n && s[x + 1][y] != 'x'){
				if(!vis[++x][y]){
					num++;
				}
				vis[x][y]=1;
			}
			else if(d == 2 &&y-1 >= 1 && s[x][y-1] != 'x'){
				if(!vis[x][--y]){
					num++;
				}
				vis[x][y]=1;
			}
			else if(d == 3&& x - 1 >= 1 && s[x - 1][y] != 'x'){
				if(!vis[--x][y]){
					num++;
				}
				vis[x][y]=1;
			}
			else{
				d = (d + 1) % 4;
			}
		}
		cout << num << endl; 
	}
	return 0;
}
