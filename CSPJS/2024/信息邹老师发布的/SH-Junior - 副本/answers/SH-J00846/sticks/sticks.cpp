#include<bits/stdc++.h>
using namespace std;
int a;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a;
		if(a<2)cout<<-1<<endl;
		else if(a%7==1){
			cout<<10;
			for(int i=2;7*i<=a;i++)cout<<8;
			cout<<endl;
		}
		else{
			for(int i=1;7*i<=a;i++)cout<<8;
			cout<<endl;
		}
	}
	return 0;
}
