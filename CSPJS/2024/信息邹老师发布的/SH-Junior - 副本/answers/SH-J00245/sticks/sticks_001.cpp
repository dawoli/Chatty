#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	string ans="";
	cin>>t;
	int k,m;
	while (t--){
		cin>>n;
		ans="";
		k=ceil(n*1.0/7);
		m=n%7;
		if (m==0){
			for (int i=0;i<k;i++){
				cout<<8;
			}
		}else if (m==1){
			if (k>1){
				cout<<10;
				for(int i=0;i<k-2;i++){
					cout<<8;
				}
			}else{
				cout<<-1;
			}
		}else if (m==2){
			cout<<1;
			for (int i=0;i<k-1;i++){
				cout<<8;
			}
		}else if (m==3){
			if (k>1){
				cout<<22;
				for (int i=0;i<k-2;i++){
					cout<<8;
				}
			}else{
				cout<<7;
			}
		}else if (m==4){
			if (k>1){
				cout<<20;
				for (int i=0;i<k-2;i++){
					cout<<8;
				}
			}else{
				cout<<4;
			}
		}else if (m==5){
			cout<<2;
			for (int i=0;i<k-1;i++){
				cout<<8;
			}
		}else if (m==6){
			cout<<6;
			for (int i=0;i<k-1;i++){
				cout<<8;
			}
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

