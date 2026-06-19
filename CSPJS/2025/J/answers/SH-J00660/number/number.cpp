#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(stdin,"r",number.in);
	freopen(stdout,"w",number.out);
	char a[100002]={0};
	gets(a);
	int k1=0,k2=0,k3=0,k4=0,k5=0,k6=0,k7=0,k8=0,k9=0,k0=0;
	for(int j=0;j<=100000;j++)
	{
		if(a[j]=='0')
			k0++;
		if(a[j]=='1')
			k1++;
		if(a[j]=='2')
			k2++;
		if(a[j]=='3')
			k3++;
		if(a[j]=='4')
			k4++;
		if(a[j]=='5')
			k5++;
		if(a[j]=='6')
			k6++;
		if(a[j]=='7')
			k7++;
		if(a[j]=='8')
			k8++;
		if(a[j]=='9')
			k9++;
	}
	for(int i=1;i<=k9;i++)
		printf("9");
	for(int i=1;i<=k8;i++)
		printf("8");
	for(int i=1;i<=k7;i++)
		printf("7");
	for(int i=1;i<=k6;i++)
		printf("6");
	for(int i=1;i<=k5;i++)
		printf("5");
	for(int i=1;i<=k4;i++)
		printf("4");
	for(int i=1;i<=k3;i++)
		printf("3");
	for(int i=1;i<=k2;i++)
		printf("2");
	for(int i=1;i<=k1;i++)
		printf("1");
	for(int i=1;i<=k0;i++)
		printf("0");
	return 0;
}
