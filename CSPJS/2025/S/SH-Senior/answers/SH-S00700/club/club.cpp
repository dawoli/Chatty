#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Node {
	int x,y,z,id;
} a[N];
bool cmpx(Node x, Node y)
{
	return x.x > y.x;
}
bool cmpy(Node x, Node y)
{
	return x.y > y.y;
}
bool cmpz(Node x, Node y)
{
	return x.z > y.z;
}
void start()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].id = i;
	}
	int flag = 0;
	char f;
	sort(a + 1, a + n + 1, cmpx);
	if (a[1].x == 0)
	{
		flag++;
	}
	else
	{
		f = 'x';
	}
	sort(a + 1, a + n + 1, cmpy);
	if (a[1].y == 0)
	{
		flag++; 
	}
	else
	{
		f = 'y';
	}
	sort(a + 1, a + n + 1, cmpz);
	if (a[1].z == 0)
	{
		flag++; 
	}
	else
	{
		f = 'z';
	}
	if (flag == 3)
	{
		cout<<"0";
	}
	else if (flag == 2)
	{
		int sum = 0;
		if (f == 'x') sort(a + 1, a + n + 1, cmpx);
		else if (f == 'y') sort(a + 1, a + n + 1, cmpy);
		else sort(a + 1, a + n + 1, cmpz);
		for (int i = 1; i <= n / 2; i++)
		{
			if (f == 'x')
			{
				sum += a[i].x; 
			}
			else if (f == 'y')
			{
				sum += a[i].y;
			}
			else
			{
				sum += a[i].z;
			}
		}
		cout<<sum;
	}
	else if (flag == 1)
	{
		
	}
	else
	{
		
	}
	return ;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	int t;
	cin>>t;
	while (t--)
	{
		start();
	}
}
