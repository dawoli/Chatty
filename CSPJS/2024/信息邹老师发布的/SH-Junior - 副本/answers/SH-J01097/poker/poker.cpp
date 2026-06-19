#include <iostream>
#include <cstdio>
using namespace std;
string a[55],s;
int n,ans=52;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		ans--;
		for(int j = 1;j<i;j++)
		{
			if(a[i]==a[j])
			{
				ans++; 
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
