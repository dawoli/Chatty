#include<bits/stdc++.h>
using namespace std;
struct no{
	int id,sc;
}a[11000];
bool cp(no x,no y){return x.sc>y.sc;}
struct seat{
	int row,col;
}b[11000];
bool cp2(seat a,seat b){
	if(a.col!=b.col)return a.col<b.col;
	if(a.col%2==0)return a.row>b.row;
	else return a.row<b.row;
}
int cur=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i = 1;i<=n*m;i++)cin>>a[i].sc,a[i].id=i;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			b[++cur]={i,j};
	sort(a+1,a+cur+1,cp);sort(b+1,b+cur+1,cp2);
	for(int i = 1;i<=cur;i++)
		if(a[i].id==1){
			cout<<b[i].col<<" "<<b[i].row;
			break;
		} 
	return 0;
}
