#include<bits/stdc++.h>
using namespace std;
int a[110],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a0=a[0],ai;
	sort(a,a+(n*m));
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==a0){
			ai=n*m-i;
			break;
		}
	}
	int x=1,y=1;
	for(int i=1;i<ai;i++){
		if(y%2!=0&&x<=n){
			x++;
		}else if(y%2==0&&x>0){
			x--;
		}
		if(x>n){
			x=n;
			y++;
		}
		if(x<1){
			x=1;
			y++;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
