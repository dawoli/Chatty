#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker","in",stdin);
	freopen("poker","out",stdout);
	string a[60];
	int cnt = 0;
	bool flag = true;
	int n;
	cin >> n;
	for(int i = 0; i< n; i++)
	{
		cin >> a[i];
		for(int j = 0 ;j < n;j ++)
		{
			if(a[i]==a[j])
			{
				flag=false;
			}
			else
			{
				flag = true;
			}
		}
		if(flag==true)
		{
			cnt +=1;
		}
	}
	if(cnt == 0)
	{
		cout << 52-n;
	}
	else 
	{
		cout <<52-cnt;
	}
	return 0;
}
