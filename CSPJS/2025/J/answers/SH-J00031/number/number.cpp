#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string a;
int g[N];
int k,cnt;
bool cmp(int a,int b)
{
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i = 0;i < a.length(); i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			g[k++] = a[i] - 48;
			cnt++;
		}
	}
	sort(g+0,g+0+cnt,cmp);
	for(int i = 0;i < cnt; i++)cout << g[i];

   return 0;
}

