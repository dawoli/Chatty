#include<bits/stdc++.h>
using namespace std;
int a[55];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,j=1,cnt=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	while(j<=t){
		cnt=0;
		if(a[i]==1){
			cout<<-1;
			continue;
		}
		for(int i=1;i<100;i++){
			int a=i/10,b=i%10;
			if(a==1)cnt+=2;
			if(a==2)cnt+=5;
			if(a==3)cnt+=5;
			if(a==4)cnt+=4;
			if(a==5)cnt+=5;
			if(a==6)cnt+=6;
			if(a==7)cnt+=3;
			if(a==8)cnt+=7;
			if(a==9)cnt+=6;
			if(b==1)cnt+=2;
			if(b==2)cnt+=5;
			if(b==3)cnt+=5;
			if(b==4)cnt+=4;
			if(b==5)cnt+=5;
			if(b==6)cnt+=6;
			if(b==7)cnt+=3;
			if(b==8)cnt+=7;
			if(b==9)cnt+=6;
			if(cnt==a[i]){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
