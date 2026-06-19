#include<bits/stdc++.h>
using namespace std;
int n,ans,st[10]={6,2,5,5,4,5,6,3,7,6},s;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s<2){
			cout<<-1<<"\n";
			continue;
		}
		if(s%7==0){
			int k=s/7;
			for(int i=1;i<=k;i++)cout<<8;
			cout<<"\n";
			continue;
		}
		if(s%7==1){
			int k=(s-1)/7-1;
			cout<<10;
			for(int i=1;i<=k;i++)cout<<8;
			cout<<"\n";
			continue;
		}
		for(int j=1;j<=1e5;j++){
			int o=j,now=0;
			while(o>0){
				now+=st[o%10];
				o/=10;
			}
			if(now==s){
				cout<<j<<"\n";
				break;
			}
		}
	}
	return 0;
}
