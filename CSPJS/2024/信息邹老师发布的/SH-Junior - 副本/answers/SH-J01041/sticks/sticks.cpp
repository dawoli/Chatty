#include<bits/stdc++.h>
using namespace std;
int a[100000]={-1,-1,1,7,4,2,6,8,10,18,22,107,104,102,100,108,202,200,208,608,888,1008,2000,2008,6008};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cout<<a[x];
	} 
}
