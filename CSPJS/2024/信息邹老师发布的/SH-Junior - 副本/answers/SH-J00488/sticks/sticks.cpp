#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			n/=7;
			while(n--){
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
		if(n%7==1){
			if(n==1) cout<<-1<<"\n";
			else{
				n/=7;
				n-=1;
				cout<<10;
				while(n--){
					cout<<8;
				}
				cout<<"\n";
				continue;			
			}

		}
		if(n%7==2){
			cout<<1;
			n/=7;
			while(n--){
				cout<<8;
			}
			cout<<"\n";
			continue;			
		}
		if(n%7==3){
			if(n==3) cout<<7<<"\n";
			else{
				cout<<22;
				n-=10;
				n/=7;
				while(n--){
					cout<<8;
				}
				cout<<"\n";
				continue;			
			}
		}
		if(n%7==4){
			if(n==4)cout<<4<<"\n";
			else{
				cout<<20;
				n-=11;
				n/=7;
				while(n--){
					cout<<8;
				}
				cout<<"\n";
				continue;
			}
		}
		if(n%7==5){
			cout<<2;
			n/=7;
			while(n--){
				cout<<8;
			}
			cout<<"\n";
			continue;		
		}
		if(n%7==6){
			cout<<6;
			n/=7;
			while(n--){
				cout<<8;
			}
			cout<<"\n";
			continue;	
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

