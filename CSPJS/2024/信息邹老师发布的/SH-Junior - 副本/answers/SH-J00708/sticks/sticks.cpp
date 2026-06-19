#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		int n;
		cin>>n;
		if(n<=1){
			cout<<-1<<"\n";
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++)
				cout<<8;
			cout<<"\n";
			continue;
		}				
		int len=(n+6)/7;
		int maxi=(7-n%7)%7;//除了前maxi位以外，其他位必定是8
		n-=max(0,(len-maxi)*7);
		if(maxi<6){
			for(int i=1;i<pow(10,maxi+1);i++){
				int cnt=0;
				int j=i;
				while(j){
					cnt+=num[j%10];
					j/=10;
				}
				if(cnt==n){
					cout<<i;
					for(int j=1;j<=max(0,len-maxi);j++)
						cout<<8;
					cout<<"\n";
					break;
				}
			}			
		}else{
			if(n%6==0){
				cout<<6;
				n-=6;
			}
			else if(n%6==1){
				cout<<12;
				n-=7;
			}
			else if(n%6==2){
				cout<<1;
			}
			else if(n%6==3){
				cout<<7;
			}
			else if(n%6==4){
				cout<<4;
			}
			else if(n%6==5){
				cout<<2;
			}
			for(int i=1;i<=n/6;i++)
				cout<<0;
			for(int i=1;i<=len-maxi;i++){
				cout<<8;
			}
			cout<<"\n";	
		}
	}
	return 0;
}
