#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	swap(n,m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sb=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sb){
			sb=i;
			break;
		}
	}
	int x=(sb+m-1)/m;
	cout<<x<<' ';
	if(x%2==1){
		int l=(x-1)*m+1;
		int r=x*m;
		cout<<sb-l+1;
	}
	else{
		int l=(x-1)*m+1;
		int r=x*m;
		cout<<r-sb+1;
	}
	return 0;
}
