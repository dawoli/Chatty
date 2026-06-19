#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int _p;
	for(int i=1;i<=n*m;i++) if(a[i]==k) _p=i;
	_p--;
	int j=_p/n,l=_p%n;
	if(j%2==0){
		cout<<j+1<<" "<<l+1;
	}
	else{
		cout<<j+1<<" "<<n-l;
	}
	return 0;
}
