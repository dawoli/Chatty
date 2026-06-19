#include<iostream>
#include<cstring>
using namespace std;

int T,n,a[100005],tag[100005];
long long int sum;
int find(int t)
{
	for (int i = t-1;i >= 1;i--)
	{
		if(a[i] == a[t] && tag[a[i]] == 0 && tag[a[t]] == 0)
		{
			tag[a[i]] = tag[a[t]] = 1;
			sum = sum + a[t];
		}
	}
	return sum;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	
	for (int i = 1;i <= T;i++)
	{
		sum = 0;
		memset(a,0,100005);
		memset(tag,0,100005);
		cin >> n;
		for (int j = 1;j <= n;j++)
		{
			cin >> a[j];
			find(j);
		}
		cout << sum << endl;
	}
	
	return 0;
}
