#include<bits/stdc++.h>
using namespace std;
string a;
long long sz[100];
string ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long s = a.length();
	long long sum = 0;
	for(int i = 0;i < s;i++)
	{
		if(a[i] == '0') sz[0]++;
		else if(a[i] == '1') sz[1]++;
		else if(a[i] == '2') sz[2]++;
		else if(a[i] == '3') sz[3]++;
		else if(a[i] == '4') sz[4]++;
		else if(a[i] == '5') sz[5]++;
		else if(a[i] == '6') sz[6]++;
		else if(a[i] == '7') sz[7]++;
		else if(a[i] == '8') sz[8]++;
		else if(a[i] == '9') sz[9]++;
		else sz[11]++;
	}
	for(int i = 0;i <= 9;i++) sum += sz[i];
	if(sum == sz[0]) cout<<"0"<<endl;
	else
	{
		for(int i = 9;i >= 0;i--)
		{
			for(int j = 1;j <= sz[i];j++)
			{
				if(i == 0) ans += '0';
				else if(i == 1) ans += '1';
				else if(i == 2) ans += '2';
				else if(i == 3) ans += '3';
				else if(i == 4) ans += '4';
				else if(i == 5) ans += '5';
				else if(i == 6) ans += '6';
				else if(i == 7) ans += '7';
				else if(i == 8) ans += '8';
				else if(i == 9) ans += '9';
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
