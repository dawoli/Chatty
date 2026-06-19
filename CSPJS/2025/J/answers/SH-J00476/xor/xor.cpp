#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[n],ans=0,tot=-1;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]==k || tot==k)
		{
			ans++;
			tot=-1;
		}
		else if(tot==-1)tot=a[i];
		else tot=tot^a[i];
	}
	if(tot==k)ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
