#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
		}
		else if(n<=7){
			for(int i=1;i<=9;i++){
				if(s[i]==n){
					cout<<i<<"\n";
					break;
				}
			}
		}
		else if(n<=14){
			int f=0;
			for(int i=1;i<=9;i++){
				for(int j=0;j<=9;j++){
					if(s[i]+s[j]==n){
						cout<<i*10+j<<"\n";
						f=1;
						break;
					}
				}
				if(f){
					break;
				}
			}
		}
		else if(n<=21){
			int f=0;
			for(int i=1;i<=9;i++){
				for(int j=0;j<=9;j++){
					for(int k=0;k<=9;k++){
						if(s[i]+s[j]+s[k]==n){
							cout<<i*100+j*10+k<<"\n";
							f=1;
							break;
						}
					}
					if(f){
						break;
					}
				}
				if(f){
					break;
				}
			}
		}
		else if(n%7==0){
			int cnt=0;
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<"\n";
		}
		else if((n-1)%7==0){
			int k=(n-1)/7-1;
			cout<<20;
			for(int i=1;i<=k;i++){
				cout<<8;
			}
			cout<<"\n";
		}
		else{
			cout<<-1<<"\n";
		}
	}
	return 0;
}
