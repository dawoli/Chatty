#include<bits/stdc++.h>
using namespace std;
int T,n,a[7]={-1,-1,1,7,4,2,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		int x=n%7;
		int y=n/7;
		if(y==0){
			cout<<a[x]<<endl;
			continue;
		}
		if(x==0){
			for(int j=1;j<=y;j++)cout<<8;
		}else if(x==2||x==5||x==6){
			cout<<a[x];
			for(int j=1;j<=y;j++)cout<<8;
		}else if(x==1||x==4){
			cout<<a[x+1]<<0;
			for(int j=1;j<=y-1;j++)cout<<8;
		}else{
			if(y==1){
				cout<<26;	
			}else{
				cout<<a[x+2]<<0<<0;
				for(int j=1;j<=y-2;j++)cout<<8;
			}
		}
		cout<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
