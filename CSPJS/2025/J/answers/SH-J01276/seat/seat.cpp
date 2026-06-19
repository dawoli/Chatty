#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int s[n][m];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]=a[i];
		}
	}
	return 0;
}
