#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==0||n==1)
			cout<<-1<<"\n";
		else if(n==2)
			cout<<1<<"\n"; 
		else if(n==3)
			cout<<7<<"\n";
		else if(n==4)
			cout<<4<<"\n";
		else if(n==5)
			cout<<2<<"\n";
		else if(n==6)
			cout<<6<<"\n";
		else{
			int cnt=n/7;
			int sum=n%7;
			if(sum==0){
				for(int i=1;i<=cnt;i++)
					cout<<8;
				cout<<"\n";
			}
			else if(sum==1){
				cout<<10;
				for(int i=1;i<cnt;i++)
					cout<<8;
				cout<<"\n";	
			}
			else if(sum==2){
				cout<<18;
				for(int i=1;i<cnt;i++)
					cout<<8;
				cout<<"\n";	
			}
			else if(sum==3){
				cout<<23;
				for(int i=1;i<cnt;i++)
					cout<<8;
				cout<<"\n";	
			}
			else if(sum==4){
				cout<<20;
				for(int i=1;i<cnt;i++)
					cout<<8;
				cout<<"\n";	
			}
			else if(sum==5){
				cout<<28;
				for(int i=1;i<cnt;i++)
					cout<<8;
				cout<<"\n";	
			}
			else if(sum==6){
				cout<<68;
				for(int i=1;i<cnt;i++)
					cout<<8;
				cout<<"\n";	
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
