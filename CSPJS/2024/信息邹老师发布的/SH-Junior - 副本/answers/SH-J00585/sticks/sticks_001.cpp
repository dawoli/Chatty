#include<bits/stdc++.h>
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n<=1){
			cout<<-1<<endl;
			continue;
		}
		if(n<=7){
			for(int i=1;i<=8;i++){
				if(stick[i]==n){
					cout<<i<<endl;
					break;
				}
			}
			continue;
		}
		int cnt=0;
		while(n>14){
			cnt++;n-=7;
		}
		bool flag=0;
		for(int i=1;i<=8;i++){
			if((stick[i]+6)==n){
				flag=1;cout<<i<<0;
				break; 
			}
			bool flag1=0;
			for(int j=1;j<=9;j++){
				if((stick[j]+stick[i])==n){
					flag=1;flag1=1;
					cout<<i<<j;
					break; 
				}
			}
			if(flag1)break;
		}
		if(!flag){
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<=cnt;i++)cout<<8;
		cout<<endl;
	}
	return 0;
} 
