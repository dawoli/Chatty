#include <bits/stdc++.h>
using namespace std;
int a[52];
char p[4]={'D','C','H','S'},o[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	fill(a,a+52,1);
	string b;
	int n,count=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b;
		for(int j=0;j<4;j++)
		{
			if(b[0]==p[j])
			{
				for(int k=0;k<13;k++)
				{
					if(b[1]==o[k])
					{
						a[j*13+k]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<52;i++)
	{
		count+=a[i];
	}
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
