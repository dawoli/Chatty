#include<bits/stdc++.h>
using namespace std;
const int N=1009;
string ans[N]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","68","88","108","188","200","208","288","688","888","1088","1888","2008","2088","2888","6888","8888","10888","18888"};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		int n;
		cin>>n;
		if(n==1)cout<<-1<<endl;
		else if(n<=20)cout<<ans[n]<<endl;
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}else if(n%7==1){
			cout<<10;
			n-=8;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}else if(n%7==2){
			cout<<1;
			n-=2;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}else if(n%7==3){
			cout<<200;
			n-=17;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}else if(n%7==4){
			cout<<20;
			n-=11;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}else if(n%7==5){
			cout<<2;
			n-=5;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}else{
			cout<<6;
			n-=6;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
	}
	// "1088","1888","2008","2088","2888","6888","8888"
	return 0;
}
