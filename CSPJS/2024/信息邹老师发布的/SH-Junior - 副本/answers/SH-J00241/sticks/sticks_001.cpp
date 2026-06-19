#include <bits/stdc++.h>
using namespace std;
int c[11]={6,2,5,5,4,5,6,3,7,6},n,T,ans,st[8][2]={{0,0},{10,1},{1,0},{22,1},{20,1},{2,0},{6,0}};
int main(){
	freopen("sticks.in","r",stdin);freopen("sticks.out","w",stdout);
	cin >>T;
	while(T--)
	{
		cin >> n;
		if(n%7==0)
		{
			for(int i=0;i<n/7;i++) cout << '8';
			cout <<endl;
		}
		else
		{
			if(n==1){cout << -1;cout <<endl;continue;}
			if(n==2){cout << 1;cout <<endl;continue;}
			if(n==3){cout << 7;cout <<endl;continue;}
			if(n==4){cout << 4;cout <<endl;continue;}
			if(n==5){cout << 2;cout <<endl;continue;}
			if(n==6){cout << 6;cout <<endl;continue;}
			else{cout << st[n%7][0];
			for(int i=0;i<n/7-st[n%7][1];i++) cout << '8';
			}
			cout <<endl;
		}
	}
	return 0;
} 
