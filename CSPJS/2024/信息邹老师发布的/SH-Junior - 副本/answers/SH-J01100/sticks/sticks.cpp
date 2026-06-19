#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int a[10],n,t,p[107];
int shu(int x){
	int ret=0;
	while(x)
		ret+=a[x%10],x/=10;
	return ret;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	a[0]=6;a[1]=2;a[2]=5;a[3]=5;a[4]=4;a[5]=5;a[6]=6;a[7]=3;a[8]=7;a[9]=6;
	for(int i=1;i<=1000;i++)
		if(!p[shu(i)])
			p[shu(i)]=i;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			puts("-1");
			continue;
		}
		int t=0;
		while(n>21)
			n-=7,t++;
		cout<<p[n];
		while(t--)
			cout<<8;
		putchar('\n');
	}
} 
/*
5
1
2
3
6
18

*/
