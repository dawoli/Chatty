#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n>=7&&n%7==0){
			for(int i=0;i<n/7;i++){
				cout<<'8';
			}
			cout<<endl;
		}else if(n>=7&&n%7==1){
			if(n==8){
				cout<<10<<endl;
			}else{
				for(int i=1;i<(n-1)/7;i++){
					cout<<'8';
				}
				cout<<'0'<<'1'<<endl;
			}
		}else if(n==2) cout<<1<<endl;
		else if(n==4) cout<<4<<endl;
		else if(n==5) cout<<2<<endl;
		else if(n==6) cout<<6<<endl;
		else cout<<-1<<endl; 
	}
	return 0;
}
