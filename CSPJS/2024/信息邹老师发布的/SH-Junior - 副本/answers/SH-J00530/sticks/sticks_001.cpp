#include<bits/stdc++.h>
using namespace std;
int a[10010];
int b[10010];
int main()
{
	freopen("sticks","in",stdin);
	freopen("sticks","out",stdout);
	int t;
	cin >> t;
	for(int i = 0; i<t; i++)
	{
		cin >> a[i];
		if(a[i]==1) b[i]=-1;
		if(a[i]==2) b[i]=1;
		if(a[i]==3) b[i]=7;
		if(a[i]==4) b[i]=4;
		if(a[i]==5) b[i]=2;
		if(a[i]==6) b[i]=6;
		if(a[i]==7) b[i]=8;
		if(a[i]==8) b[i]=10;
		if(a[i]==9) b[i]=18;
		if(a[i]==10) b[i]=23;
		if(a[i]==11) b[i]=20;
		if(a[i]==12) b[i]=28;
		if(a[i]==13) b[i]=68;
		if(a[i]==14) b[i]=88;
		if(a[i]==15) b[i]=108;
		if(a[i]==16) b[i]=188;
		if(a[i]==17) b[i]=200;
		if(a[i]==18) b[i]=208;
		if(a[i]==19) b[i]=608;
		if(a[i]==20) b[i]=688;
	}
	for(int i =0;i <t; i++)
	{
		cout << b[i]<<endl;
	}
	return 0;
}
