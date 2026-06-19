#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
long long a[10]={0,-1,1,7,4,2,6,8},b[10]={88,10,18,22,20,28,68};
int n,t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n<=7)cout<<a[n];
		else{
			long long x=(n-1)/7-1,y=n%7;
			cout<<b[y];
			for(int j=1;j<=x;j++)cout<<8;
		}
		cout<<"\n";
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
