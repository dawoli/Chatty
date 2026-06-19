#include <iostream>
using namespace std;
int r[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int XR;
	for(int i=1;i<=n*m;i++){
		int p;
		cin>>p;
		if(i==1) XR=p;
		r[p]++;
	}
	int dir=1;
	int c=1,cspj2025rp=1;
	bool flag=1;
	for(int i=100;i>=0;i--){
		if(r[i]){
			if(i==XR){
				cout<<cspj2025rp<<" "<<c<<endl;
				return 0;
			}
			if((c==n||c==1)&&flag==0){
				cspj2025rp++;
				if(dir==1) dir=-1;
				else dir=1;
				flag=1;
			}
			else{
				c+=dir;
				flag=0;
			}
		}
	}
	return 0;
}
