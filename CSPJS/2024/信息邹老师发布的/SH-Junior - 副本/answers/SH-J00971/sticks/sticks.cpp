#include<iostream>
#include<cstdio>
using namespace std;
FILE* fin=freopen("sticks.in","r",stdin);
FILE* fout=freopen("sticks.out","w",stdout);
int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int n,x,r;
		cin>>n;
		if (n<=6){
			if(n==1)cout<<"-1"<<endl;
			if(n==2)cout<<"1"<<endl;
			if(n==3)cout<<"7"<<endl;
			if(n==4)cout<<"4"<<endl;
			if(n==5)cout<<"2"<<endl;
			if(n==6)cout<<"6"<<endl;
		}
		else{
			x=n/7;
			r=n%7;
			if(r==1)cout<<"10";
			if(r==2)cout<<"18";
			if(r==3)cout<<"22";
			if(r==4)cout<<"20";
			if(r==5)cout<<"28";
			if(r==6)cout<<"68";
			for (int j=1;j<=x-1;j++){
				cout<<"8";
			}
			cout<<endl;
		}
	}
	return 0;
}
