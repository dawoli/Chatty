#include<bits/stdc++.h>
using namespace std;
void m70(int s){
	while(s){
		cout<<8;
		s-=7;
	}
	return;
}
void m71(int s){
	cout<<10;
	m70(s-8);
}
void m72(int s){
	cout<<18;
	m70(s-9);
}
void m73(int s){
	cout<<22;
	m70(s-10);
}
void m74(int s){
	cout<<20;
	m70(s-11);
}
void m75(int s){
	cout<<28;
	m70(s-12);
}
void m76(int s){
	cout<<68;
	m70(s-13);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		if(p<=1){
			cout<<-1;
			cout<<endl;
			continue;
		}
		if(p<7){
			if(p==2){
				cout<<1;
			}
			else if(p==3){
				cout<<7;
			}
			else if(p==4){
				cout<<4;
			}
			else if(p==5){
				cout<<2;
			}
			else if(p==6){
				cout<<6;
			}
			cout<<endl;
			continue;
		}
		if(p%7==0){
			m70(p);
			cout<<endl;
		}
		else if(p%7==1){
			m71(p);
			cout<<endl;
		}
		else if(p%7==2){
			m72(p);
			cout<<endl;
		}
		else if(p%7==3){
			m73(p);
			cout<<endl;
		}
		else if(p%7==4){
			m74(p);
			cout<<endl;
		}
		else if(p%7==5){
			m75(p);
			cout<<endl;
		}
		else if(p%7==6){
			m76(p);
			cout<<endl;
		}
	}
	return 0;
} 
