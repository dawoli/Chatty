#include <bits/stdc++.h>
using namespace std;
int t,n,x,f[]={1,5,2,10,3,10,1,4,0,10},a[100010];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		for(x=0;n>x*7;x++);
		int c=x*7-n;
		if(x==1){
			for(int i=1;i<=9;i++)
				if(c==f[i]){
					cout<<i<<endl;
					break;
				}
		}
		else{
			for(int i=1;i<=9;i++)
				if(c>=f[i]&&c-f[i]!=6){
					c-=f[i],a[1]=i;
					break;
				}
			for(int i=2;i<x;i++)
				for(int j=0;j<=9;j++)
					if(c>=f[j]&&c-f[j]!=6){
						c-=f[j],a[i]=j;
						break;
					}
			for(int i=0;i<=9;i++)
				if(c==f[i]){
					a[x]=i;
					break;
				}
			for(int i=1;i<=x;i++)
				cout<<a[i];
			puts("");
		}
	}
	return 0;
} 
