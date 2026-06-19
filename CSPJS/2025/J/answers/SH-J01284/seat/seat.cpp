#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,lst[100]={0},r,x=1,y=1,d=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>lst[i];
	r=lst[0];
	sort(lst,lst+100);
	for(int i=99;i>=100-n*m;i--){
		if(lst[i]==r){
			cout<<y<<" "<<x;
			break;
		}
		if(d==1&&x<n){
			x++;
		}
		else if(d==1&&x==n){
			d=2;
			y++;
		}
		else if(d==2&&x>1){
			x--;
		}
		else if(d==2&&x==1){
			d=1;
			y++;
		}
	}
	return 0;
}
