#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],bigger = 1;
	cin>>n>>m;
	cin>>a[1];
	int p = a[1];
	for(int i = 2;i <= n*m;i++){
		cin>>a[i];
		if(a[i]>p){
			bigger++;
		}
	}
	int f = 0,x = 1,y = 1;
	for(int i = 1;i <= bigger-1;i++){
		if(f == 0&&x+1<=n){
			x++;
		}
		else if(f == 0&&x+1>n){
			y++;
			f = 1;
		}
		else if(f == 1&&x-1>=1){
			x--;
		}
		else{
			y++;
			f = 0;
		}
	}
	cout<<y<<" "<<x<<"\n";
} 
