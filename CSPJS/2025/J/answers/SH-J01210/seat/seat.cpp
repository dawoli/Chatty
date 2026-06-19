#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],val;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	val = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i]==val){
			int x = (i-1)/n+1;
			cout<<x<<' ';
			int y = i-(x-1)*n;
			if(x%2==1) cout<<y;
			else cout<<n+1-y;
		}
	}
	return 0;
}
