#include<bits/stdc++.h>
using namespace std;
int T,n;
int d,yv;
int cost[15]={6,2,5,5,4,5,6,3,7,6};
int mc[15]={-1,-1,1,7,4,2,0,8};
int y1,y2;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=7){
			if(n==6)
				cout<<6<<"\n";
			else cout<<mc[n]<<"\n";
			continue;
		}
		d=n/7;
		yv=n%7;
		if(yv==0){
			for(int i=1;i<=d;i++)
				cout<<8;
			cout<<"\n";
			continue;
		}
		
		if(yv!=0 && yv!=1){
			if(yv==6)
				y1=6;
			else y1=mc[yv];
		}else y1=-1;
		
		y2=1e9;
		if(d>=1){
			yv+=7,d--;
			for(int i=2;i<=yv/2;i++){
				if(yv-i>=7)continue;
				int a,b;
				a=mc[i],b=mc[yv-i];
				if(a>b)swap(a,b);
				if(a==0 && b==0)
					y2=min(y2,60);
				else if(a==0)
					y2=min(y2,b*10+a);
				else y2=min(y2,a*10+b);
			}
		}else y2=-1;
		
		if(y1==-1 && y2==-1){
			cout<<-1<<"\n";
			continue;
		}else if(y1==-1){
			cout<<y2;
		}else if(y2==-1){
			cout<<y1;
		}else {
			cout<<min(y1*10+8,y2);
		}
		
		for(int i=1;i<=d;i++){
			cout<<8;
		}cout<<"\n";
	}
	return 0;
}
//1 13
