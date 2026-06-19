#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		else if(n>30){
			if(n%7==0){
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
			}
			else if(n%7==1){
				cout<<10;
				for(int i=1;i<=(n-8)/7;i++) cout<<8;
				cout<<endl;
			}
			else if(n%7==2){
				cout<<18;
				for(int i=1;i<=(n-9)/7;i++) cout<<8;
				cout<<endl;
			}
			else if(n%7==3){
				cout<<200;
				for(int i=1;i<=(n-17)/7;i++) cout<<8;
				cout<<endl;
			}
			else if(n%7==4){
				cout<<20;
				for(int i=1;i<=(n-11)/7;i++) cout<<8;
				cout<<endl;
			}
			else if(n%7==5){
				cout<<28;
				for(int i=1;i<=(n-12)/7;i++) cout<<8;
				cout<<endl;
			}
			else if(n%7==6){
				cout<<68;
				for(int i=1;i<=(n-13)/7;i++) cout<<8;
				cout<<endl;
			}
		}
		else{
			for(int i=1; ;i++){
				int k=i,cnt=0;
				while(k!=0){
					cnt+=num[k%10];
					k/=10;
				}
				if(cnt==n){
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
