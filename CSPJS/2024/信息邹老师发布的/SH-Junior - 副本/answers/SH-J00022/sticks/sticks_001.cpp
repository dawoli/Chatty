#include<bits/stdc++.h>
using namespace std;
string a[1000000];
char b[7]={'1','1','2','2','2','6','8'};
int t[7]={2,2,5,5,5,6,7};
char s[8]={' ',' ','1','7','4','2','6','8'};
int main()
{
//freopen("explore.in","r",stdin);
//freopen("explore.out","w",stdout);
	a[0]="10";
	a[1]="18";
	a[2]="22";
	a[3]="20";
	a[4]="28";
	a[5]="68";
	a[6]="88";

for(int i=7;i<100000;i++)
{
	a[i]=b[(i-1)%7]+a[i-t[(i-1)%7]];
	if(a[i][2]=='6')
	{
		a[i][2]='0';
	}
}
int h,j;
cin>>h;
for(int i=0;i<h;i++)
{
	cin>>j;
	cout<<i;
	if(j<8)
	{
		if(j<2)
		{
			cout<<-1;
		}
		else
		{
		cout<<s[j];			
		}

	}
	else
	{
		cout<<a[j-8]<<endl;	
	}

}
return 0;
}
