#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200]
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum+=sqrt(a[i][j]);
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
