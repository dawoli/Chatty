#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	  cin>>n;
	  if(n<=7||n==10){
	  	if(n==1) cout<<"-1";
	  	if(n==2) cout<<"1";
	  	if(n==3) cout<<"7";
	  	if(n==4) cout<<"4";
	  	if(n==5) cout<<"2";
	  	if(n==6) cout<<"6";
	  	if(n==7) cout<<"8";
	  	if(n==10) cout<<"22";
	  	cout<<endl;
	  }
	  else{
		if(n%7==1) cout<<"10",n-=8;
		if(n%7==2) cout<<"18",n-=9;
		if(n%7==3) cout<<"200",n-=17;
		if(n%7==4) cout<<"20",n-=11;
		if(n%7==5) cout<<"28",n-=12;
		if(n%7==6) cout<<"68",n-=13;
		for(int i=1;i<=n/7;i++) cout<<"8";
		cout<<endl;
	  }
	}
	return 0;
}
