#include<bits/stdc++.h>
using namespace std;

bool walked[1009][1009];
char mp[1009][1009];
int dx[4] = {0 , 1 , 0 , -1};
int dy[4] = {1 , 0 , -1 , 0};

int main(){
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T --){
		memset(walked , false , sizeof(walked));
		memset(mp , 'x' , sizeof(mp));
		int n , m , k;
		int x0 , y0 , d0;
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= m ; j ++){
				cin >> mp[i][j];
			}
		}
		//------------¼îµªµÄdfs
		int x = x0 , y = y0 , d = d0 , cnt = 0;
		
		for(int i = 1 ; i <= k ; i ++){
			if(!walked[x][y]) cnt ++;
			walked[x][y] = true;
			int xn = x + dx[d];
			int yn = y + dy[d];
			if(xn < 1 || xn > n || yn < 1 || yn > m || mp[xn][yn] == 'x'){
				d = (d + 1) % 4;
			}
			else{
				x = xn;
				y = yn;
			}
		}
		if(!walked[x][y]) cnt ++;
		walked[x][y] = true;
		cout << cnt << endl;
	} 

	return 0;
}

