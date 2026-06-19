#include<bits/stdc++.h>
using namespace std;
bool a[1009][1009], b[1009][1009];
int T, n, m, k;
void work(){
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
//	scanf("%d %d %d", &n, &m, &k);
	int x, y, d, x_, y_;
//	scanf("%d %d %d", &x, &y, &d);
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			char c;
//			scanf("%c", &c);
			cin>>c;
			if(c=='.') a[i][j]=true;
//			printf("%d ", (int)a[i][j]);
//			cout<<a[i][j]<<' ';
		}
//		cout<<endl;
//		printf("\n");
	}
	b[x][y]=true;
	for(int i=1; i<=k; i++){
		x_=x; y_=y;
		switch(d){
			case 0: x_--; break;
			case 1: y_--; break;
			case 2: x_++; break;
			case 3: y_++; break;
		}
		if(a[x_][y_]){
			x=x_;
			y=y_;
		}
		else{
			d=(d+1)%4;
		}
//		cout<<x<<' '<<y<<' '<<d<<endl;
//		printf("%d %d %d\n", x, y, d);
		b[x][y]=true;
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(b[x][y]) ans++;
//			printf("%d ", b[x][y]);
//			cout<<b[x][y]<<' ';
		}
//		cout<<endl;
//		printf("\n");
	}
//	printf("%d\n", ans);
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
//	scanf("%d", &T);
	cin>>T;
	for(int i=1; i<=T; i++) work();
	return 0;
}
