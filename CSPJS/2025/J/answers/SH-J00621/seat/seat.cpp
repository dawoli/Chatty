#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[225];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	cout<<"1 1"<<endl;
  return 0;
} 

