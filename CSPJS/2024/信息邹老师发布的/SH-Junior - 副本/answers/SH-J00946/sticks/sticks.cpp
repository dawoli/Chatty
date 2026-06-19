#include <bits/stdc++.h>
using namespace std;

int T,n;
string s[55]={"-1","-1","1","7","4","2","6","8","10","18","23","20","28","68","88","108","188","200","208","288","688","888","1088","1888","2008","2088","2888","6888","8888","10888"};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int aa=1;aa<=T;aa++){
		cin>>n;
		if(n==1){
			cout<<"-1"<<endl;
			continue;
		}
		if(n%7==0){
			int num=n/7;
			for(int i=1;i<=num;i++) cout<<"8";
			cout<<endl;
			continue;
		}
		if((n-1)%7==0){
			int num=(n-8)/7;
			cout<<"10";
			for(int i=1;i<=num;i++) cout<<"8";
			cout<<endl;
			continue;
		}
		if((n-2)%7==0){
			int num=(n-2)/7;
			cout<<"1";
			for(int i=1;i<=num;i++) cout<<"8";
			cout<<endl;
			continue;
		}
		if((n-3)%7==0 && n>=24){
			int num=(n-17)/7;
			cout<<"200";
			for(int i=1;i<=num;i++) cout<<"8";
			cout<<endl;
			continue;
		}
		if((n-4)%7==0 && n>=7){
			int num=(n-11)/7;
			cout<<"20";
			for(int i=1;i<=num;i++) cout<<"8";
			cout<<endl;
			continue;
		}
		if((n-5)%7==0){
			int num=(n-5)/7;
			cout<<"2";
			for(int i=1;i<=num;i++) cout<<"8";
			cout<<endl;
			continue;
		}
		if((n-6)%7==0){
			int num=(n-6)/7;
			cout<<"6";
			for(int i=1;i<=num;i++) cout<<"8";
			cout<<endl;
			continue;
		}
		cout<<s[n]<<endl;
	}
	return 0;
}
