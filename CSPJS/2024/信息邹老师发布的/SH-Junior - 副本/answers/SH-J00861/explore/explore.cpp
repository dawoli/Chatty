#include <bits/stdc++.h>

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	register int t, n, m, k, sum, x, y, d, **vis;
	register char** map;
	std::cin >> t;
	for(register unsigned short i = 0; i < t; i++){
		sum = 1;
		std::cin >> n >> m >> k >> x >> y >> d;
		x--;
		y--;
		map = new char* [n];
		vis = new int* [n];
		for(register unsigned int j = 0; j < n; j++){
			map[j] = new char[m];
			vis[j] = new int[m];
			for(register unsigned int l = 0; l < m; l++){
				std::cin >> map[j][l];
				vis[j][l] = 0;
			}
		}
		vis[x][y] = 1;
		for(register unsigned int j = 0; j < k; j++){
			switch(d){
				case 0:
					if(y + 1 < m && map[x][y + 1] == '.'){
						y++;
						if(!vis[x][y]){
							sum++;
							vis[x][y] = 1;
						}
					}
					else{
						d = (d + 1) % 4;
					}
					break;
				case 1:
					if(x + 1 < n && map[x + 1][y] == '.'){
						x++;
						if(!vis[x][y]){
							sum++;
							vis[x][y] = 1;
						}
					}
					else{
						d = (d + 1) % 4;
					}
					break;
				case 2:
					if(y - 1 >= 0 && map[x][y - 1] == '.'){
						y--;
						if(!vis[x][y]){
							sum++;
							vis[x][y] = 1;
						}
					}
					else{
						d = (d + 1) % 4;
					}
					break;
				case 3:
					if(x - 1 >= 0 && map[x - 1][y] == '.'){
						x--;
						if(!vis[x][y]){
							sum++;
							vis[x][y] = 1;
						}
					}
					else{
						d = (d + 1) % 4;
					}
					break;
			}
		}
		for(register unsigned int j = 0; j < n; j++){
			delete[] map[j];
			delete[] vis[j];
		}
		delete[] map;
		delete[] vis;
		std::cout << sum << "\n";
	}
	return 0;
}
