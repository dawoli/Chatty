#include<bits/stdc++.h>
#define int long long
using namespace std;

int dabiao[30]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,80,88,108,188,200,208,288,808,888,1088,1888,2008,2088};
int ys[30]={88,108,188,200,208,288,808};

int T,n;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=20){cout<<dabiao[n]<<"\n";continue;}
		if(n%7==0){for(int i=1;i<=n/7;i++){cout<<8;}cout<<"\n";continue;}//特判情况A
		if(n%7==1){cout<<10;for(int i=1;i<=n/7-1;i++){cout<<8;}cout<<"\n";continue;}//特判情况B
		
		//cerr<<n<<"%7="<<n%7<<"\n";
		cout<<ys[n%7];
		for(int i=1;i<=n/7-2;i++)cout<<8;
		cout<<"\n";
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
