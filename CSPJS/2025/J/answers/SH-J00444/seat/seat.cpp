#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[101],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(s==a[i]){
			s=i;
			break;
		}
	}
	int x=1,y=1,d=3,g=1;
	while(x>=1&&x<=m&&y>=1&&y<=n&&g<=n*m){
		if(g==s){
			cout<<x<<' '<<y;
			return 0;
		}
		if((y==1)||(y==n)||(d%2)){
			d=(d+1)%4;
		}
		if(d==0){
			y++;
		}else if(d==1){
			x++;
		}else if(d==2){
			y--;
		}else if(d==3){
			x++;
		}
		g++;
	}
	return 0;
}
