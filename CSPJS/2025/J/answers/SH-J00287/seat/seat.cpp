#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r,rorder,nr,mr;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==r){
			rorder=i;
			break;
		}
	}
	mr=(rorder+n-1)/n;
	if (mr%2==1){
		nr=rorder%n;
		if (nr==0){
			nr=n;
		}
	}
	else{
		nr=n-rorder%n+1;
		if (nr==n+1){
			nr=1;
		}
	}
	cout << mr << " " << nr;
	return 0;
}
