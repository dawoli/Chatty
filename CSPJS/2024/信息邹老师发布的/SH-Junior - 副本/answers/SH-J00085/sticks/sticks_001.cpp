#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		int d=n/7,c=n%7;
		string s="";
		if(c==1) c=8,d--;
		if(c==2) s="1";
		else if(c==3) s="7";
		else if(c==4) s="4";
		else if(c==5) s="2";
		else if(c==6) s="6";
		else if(c==8) s="10";
		while(d--)
			s=s+'8';
		cout<<s<<endl;
	}
	return 0;
} 
