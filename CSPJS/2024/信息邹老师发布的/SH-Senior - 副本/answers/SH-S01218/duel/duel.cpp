#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdin);
	int n,r[100000],max=-1000000,sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
            if(r[i]==r[j])
            {
                sum++;
            }
		}
		if(max<=sum)
        {
            max=sum;
        }
	}
	cout<<max;
	return 0;
}
