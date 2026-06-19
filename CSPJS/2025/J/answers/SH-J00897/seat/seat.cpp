#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int arr=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==arr){
			cout<<x<<' '<<y;
			break;
		}
		if(x&1)y++;
		else y--;
		if(y>n)x++,y=n;
		else if(y<1)x++,y=1;
	}
	return 0;
}
