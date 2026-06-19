#include<bits/stdc++.h>
using namespace std;
int t;
int hui(int n){
	if(n<2){
		return -1;
	}if(n==2){
		return 1;
	}if(n==3){
		return 7;
	}if(n==4){
		return 4;
	}if(n==5){
		return 2;
	}if(n==6){
		return 0;
	}if(n==7){
		return 8;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,w,y,d=9999;
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}if(n==2){
			cout<<1<<endl;
			continue;
		}if(n==3){
			cout<<7<<endl;
			continue;
		}if(n==4){
			cout<<4<<endl;
			continue;
		}if(n==5){
			cout<<2<<endl;
			continue;
		}if(n==6){
			cout<<6<<endl;
			continue;
		}if(n==7){
			cout<<8<<endl;
			continue;
		}if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
		w=n/7;
		y=n%7;
		int h1,h2;
		for(int i=2;i<=(7+y)/2;i++){
			int j=7+y-i;
			if(i>7 || j>7){
				continue;
			}
			int hh,hi=hui(i),hj=hui(j);
			if(hi!=0 ||hj!=0){
				if(hi==0){
					hh=hj*10;
				}else if(hj==0){
					hh=hi*10;
				}else{
					hh=min(hi*10+hj,hj*10+hi);
				}
				if(d>hh){
					h1=hh/10;
					h2=hh%10;
				}
				d=min(d,hh);
			}
		}
		cout<<h1<<h2;
		for(int i=1;i<=w-1;i++){
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
