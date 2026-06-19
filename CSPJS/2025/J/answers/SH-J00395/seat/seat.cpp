#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) cnt++;
	}
	int xx=1,yy=1;
	for(int i=1;i<=cnt;i++){
		if(xx%2==1) yy++;
		else yy--;
		if(yy==n+1) xx++,yy--;
		else if(yy==0) xx++,yy++;
	}
	cout<<xx<<" "<<yy;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
