#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int p=0;p<t;p++){
		int n;
		cin>>n;
		if(n==1) cout<<-1<<endl;
		else if(n==2) cout<<1<<endl;
		else if(n==3) cout<<7<<endl;
		else if(n==4) cout<<4<<endl;
		else if(n==5) cout<<2<<endl;
		else if(n==6) cout<<6<<endl;
		else if(n==7) cout<<8<<endl;
		else if(n==8) cout<<10<<endl;
		else{
			int cnt=n/7+1,num;
			if(n%7==0){
				for(int i=0;i<cnt-1;i++){
					cout<<8;
				}
				cout<<endl;
				continue;
			}
			num=cnt*7-n;
			if(num==1){
				cout<<80;
				cnt-=2;
			}
			else if(num==2){
				cout<<2;
				cnt-=1;
			}
			else if(num==3){
				cout<<20;
				cnt-=2;
			}
			else if(num==4){
				if(cnt>=3){
					cout<<200;
					cnt-=3;
				}
				else{
					cout<<22;
					cnt-=2;
				}
			}
			else if(num==5){
				cout<<1;
				cnt-=1;
			}
			else if(num==6){
				cout<<10;
				cnt-=2;
			}
			for(int i=0;i<cnt;i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
} 
