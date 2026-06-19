#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool visited[1010][1010];
int x,y,d;
void move(){
	if (d==0){
		if (a[x][y+1]=='.'){
			y++;
		}
		else{
			d = (d+1)%4;
		}
	}
	else if (d==1){
		if (a[x+1][y]=='.'){
			x++;
		}
		else{
			d = (d+1)%4;
		}
	}
	else if (d==2){
		if (a[x][y-1]=='.'){
			y--;
		}
		else{
			d = (d+1)%4;
		}
	}
	else if (d==3){
		if (a[x-1][y]=='.'){
			x--;
		}
		else{
			d = (d+1)%4;
		}
	}
	return;
}
void f(){
	int n,m,k;
	int cnt = 0;
	cin >> n >> m >> k;
	cin >> x >> y >> d;
	for (int i=0;i<=m+1;i++){
		a[0][i] = 0;
		a[n+1][i] = 0;
	}
	for (int i=0;i<=n;i++){
		a[i][0] = 0;
		a[i][m+1] = 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	visited[x][y] = true;
	while (k){
		move();
		visited[x][y] = true;
		k--;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (visited[i][j]){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			visited[i][j] = 0;
		}
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while (T){
		f();
		T--;
	}
	return 0;
}
