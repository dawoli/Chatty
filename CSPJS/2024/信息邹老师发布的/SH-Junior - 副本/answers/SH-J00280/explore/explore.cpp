#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
int n,m,k;
int x1,y1,x2,y2,d;
char a[1010][1010];
int b[1010][1010]={0},ans[6]={0};
string str;

void move(){
	if (d==0){
		x2 = x1;
		y2 = y1 + 1;
	}else if (d == 1){
		x2 = x1+1;
		y2 = y1;
	}else if (d == 2){
		x2 = x1;
		y2 = y1-1;
	}else if (d == 3){
		x2 = x1-1;
		y2 = y1;
	}
	if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= m && a[x2][y2] == '.'){
		x1 = x2;
		y1 = y2;
		b[x1][y1] = 1;
	}else{
		d = (d+1) % 4;
	}
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int tmp=1;tmp<=t;tmp++){
		cin >> m >> n >> k;
		cin >> x1 >> y1 >> d;
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				cin >> a[i][j];
			}
		}
		//for (int i=1;i<=m;i++){
		//	cin >> str;
		//	for (int j=0;j<n;j++){
		//		a[i][j] = str[j];
		//		cout << a[i][j];
		//	}
		//}
		b[x1][y1] = 1;
		for (int i=1;i<=k;i++){
			move();
		}
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				if (b[i][j] == 1) ans[tmp]++;
			}
		}
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				cout << b[i][j];
			}
			cout << endl;
		}
	}

	for (int i=1;i<=t;i++){
		cout << ans[i] << endl;
	}
	return 0;
}
