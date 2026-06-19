#include<iostream>
using namespace std;
int n,m;
int scores[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int id=1;
	cin>>scores[1];
	for(int i=2;i<=n*m;i++){
		cin>>scores[i];
		if(scores[i]>scores[1])id++;
	}
	int x,y;
	if(id%n==0){
		y=id/n;
	}
	else{
		y=id/n+1;
	}
	if(y%2==0){
		x=n-(id-1)%n;
	}
	else{
		if(id%n==0){
			x=n;
		}
		else{
			x=id%n;
		}
	}
	cout<<y<<" "<<x<<endl;
	
	return 0;
}
