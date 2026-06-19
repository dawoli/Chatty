#include<bits/stdc++.h>
using namespace std;
long long s;
long long cnt;
void answer(long long x,int n){
	cnt=0;
	int l=(n/7)-1;
	cnt=x*pow(10,l);
	for(int i=0;i<=l-1;i++)
	  cnt=cnt+8*pow(10,i);
}
void minnum(int k){
	if(k<=14){
		if(k==1)
		  s=-1;
		else if(k==2)
		  s=1;
		else if(k==3)
		  s=7;
		else if(k==4)
		  s=4;
		else if(k==5)
		  s=2;
		else if(k==6)
		  s=6;
		else if(k==7)
		  s=8;
		else if(k==8)
		  s=10;
		else if(k==9)
		  s=18;
		else if(k==10)
		  s=22;
		else if(k==11)
		  s=20;
		else if(k==12)
		  s=28;
		else if(k==13)
		  s=80;
		else if(k==14)
		  s=88;
	}
	else{
		if(k%7==0)
		  s=8;
		else if(k%7==1)
		  s=10;
		else if(k%7==2)
		  s=18;
		else if(k%7==3)
		  s=22;
		else if(k%7==4)
		  s=20;
		else if(k%7==5)
		  s=28;
		else
		  s=80;
		answer(s,k);
	}	
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
	  cin>>n;
	  minnum(n);
	  cout<<cnt<<endl;
    }
    return 0;
} 
