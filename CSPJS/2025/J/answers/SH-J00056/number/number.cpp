#include<bits/stdc++.h>
using namespace std;
char gs_s[1000005];
int gi_s[1000005];
bool px(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>gs_s;
	int lens=strlen(gs_s);
	int li_cnt=0;
	for(int li_i=0;li_i<lens;li_i++)
	{
		if(gs_s[li_i]>='0'&&gs_s[li_i]<='9')
		{
			li_cnt++;
			gi_s[li_cnt]=gs_s[li_i]-'0';
		}
	}
	sort(gi_s+1,gi_s+1+li_cnt,px);
	for(int li_i=1;li_i<=li_cnt;li_i++)
	{
		cout<<gi_s[li_i];
	}
	return 0;
}
