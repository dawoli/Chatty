#include <bits/stdc++.h>
using namespace std;
int check[]={
-1    ,-1    ,1     ,7    ,4    ,2    ,6     ,8     ,10    ,18    ,
22    ,20    ,28    ,68   ,88   ,108  ,188   ,200   ,208   ,288   ,
688   ,888};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		cin>>n;
		n-=1;
		int x=n/7+1;
		int y=n%7;
		if(n<21){
			ans = check[n+1];
		}else{
			ans = check[15+y]*pow(10,x-3);
			for(int i=x-4;i>=0;i--){
				ans+=pow(10,i)*8;
			}
		}
		cout<<ans<<endl;
	}
}
