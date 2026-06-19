#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n%7==0){
			for(int j=1;j<=n/7;j++)cout<<8;
			cout<<endl;
		}
		else if(n%7==1 && n!=1){
			cout<<10;
			for(int j=1;j<=(n-8)/7;j++)cout<<8;
			cout<<endl;
		}
		else if(n<7){
			if(n==2)cout<<1<<endl;
			else if(n==3)cout<<7<<endl;
			else if(n==4)cout<<4<<endl;
			else if(n==5)cout<<5<<endl;
			else if(n==6)cout<<6<<endl;
			else cout<<-1<<endl;
		}
		else{
			int minn=1000001;
			int cnt=0;
			for(int j=1;j<=9;j++){
				for(int x=0;x<=9;x++){
					for(int o=0;o<=9;o++){
						if(o==0)cnt+=6;
						if(o==1)cnt+=2;
						if(o==2)cnt+=5;
						if(o==3)cnt+=5;
						if(o==4)cnt+=4;
						if(o==5)cnt+=5;
						if(o==6)cnt+=6;
						if(o==7)cnt+=3;
						if(o==8)cnt+=7;
						if(o==9)cnt+=6;
						if(x==0)cnt+=6;
						if(x==1)cnt+=2;
						if(x==2)cnt+=5;
						if(x==3)cnt+=5;
						if(x==4)cnt+=4;
						if(x==5)cnt+=5;
						if(x==6)cnt+=6;
						if(x==7)cnt+=3;
						if(x==8)cnt+=7;
						if(x==9)cnt+=6;
						if(j==1)cnt+=2;
						if(j==2)cnt+=5;
						if(j==3)cnt+=5;
						if(j==4)cnt+=4;
						if(j==5)cnt+=5;
						if(j==6)cnt+=6;
						if(j==7)cnt+=3;
						if(j==8)cnt+=7;
						if(j==9)cnt+=6;
						if(cnt==n){
							if(100*j+10*x+o<minn)minn=100*j+10*x+o;
						}
						cnt=0;
					}
				}
			}
			if(minn==1000001)cout<<-1<<endl;
			else cout<<minn<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
