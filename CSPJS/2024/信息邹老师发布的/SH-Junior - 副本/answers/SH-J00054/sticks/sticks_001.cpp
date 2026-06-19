#include<bits/stdc++.h>
using namespace std;
int tt,nn,kk,sss;
int dpp[50]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>tt;
	for(int i=1;i<=tt;i++){
		cin>>nn;
		if(nn<=14){
			cout<<dpp[nn]<<endl;
		}
		else{
			kk=nn/7;
			sss=nn%7;
			if(sss==0){
				for(int i=1;i<=kk;i++){
					cout<<8;
				}
				cout<<endl;
			}
			else if(sss==1){
				cout<<10;
				for(int i=1;i<=kk-1;i++){
					cout<<8;
				}
				cout<<endl;
			}
			else if(sss==2){
				cout<<1;
				for(int i=1;i<=kk;i++){
					cout<<8;
				}
				cout<<endl;
			}
			else if(sss==3){
				cout<<200;
				for(int i=1;i<=kk-2;i++){
					cout<<8;
				}
				cout<<endl;
			}
			else if(sss==4){
				cout<<20;
				for(int i=1;i<=kk-1;i++){
					cout<<8;
				}
				cout<<endl;
			}
			else if(sss==5){
				cout<<2;
				for(int i=1;i<=kk;i++){
					cout<<8;
				}
				cout<<endl;
			}
			else if(sss==6){
				cout<<6;
				for(int i=1;i<=kk;i++){
					cout<<8;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
