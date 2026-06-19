#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[1000];
int r;
int seat[11][11];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	int delta=1;
	bool flag=1;
	sort (a+0,a+n*m,cmp);
	int x=0,y=0;
	for (int i=0;i<n*m;i++){
		seat[x][y]=a[i];
		if (x==n-1 && !flag){
			y++;
			delta-=2*delta;
			flag=1;
		}
		else if (x==0 && !flag){
			y++;
			delta-=2*delta;
			flag=1;
		}
		else {
			x+=delta;
			flag=0;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (seat[i][j]==r){
				cout<<j+1<<' '<<i+1;
				return 0;
			}
		}
	}
}
