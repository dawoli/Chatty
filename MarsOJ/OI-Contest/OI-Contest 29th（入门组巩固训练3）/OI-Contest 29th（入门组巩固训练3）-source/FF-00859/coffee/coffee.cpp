#include<bits/stdc++.h>
using namespace std;
int T,a[10],n,m,b[10];
long long sum;
string s;
int main(){
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=5;i++)
			for(int j=1;j<=8;j++){
				cin>>s;
				if(s[0]=='m') a[i]++;
			}
		cin>>n>>m;
		int x=n/7,y=m; 
		for(int i=1;i<=7;i++)
			b[i]+=x;
		for(int i=1;i<=n%7;i++){
			b[y]++;y++;
			if(y>7)	y-=7;
		}sum=0;
		for(int i=1;i<=7;i++)
			sum+=b[i]*a[i];
		cout<<sum<<"\n"; 
	}
} 
