#include<bits\stdc++.h>
using namespace std;
unsigned long long c[10]={6,2,5,5,4,5,6,3,7,6};
int a,T;
string s[1111111]={"0","0","1","7","4","2","6","8","10","18","22","20","28","68","88","108","188","200","208"};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(unsigned long long i=16;i<=111111;i++){
			s[i]=s[i-7]+'8';
	}
	while(T--){
		cin>>a;
		if(a==1 or a==0){
			cout<<-1<<endl;
			continue;
		}
		cout<<s[a]<<endl;
	}
	return 0;
} 
