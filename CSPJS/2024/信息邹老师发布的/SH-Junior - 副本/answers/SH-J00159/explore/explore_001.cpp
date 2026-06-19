#include <bits/stdc++.h>
using namespace std;
int grid[1001][1001];
char inp11[3] = {"."};
long long ans,k,xo,yo,doo,t,i,p,rund,kss,n,m;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	cin >> t;
	for (rund=0;rund<t;rund++){
		//没走过0 走过1 障碍2
		cin >> n >> m >> k;
		cin >> xo >> yo >> doo;
		xo -=1;
		yo-=1;
		char inp;
		for (i=0;i<n;i++){
			for(p=0;p<m;p++){
				cin >> inp;
				if (inp==inp11[0]){
				grid[i][p] = 0;
				}
				else {grid[i][p] = 2;}
			}
		}
		grid[xo][yo] = 1;
		for (kss=0;kss<k;kss++){
			if (xo+dir[doo][0] < 0 or xo+dir[doo][0] >= n){
				doo = (doo+1)%4;
				continue;
			}//x issue
			if (yo+dir[doo][1] < 0 or yo+dir[doo][1] >= m){
				doo = (doo+1)%4;
				continue;
			}//y issue
			if (grid[xo+dir[doo][0]][yo+dir[doo][1]] == 2){
				doo = (doo+1)%4;
				continue;
			}//block issue
			grid[xo+dir[doo][0]][yo+dir[doo][1]] = 1;
			xo = xo+dir[doo][0];
			yo = yo+dir[doo][1];
		}
		ans = 0;
		for (i=0;i<n;i++){
			for (p=0;p<m;p++){
				if (grid[i][p] == 1)ans++;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


