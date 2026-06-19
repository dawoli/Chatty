#include <bits/stdc++.h>
using namespace std;
int solve(vector<unsigned int> &a)
{
	if(a.size()<3)
	{
		return a[1];
	}
	unsigned int sum = a[1];
	for(int i = 2;i <= a.size();i++)
	{
		sum =  sum^a[i];
	}
	return sum;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	vector<unsigned int> a(n+1,0);
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i]; 
	}
	int j = 1;
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		j = 1;
		vector< unsigned int> b(i+1,0);
		for(j = 1;j <= i;j++)
		{
			b[j] = a[j];
			cout << b[j] <<' ';
		}
		
		cout <<  solve(b) << endl;
		if(k == solve(b))
		{
			cnt++;
			
		}
	}
	cout << cnt;
}

 
