#include<iostream>
#include<string>
using namespace std;
long long T,cnt;
char map[1010][1010];
bool book[1010][1010];
int x[10]={0,1,0,-1};
int y[10]={1,0,-1,0};
int way1(int A){
	long long n,m,k;
	long long x0,y0,d;
	long long xn,yn;
	cin>>n>>m>>k;
	//cout<<1<<endl;
	cin>>x0>>y0>>d;
	//cout<<1<<endl;
	xn=x0,yn=y0;
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
			//cout<<1<<endl;
			book[i][j]=false;
		}
	}
	//cout<<"ac"<<endl;
	//cout<<k<<endl;
	book[xn][yn]=true;
	cnt=1;
	for(int i=1;i<=k;i++){
		int a=xn+x[d],b=yn+y[d];
		if(xn+x[d]>=1 && xn+x[d]<=n && yn+y[d]>=1 && yn+y[d]<=m && map[a][b]=='.'){
			xn=xn+x[d];
			yn=yn+y[d];
			//cout<<xn<<" "<<yn<<endl;
			if(book[xn][yn]==false){
				book[xn][yn]=true;
				cnt++;
			}

		}
		else d=(d+1)%4;
	}
	cout<<cnt<<endl;
	return 0;
}
int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		way1(i);
		//cout<<"ac"<<endl;
	}
	return 0;
}
