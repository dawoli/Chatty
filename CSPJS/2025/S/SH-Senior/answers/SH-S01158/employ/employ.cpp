#include<bits/stdc++.h>
using namespace std;
char a[505];
int c[5005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int sum=1;
	for(int i=n;i>=n-m;i--){
		sum*=i;
	}
	cout<<sum;
	return 0;
}
