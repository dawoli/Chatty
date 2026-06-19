#include <iostream>
using namespace std;
int a[110][110]; 
int main(){

	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[x+1][y]=1;
		a[x][y+1]=1;
		a[x+1][y+1]=1;
	}
	int cnt = 0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if (a[i][j] == 0) {
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;

	return 0;
}
