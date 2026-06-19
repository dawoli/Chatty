#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool p(int X,int Y){
	return X>Y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,p);
	int u; 
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			u=i;
			break;
		}
	}
	int ansa,ansb;
	ansa=ceil(1.0*u/n);
	ansb=u-(ansa-1)*n;
	if(!(ansa%2)){
		ansb=n+1-ansb;
	}
	cout<<ansa<<' '<<ansb<<endl;
	return 0;
} 
