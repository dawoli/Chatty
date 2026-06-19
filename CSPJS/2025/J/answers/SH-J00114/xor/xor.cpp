#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int cnt=0; 
int a[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int tot=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int num=0;
		for(int j=i;j>=tot;j--)
		{
			num^=a[j];
			//cout<<i<<" "<<j<<" "<<num<<endl;
			if(num==k)
			{
				cnt++;
				tot=i+1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
