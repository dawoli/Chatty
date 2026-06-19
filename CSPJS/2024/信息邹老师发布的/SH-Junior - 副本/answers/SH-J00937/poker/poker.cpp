#include<bits\stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int l;
	int count=52;
	string m[53];
	cin>>l;
	count-=l;
    for (int i=0;i<=l;i++)
    {
    	getline(cin,m[i]);
	}
	sort(m,m+l);
	for (int i=1;i<l;i++)
	{
		if (m[i]==m[i-1])
		{
			count++;
		}
	}
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
