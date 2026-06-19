#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int l=a.length(),le=0,j=-1;
	for(int i=0;i<l;i++)
	{
		char s=a[i];
		if(s>='0'&&s<='9')
		{
			le++;
		}
	}
	int ans[le];
	for(char p:a)
	{
		if(p>='0'&&p<='9')
		{
			j++;
			ans[j]=p-'0';
		}
	}
	sort(ans,ans+le);
	for(int i=le-1;i>=0;i--)
	{
		cout << ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
