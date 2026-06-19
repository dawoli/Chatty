#include<bits/stdc++.h>
#define int long long
using namespace std;
//int a[20]={0,6,2,5,5,4,5,6,3,7,6};
//int s[20]={0,8,0,6,9,2,3,5,4,7,1};
int t,n;
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n>7){
			if(n%7==0){
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
				continue;
			}else if(n%7==1){
				int m=n/7-1;
				cout<<10;
				for(int i=1;i<=m;i++) cout<<8;
				cout<<endl;
				continue;
			}else if(n%7==3){
				int m=n/7-1;
				cout<<22;
				for(int i=1;i<=m;i++) cout<<8;
				cout<<endl;
				continue;
			}else if(n%7==2){
				int m=n/7-1;
				cout<<18;
				for(int i=1;i<=m;i++) cout<<8;
				cout<<endl;
				continue;
			}else if(n%7==4){
				int m=n/7-1;
				cout<<20;
				for(int i=1;i<=m;i++) cout<<8;
				cout<<endl;
				continue;
			}else if(n%7==5){
				int m=n/7-1;
				cout<<28;
				for(int i=1;i<=m;i++) cout<<8;
				cout<<endl;
				continue;
			}else if(n%7==6){
				int m=n/7-1;
				cout<<80;
				for(int i=1;i<=m;i++) cout<<8;
				cout<<endl;
				continue;
			}
		}else{
			if(n==1) cout<<"-1"<<endl;
			if(n==2) cout<<"1"<<endl;
			if(n==3) cout<<"7"<<endl;
			if(n==4) cout<<"4"<<endl;
			if(n==5) cout<<"2"<<endl;
			if(n==6) cout<<"6"<<endl;
			if(n==7) cout<<"8"<<endl;
		}
	}
	return 0;
}

//T3竟然是结论题,5W 5W 5W(指电功率) 
//sto  CCF  orz
