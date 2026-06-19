#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

char ditu[1010][1010];
bool zouguo[1010][1010] = {false};

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		// 输入环节 
		int n, m, k, x, y, pos;
		scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &pos);
		pos += 1;
		for(int j = 1; j <= n; j++){
			for(int p = 1; p <= m; p++){
				scanf("%c", &ditu[j][p]);
			}
		}
		zouguo[x][y] = true;
		
		// 执行操作
		for(int j = 1; j <= k; j++){
			int x1 = x, y1 = y;
			if(pos == 0) y1 += 1;
			else if(pos == 1) x1 += 1;
			else if(pos == 2) y1 -= 1;
			else x1 -= 1;
			if(ditu[x1][y1] == '.' && x1 <= n && y1 <= m){
				zouguo[x1][y1] = true;
				x = x1;
				y = y1;
			}else{
				pos = (pos + 1) % 4;
			}
		}
		
		// 计算、输出
		int ans = 0; // 看这个好像有点问题但是又不知道是什么问题的样子就很难受omo 
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(zouguo[i][j] == true) ans += 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
