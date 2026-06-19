#include<bits/stdc++.h>
using namespace std;
string a[10002]; 
int main()
{
	freopen("poker.in","r",stdin); 
	freopen("poker.out","w",stdout);
	int n,cnt;
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<i;j++)
		{
			if(a[i]==a[j]) 
			{
				cnt--;
				break;
			}
			
		}
	} 
	cout<<52-cnt<<endl;
	 
	return 0;
 } 
