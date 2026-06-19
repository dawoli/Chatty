#include<bits/stdc++.h>
using namespace std;
int k[20]={6,2,5,5,4,5,6,3,7,6};
int a[100010];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1)	cout<<"-1"<<"\n";
		if(a[i]%7==0){
			for(int j=1;j<=a[i]/7;j++){
				cout<<8;
			}
		}
		else	if(a[i]%7==1){
					int t=a[i]/7+1,p;
					int s=a[i]-5*(t-1);
					if(a[i]%t==0){
						for(int j=0;j<=9;j++){
							if(a[i]/t==k[j])	p=j;
						}
						for(int j=1;j<=t;j++)	cout<<p;
					}
					else{
						if(s>=2){
							for(int j=1;j<=t-1;j++)	cout<<2;
							for(int j=0;j<=9;j++){
								if(s==k[j])	cout<<j;
							}
						}
					}
		}
	}
	return 0;
}
