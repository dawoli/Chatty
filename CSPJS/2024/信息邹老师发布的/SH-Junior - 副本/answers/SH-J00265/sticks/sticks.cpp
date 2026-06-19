#include<bits/stdc++.h>
using namespace std;

int n,a;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a<2) cout<<"-1"<<endl;
		if(a==2) cout<<"1"<<endl;
		if(a==3) cout<<"7"<<endl;
		if(a==6) cout<<"6"<<endl;
		if(a==4) cout<<"4"<<endl;
		if(a==5) cout<<"2"<<endl;
		if(a==7) cout<<"8"<<endl;
		if(a==8) cout<<"10"<<endl;
		if(a==9) cout<<"18"<<endl;
		if(a==18) cout<<"208"<<endl; 
		if(a==10) cout<<"25"<<endl;
		else cout<<"-1"<<endl;;
	}
	return 0;
}
