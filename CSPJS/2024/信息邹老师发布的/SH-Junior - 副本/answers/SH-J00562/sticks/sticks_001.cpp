#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in",stdin);
	freopen("sticks.out",stdout);
	int t,num;
	cin>>t;
	while(t--){
		cin>>num;
		if(num==1){
			cout<<-1;
		}
		else{
			if(num%7==0){
				num/=7;
				for(int i=0;i<num;i++){
					cout<<8;
				}
				cout<<endl;
			}
			else{
				cout<<10;
				num-=8;
				num/=7;
				for(int i=0;i<num;i++){
					cout<<8;
				}
				cout<<endl;
			}
		}
		
	}
	
	return 0;
}

