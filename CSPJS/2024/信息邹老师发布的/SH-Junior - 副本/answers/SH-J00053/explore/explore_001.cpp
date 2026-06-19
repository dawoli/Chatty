# include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
void f(int n,int m,int &x,int &y,int &d){
	int x2=x,y2=y;
	if (d==0) y2+=1;
	else if (d==1) x2+=1;
	else if (d==2) y2-=1;
	else x2-=1;
	if (x2<=0 || x2>n || y2<=0 || y2>m) d=(d+1)%4;
	else if (a[x2][y2]=='x') d=(d+1)%4;
	else {x=x2;y=y2;}
//	cout << x2 << y2 << ' ';
}
int main(){
	freopen("explore5.in","r",stdin);
	freopen("explore5.ans","w",stdout);
	int t;cin >> t;
	int n,m,k,x,y,d;
	for (int ti=0;ti<t;ti++){
		cin >> n >> m >> k >> x >> y >> d;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) cin >> a[i][j];
		}
		int cnt=1;
		a[x][y]='a';
		for (int ki=0;ki<k;ki++){
			f(n,m,x,y,d);
			if (a[x][y]=='.'){a[x][y]='a';cnt++;}
//			cout << d << ' ' << x << ' ' << y << ' ';
// 			for (int i=1;i<=n;i++){
// 				for (int j=1;j<=m;j++) cout << a[i][j]<< ' ';
// 				cout << endl;
// 			}
		}
//		cout << endl << k << ' ';
		cout << cnt << endl;
//		for (int i=1;i<=n;i++){
//			for (int j=1;j<=m;j++) cout << a[i][j]<< ' ';
//			cout << endl;
//		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
