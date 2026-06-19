#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[1000010];
	int bj=1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0' and a[i]<='9')
			b[bj++]=a[i]-'0';
	}
	sort(b+1,b+bj,cmp);
	for(int i=1;i<bj;i++)
	{
		cout<<b[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
