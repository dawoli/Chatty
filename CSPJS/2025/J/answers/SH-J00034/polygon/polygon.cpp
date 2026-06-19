#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3) 
	{
		cout<<0;
		return 0;	
	}
	else if(n==3)
	{
			
		
		int x,y,z;
		cin>>x>>y>>z;
		if(max(x,max(y,z))*2>=x+y+z){
			cout<<0;
		}
		else cout<<1;
	}
	else cout<<(n)*(n+1)/2-1;
	return 0;
}
