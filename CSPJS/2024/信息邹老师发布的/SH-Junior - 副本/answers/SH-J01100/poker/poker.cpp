#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n;
string x;
int cun[57],ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		int a=0,b=0;
		if(x[0]=='D')
			b=0;
		if(x[0]=='C')
			b=1;
		if(x[0]=='H')
			b=2;
		if(x[0]=='S')
			b=3;
		if(isdigit(x[1]))
			a=x[1]-'0';
		if(x[1]=='A')
			a=1;
		if(x[1]=='T')
			a=10;
		if(x[1]=='J')
			a=11;
		if(x[1]=='Q')
			a=12;
		if(x[1]=='K')
			a=13;
		cun[(a-1)*4+b]=1;
	}
	for(int i=0;i<52;i++)
		ans+=cun[i]^1;
	cout<<ans<<endl;
} 
/*

*/
