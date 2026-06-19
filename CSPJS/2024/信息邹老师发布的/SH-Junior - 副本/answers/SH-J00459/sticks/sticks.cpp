#include<bits/stdc++.h>
using namespace std;
long long n;
int a(int ceng,int gen){
	int b=n%7;
	if(b){
		b=n/7+1;
	}
	else{
		b=n/7;
	}
	if(ceng==1){
		if(ceng!=b&&gen==6){
			return 0;
		}
		else if(gen==2){
			return 1;
		}
		else if(gen==3){
			return 7;
		}
		else if(gen==4){
			return 4;
		}
		else if(gen==5){
			return 2;
		}
		else if(gen==6){
			return 6;
		}
		else if(gen==7){
			return 8;
		}
	}
	if(gen-6<=7*ceng-7&&ceng!=b&&gen-6>=2){
		return a(ceng-1,gen-6);
	}
	else if(gen-2<=7*ceng-7&&gen-2>=2){
		return 1*pow(10,ceng-1)+a(ceng-1,gen-2);
	}
	else if(gen-5<=7*ceng-7&&gen-5>=2){
		return 2*pow(10,ceng-1)+a(ceng-1,gen-5);
	}
	else if(gen-4<=7*ceng-7&&gen-4>=2){
		return 4*pow(10,ceng-1)+a(ceng-1,gen-4);
	}
	else if(gen-6<=7*ceng-7&&gen-6>=2){
		return 6*pow(10,ceng-1)+a(ceng-1,gen-6);
	}
	else if(gen-3<=7*ceng-7&&gen-3>=2){
		return 7*pow(10,ceng-1)+a(ceng-1,gen-3);
	}
	else if(gen-7<=7*ceng-7&&gen-7>=2){
		return 8*pow(10,ceng-1)+a(ceng-1,gen-7);
	}
	
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n;
		if (n<2){
			cout<<-1<<'\n';
		}
		else{
			int b=n%7;
			if(b){
				cout<<a(n/7+1,n)<<'\n';
			}
			else{
				cout<<a(n/7,n)<<'\n';
			}
		}
	}
	return 0;
}
