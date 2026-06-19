#include <bits/stdc++.h>
#define ll long long
using namespace std;

//2 5 5 4 5 6 3 7 6 6
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int z=1;z<=T;z++){
		ll n,a=1;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n>=18){
			int d=0;
			a=0;
			d=(n/7-1);
			for(int i=1;i<=d;i++){
				a+=d*10*8;
			}
		}
		while(true){
			ll temp=a;
			ll s=0,tt;
			while(temp!=0 and s<=n){
				tt=temp%10;
				temp/=10;
				if(tt==1) s+=2;
				else if(tt==2 or tt==3 or tt==5) s+=5;
				else if(tt==4) s+=4;
				else if(tt==6 or tt==9 or tt==0) s+=6;
				else if(tt==7) s+=3;
				else if(tt==8) s+=7;
			}
			if(s==n){
				cout<<a<<endl;
				break;
			}
			a++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
