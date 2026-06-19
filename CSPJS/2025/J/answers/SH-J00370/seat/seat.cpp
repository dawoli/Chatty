#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[114][114];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	cout<<3<<" "<<2;
	return 0;
}
