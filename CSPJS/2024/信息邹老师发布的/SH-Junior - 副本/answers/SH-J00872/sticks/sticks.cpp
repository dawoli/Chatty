#include<bits/stdc++.h>
using namespace std;
int t,n,m,d[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		else if(n<=7){
			for(int i=1;i<=9;i++){
				if(d[i]==n){
					cout<<i<<endl;
					break;
				}
			}
			continue;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
			continue;
		}
		else if(n%7==1)cout<<10;
		else if(n%7==2)cout<<18;
		else if(n%7==3)cout<<23;
		else if(n%7==4)cout<<20;
		else if(n%7==5)cout<<28;
		else if(n%7==6)cout<<68;
		n-=8;
		for(int i=1;i<=n/7;i++)cout<<8;
		cout<<endl;
	}
	return 0;
}
