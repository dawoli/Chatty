#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	int xr;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			xr=n*m-i+1;
			break;
		}
	}
	//cout<<xr<<endl;
	int x=1,y=1;
	int way=1;//1об2ср3ио 
	for(int i=2;i<=xr;i++){
		
		if(way==1){
			if(y==n){
				x++;
				way=3;
			}
			else{
				y++;
			}
		}
		else{
			if(way==3){
				if(y==1){
					x++;
					way=1;
				}
				else{
					y--;
				}
			} 
		}
	//	cout<<x<<" "<<y<<endl;
	}
	cout<<x<<" "<<y;
	return 0;
}
