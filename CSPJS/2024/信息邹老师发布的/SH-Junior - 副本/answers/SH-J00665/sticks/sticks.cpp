#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	long long t,a[100],b[20];
	char c[100001]={'s'};
	b[0]=6;
	b[1]=2;
	b[2]=5;
	b[3]=5;
	b[4]=4;
	b[5]=5;
	b[6]=6;
	b[7]=3;
	b[8]=7;
	b[9]=6;
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>a[i];
		int x=0;
		if(a[i]==1){
			cout<<-1<<endl;
		}
		else if(a[i]==2){
			cout<<1<<endl;
		}
		else if(a[i]==3){
			cout<<7<<endl;
		}
		else if(a[i]==4){
			cout<<4<<endl;
		}
		else if(a[i]==5){
			cout<<2<<endl;
		}
		else if(a[i]==6){
			cout<<6<<endl;
		}
		else if(a[i]==7){
			cout<<8<<endl;
		}
		else if(a[i]%7==0){
			for(int j=1;j<=a[i]/7;++j){
				cout<<'8';
			}
			cout<<endl;
		}
		else if(a[i]>7){
			while(a[i]-7>=6){
				c[x]='8';
				++x;
				a[i]-=7;
			}
			if((a[i]-1)%7==0){
				c[x]='0';
				c[x+1]='1';
			}
			else if((a[i]-3)%7==0){
				c[x]='0';
				c[x+1]='4';
			}
			else if((a[i]-2)%7==0){
				c[x]='1';
				c[x+1]='8';
			}
			else if((a[i]-4)%7==0){
				c[x]='0';
				c[x+1]='2';
			}
			else if((a[i]-5)%7==0){
				c[x]='0';
				c[x+1]='0';
			}
			else if((a[i]-6)%7==0){
				c[x]='0';
				c[x+1]='8';
			}
			sort(c,c+x+2);
			if(c[0]=='0'){
				for(int j=0;j<=x+1;++j){
					if(c[j]!='0'){
						swap(c[j],c[0]);
						break; 
					}
				}
			}
			for(int j=0;j<=x+1;++j){
				if(c[j]!='s')
					cout<<c[j];
			}
			cout<<endl;
		}
	}
	return 0; 
} 
