#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	int a[60];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=a[i]/7;
		if(k==0){
			if(a[i]==1){
				cout<<"-1"<<endl;
			}
			if(a[i]==2){
				cout<<"1"<<endl;
			}
			if(a[i]==3){
				cout<<"7"<<endl;
			}
			if(a[i]==4){
				cout<<"4"<<endl;
			}
			if(a[i]==5){
				cout<<"5"<<endl;
			} 
			if(a[i]==6){
				cout<<"6"<<endl;
			} 
		}
		if(k>=1){
			if(a[i]%7==0){
			cout<<8*(pow(10,k)-1/9)<<endl;
		}
		if(a[i]%7==1){
			cout<<pow(10,k)+8*(pow(10,k-1)-1)/9<<endl;
		} 
		if(a[i]%7==2){
			cout<<pow(10,k)+8*(pow(10,k)-1)/9<<endl;
		}
		if(a[i]%7==3){
			if(k==1){
				cout<<"22"<<endl;
			}
			if(k!=1){
				cout<<2*pow(10,k)+8*(pow(10,k-2)-1)/9<<endl;
			} 
		} 
		if(a[i]%7==4){
			cout<<2*pow(10,k)+8*(pow(10,k-1)-1)/9<<endl;
		}
		if(a[i]%7==5){
			cout<<2*pow(10,k)+8*(pow(10,k)-1)/9<<endl;
		} 
		if(a[i]%7==6){
			cout<<6*pow(10,k)+8*(pow(10,k)-1)/9<<endl;
		}
	}
}
	return 0; 
 }
