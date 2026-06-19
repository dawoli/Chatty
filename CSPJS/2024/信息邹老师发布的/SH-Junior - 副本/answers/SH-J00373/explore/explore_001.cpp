#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("explore.in");
ofstream fout("explore.out");
char c[1005][1005][10];
int n[10], m[10], ans[10];
void dfs(int i, int j, int fx, int maxstep, int nzsj){
	if(maxstep == 0) return;
	if(fx == 0){
		if(j <= 0 || c[i][j][nzsj] == 'x'){
			dfs(i, j, (fx + 1) % 4, maxstep - 1, nzsj);

		}
		else{
			ans[nzsj]++;
			dfs(i, j - 1, fx, maxstep - 1, nzsj);
		}
	}
	if(fx == 1){
		if(i >= n[nzsj] - 1 || c[i][j][nzsj] == 'x'){
			dfs(i, j, (fx + 1) % 4, maxstep - 1, nzsj);
			
		}
		else{
			ans[nzsj]++;
			dfs(i + 1, j, fx, maxstep - 1, nzsj);
		}
	}
	if(fx == 2){
		if(j >= m[nzsj] - 1 || c[i][j][nzsj] == 'x'){
			dfs(i, j, (fx + 1) % 4, maxstep - 1, nzsj);
		}
		else{
			ans[nzsj]++;
			dfs(i, j + 1, fx, maxstep - 1, nzsj);
		}
	}
	if(fx == 3){
		if(i <= 0 || c[i][j][nzsj] == 'x'){
			dfs(i, j, (fx + 1) % 4, maxstep - 1, nzsj);
		}
		else{
			ans[nzsj]++;
			dfs(i, j - 1, fx, maxstep - 1, nzsj);
		}
	}
}
int main(){
	int t;
	fin >> t;
	for(int i = 0; i < t; i++){
		int k;
		fin >> n[i] >> m[i] >> k;
		int x, y, d;
		fin >> x >> y >> d;
		for(int j = 0; j < n[i]; j++){
			for(int h = 0; h < m[i]; h++){
				fin >> c[j][h][i];
			}
		}
		dfs(x - 1, y - 1, d, k, i);
	}
	for(int i = 0; i < t; i++){
		fout << ans[i] << "\n";
	}
	return 0;
} 
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x.... 
 */
