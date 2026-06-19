#include<bits/stdc++.h>
using namespace std;

short y[1000000];
string x;
int n;

int main()
{
	ifstream in_("number.in");
	ofstream out_("number.out");
	in_>>x;
	for(int i=0;x[i];i++)
	{
		if(x[i]>='0'&&x[i]<='9')
		{
			y[n]=x[i]-'0';
			n++;
		}
	}
	sort(y,y+n); 
	for(int i=n-1;i>=0;i--)
	{
		out_<<y[i];
	}
	return 0;
}

