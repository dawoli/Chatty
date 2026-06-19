#include <bits/stdc++.h>
using namespace std;
int n,a[110000] ,tong[110000],Top,End,cnt;// ´ð°¸Îªn-cnt-1
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	sort(a+1,a+1+n,cmp);
	Top=1,End=2;
	while(End<=n)
	{
		while(a[Top]<a[End]&&End<=n) 
		{
			Top++;End++;
			cnt++;
		}
		End++;
	}
	cout<<n-cnt;
	return 0;
 } 
