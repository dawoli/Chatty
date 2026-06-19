#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[114];
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int r=a[0];
	sort(a,a+n*m,cmp);
	int x=1,y=0;
	bool ud=1;
	for(int i=0;i<n*m;i++){
		if(ud)y++;
		else y--;
		if(y>n){
			y=n;
			x++;
			ud=0;
		}
		if(y<1){
			y=1;
			x++;
			ud=0;
		}
		if(a[i]==r){
			cout<<x<<' '<<y;
			return 0;
		}
	}
}
