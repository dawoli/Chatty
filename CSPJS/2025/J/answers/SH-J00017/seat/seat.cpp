#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	int myPoint;
	cin>>myPoint;
	
	int x=1,y=1;//x¡– y–– 
	int ope=1;
	for(int i=2;i<=m*n;i++){
		int point;
		cin>>point;
		if(myPoint>point){
			cout<<x<<' '<<y;
			return 0;
		}
		y+=ope;
		if(y==n+1){
			y--;
			x++;
			ope=-1;
		}
		if(y==0){
			y++;
			x++;
			ope=1;
		}
	}
	cout<<n<<' '<<m;
	
	return 0;
}

