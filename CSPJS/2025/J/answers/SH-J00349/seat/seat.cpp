#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int n,m;
struct Node
{
	int s,i;
}a[N];
bool cmp(Node a,Node b)
{
	return a.s>b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].s;
		a[i].i=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int p;
	for(int i=1;i<=n*m;i++)if(a[i].i==1)
	{
		p=i;
	}
	if(p%n==0)
	{
		cout<<p/n<<' '<<n;
	}
	else if((p/n)%2==0)
	{
		cout<<p/n+1<<' '<<p%n;
	}
	else
	{
		cout<<p/n+1<<' '<<n+1-(p%n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//#Shang4Shan3Ruo6Shui4
