#include<bits/stdc++.h>
using namespace std;
int n,m,num,a,l,d=1,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>num;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>num)
			l++;
	}
	for(int i=1;i<=l;i++){
		if(x==n&&d==1)
			d=0;
		if(x==1&&d==-1)
			d=9;
		if(d==1)
			x++;
		if(d==-1)
			x--;
		if(d==0){
			y++;
			d=-1;
		}
		if(d==9){
			y++;
			d=1;
		}
//		cout<<x<<" "<<y<<" "<<d<<endl;
	}
	cout<<y<<" "<<x;
	return 0;
}
