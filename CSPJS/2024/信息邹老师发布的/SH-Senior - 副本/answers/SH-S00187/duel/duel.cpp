#include<bits/stdc++.h>
using namespace std;
int v[100009];
int n;
int cnt;
int main()
{
	freopen("duel.in","r",stdin);  //just do it
	freopen("duel.out","w",stdout);//impossible is nothing
	cin >> n;                      //trust yourself
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v,v+n);
	int i,j;
	for(i = 0; i < n; i++)
	{
		if(v[i]>v[0])break;
	}
	for(j = 0; i < n && j < n;)
	{
		if(v[i]>v[j] && i != n)
		{
			++i,++j;
		}
		else 
		{
			++i;
		}
//		cout << i << " " << j << " " << cnt << endl;
	}
	cnt = n-j;
	cout << cnt;
	return 0;
}
// this is an orange problem in luogu probably
