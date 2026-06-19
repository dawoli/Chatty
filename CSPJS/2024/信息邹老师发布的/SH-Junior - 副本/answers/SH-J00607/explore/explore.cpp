#include<bits/stdc++.h>
using namespace std;
const int d_[4][3]={{0,0,1},{0,1,0},{0,0,-1},{0,-1,0}};
string s[1001];
int T,n,m,k,x_,y_,d,a=1;
void op(int x,int y){
	x+=d_[d][1];
	y+=d_[d][2];
	if(x>n||y>m||x<1||y<0||s[x][y]=='x'){
		d=(d+1)%4;
		return;
	}
	x_=x;y_=y;
	if(s[x_][y_]=='.'){
		s[x_][y_]='s';
		a++;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		a=1;
		cin>>n>>m>>k>>x_>>y_>>d;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		y_--;m--;
		s[x_][y_]='s';
		for(int i=1;i<=k;i++)
			op(x_,y_);
		cout<<a<<endl;
	}
	return 0;
}
