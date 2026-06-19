#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool a[5][14];
char x[3];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	while(n --) {
		scanf("%s",x);
		int nx = 0,ny = 0;
		if(x[0] == 'D') {
			nx = 1;
		}else if(x[0] == 'C') {
			nx = 2;
		}else if(x[0] == 'H') {
			nx = 3;
		}else if(x[0] == 'S') {
			nx = 4;
		}
		if(x[1] == 'A') {
			ny = 1;
		}else if(x[1] == 'T') {
			ny = 10;
		}else if(x[1] == 'J') {
			ny = 11;
		}else if(x[1] == 'Q') {
			ny = 12;
		}else if(x[1] == 'K') {
			ny = 13;
		}else if(x[1] >= '0' && x[1] <= '9') {
			ny = x[1] - '0';
		}
		if(a[nx][ny] == 0) {
			a[nx][ny] = 1;
		} 
	}
	for(int i = 1;i <= 4;i = i + 1) {
		for(int j = 1;j <= 13;j = j + 1) {
			if(a[i][j] == 0) {
				ans ++;
			}
		} 
	}
	printf("%d",ans);
	return 0;
}
