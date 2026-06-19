#include<bits/stdc++.h>
using namespace std;
int n,a[10]={6,2,5,5,4,5,6,3,7,6},T;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		int k8=0;
		cin>>n;
		if(n==1){cout<<-1<<endl;continue;}
		if(n==4){cout<<4<<endl;continue;}
		if(n==3){cout<<7<<endl;continue;}
		if(n==6){cout<<6;cout<<endl;continue;}
		k8=n/7;
		n%=7;
		if(n==0){
		    for(int i=1;i<=k8;i++)cout<<8;
		    cout<<endl;
		    continue;
		}
		else if(n==1){
			cout<<10;
		    for(int i=1;i<=k8-1;i++)cout<<8;
		    cout<<endl;
		    continue;
		}
		else if(n==2){
			cout<<1;
		    for(int i=1;i<=k8;i++)cout<<8;
		    cout<<endl;
		    continue;
		}
		else if(n==3){
			cout<<40;
		    for(int i=1;i<=k8-1;i++)cout<<8;
		    cout<<endl;
		    continue;
		}
		else if(n==4){
			cout<<20;
		    for(int i=1;i<=k8-1;i++)cout<<8;
		    cout<<endl;
		    continue;
		}
		else if(n==5){
			cout<<2;
		    for(int i=1;i<=k8;i++)cout<<8;
		    cout<<endl;
		    continue;
		}
		else if(n==6){
		    cout<<80;
		    for(int i=1;i<=k8-1;i++)cout<<8;
		    cout<<endl; 
		    continue;
		}
		else cout<<-1<<endl;
	} 
	return 0;
} 
