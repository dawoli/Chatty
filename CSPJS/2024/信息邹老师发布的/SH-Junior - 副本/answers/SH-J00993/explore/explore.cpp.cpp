#include <bits/stdc++.h>
using namespace std;
struct EXL{
	char s;
	int c;
}a[1007][1007];
int t,n,m,k,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i = 1;i<=n;i++)	for(int j = 1;j<=m;j++)	cin>>a[i][j].s;
		for(int i = 0;i<=1000;i++) for(int j = 0;j<=1000;j++) a[i][j].c = 0;
		a[x][y].c = 1;
		int cnt = 1;
		while(k--){
			if(d == 0 && a[x][y + 1].s == '.'){
				if(a[x][y + 1].c == 0){
					a[x][y + 1].c++;
					cnt++;
				}
				y++;
			}
			else if(d == 1 && a[x + 1][y].s == '.'){
				if(a[x + 1][y].c == 0){
					a[x + 1][y].c++;
					cnt++;
				}
				x++;
			}
			else if(d == 2 && a[x][y - 1].s == '.'){
				if(a[x][y - 1].c == 0){
					a[x][y - 1].c++;
					cnt++;
				}
				y--;
			}
			else if(d == 3 && a[x - 1][y].s == '.'){
				if(a[x - 1][y].c == 0){
					a[x - 1][y].c++;
					cnt++;
				}
				x--;
			}
			else{
				d = (d + 1)%4;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
