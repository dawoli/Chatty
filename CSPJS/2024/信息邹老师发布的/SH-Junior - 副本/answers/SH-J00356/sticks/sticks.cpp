#include<bits/stdc++.h>
using namespace std;
//            
char a[7]={2,2,5,5,5,6,7};
//
string b[150000];
//
string c[150000];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	c[1]=b[1]="-1";
	c[2]=b[2]="1";
	c[3]=b[3]="7";
	c[4]=b[4]="4";
	c[5]=b[5]="2";
	c[6]="0";
	b[6]="6";
	c[7]=b[7]="8";
	int t,s=7;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n>s){
			for(int i=s+1;i<=n;i++){
				int x=(i-1)%7;
				if(x<=1) x=2;
				else if(x<=4) x=5;
				else if(x<=5) x=6;
				else x=7;
				b[i]=b[x]+c[i-a[(i-1)%7]];
				c[i]=c[x]+c[i-a[(i-1)%7]];
			}
			s=n;
		}
		cout<<b[n]<<endl;
	}
	return 0;
}
