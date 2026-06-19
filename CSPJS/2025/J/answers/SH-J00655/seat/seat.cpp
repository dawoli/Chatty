#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
struct yhy {
	int num;
	int id;
	int r,c;
} a[405];
int b[20][20];
bool cmp(yhy a,yhy b) {
	return a.num>b.num;
}
int main() {
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++) {
		cin >> a[i].num;
		a[i].id=i;
	}
	yhy x;
	x.id=1,x.num=a[1].num;
	sort(a+1,a+n+1,cmp);//j––k¡–
	for(int i=1,j=1,k=1; i<=n*m && k<=m; i++,j++) {
		a[i].r=j;
		if(j==n)	j=0,a[i].r--,k++;
		a[i].c=k;
		if(a[i].id==1) {
			if(a[i].c%2==1)	cout << a[i].c<< " " << a[i].r;
			else	cout << a[i].c << " " << n-a[i].r+1;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cin >> a[i][j];
//		}
//	}
//	int k=a[1][1];

//	if(m%2==0){
//		cout<< m << " 1";
//	}else{
//		cout << m << " " << n;
//	}∆≠∑÷


