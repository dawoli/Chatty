#include<bits/stdc++.h>
using namespace std;
int ton[233];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;int rp;
	for(int i=0;i<n*m;i++){
		int sco;
		cin>>sco;
		ton[sco]++;
		if(i==0)rp=sco;
	
	}
	int gp=0;
	for(int i=100;i>rp;i--){
		gp+=ton[i];
	}int op=gp/n;
	if(op%2==1){
		cout<<op+1<<' '<<n-gp%n<<endl;
	}if(op%2==0){
		cout<<op+1<<' '<<gp%n+1<<endl;
	}
	return 0;
}
