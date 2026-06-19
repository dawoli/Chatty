#include<bits/stdc++.h>
using namespace std;
int minuss[10]={1,5,2,2,3,2,1,4,0,1},addd[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,a,t;
		cin>>n;
		int minn;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		if(n<=7){
			for(int i=1;i<10;i++){
				if(addd[i]==n){
					cout<<i<<endl;
					break;
				}
			}
			continue;
		}
		if(n%7==0) a=n/7;
		else a=n/7+1;
		t=7-(n%7);
		bool flag=false;
		while(t>0){
			if(a==1&&t==5){
				a=0;
				break;
			}
			for(int i=0;i<10;i++){
				if(t>minuss[i]||t==minuss[i]){
					if(i==0&&flag==false) continue;
					else{
						cout<<i;
						a--;
						t-=minuss[i];
						break;
					}
				}
			} 
			flag=true;
		}
		for(int i=1;i<=a;i++) cout<<8;
		cout<<endl;
	} 
	return 0;
} 
