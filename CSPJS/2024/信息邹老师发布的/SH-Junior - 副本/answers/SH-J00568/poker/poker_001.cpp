#include<bits/stdc++.h>
using namespace std;
struct poker
{
	char hua,dian;
};
poker a[55];
bool cmp(poker c,poker b)
{
	if(c.dian==b.dian)
		return c.hua<b.hua;
	return c.dian<b.dian;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,sum=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].hua>>a[i].dian;
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
		if(a[i].dian!=a[i-1].dian or a[i].hua!=a[i-1].hua)
			sum++;
	cout<<52-sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
