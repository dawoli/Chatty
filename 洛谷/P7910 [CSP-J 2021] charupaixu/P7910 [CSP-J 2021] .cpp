#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
	int n,q,c,x,v;
	vector<int> a,b;
	void Soar()
	{
		cin>>n>>q;
		a.resize(n+1);
		b.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		while(q--)
		{
			cin>>c>>x;
			if(c==1)
			{
				cin>>v;
				a[x]=v;
			}
			else if(c==2)
			{
				swap(a,b);
				for (int i = 1; i <= n; i++)
					for (int j = i; j >= 2; j--)
						if (a[j] < a[j-1])swap(a[j],a[j-1]);
				a=b;
			}
		}
	}
}
int main()
{
	Soaring_Wings::Soar();
	return 0;
}
