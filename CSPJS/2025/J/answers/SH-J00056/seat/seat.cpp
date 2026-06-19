#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int li_c_r;
	cin>>li_c_r;
	int li_c;
	int li_mc=1;
	for(int li_i=2;li_i<=n*m;li_i++)
	{
		cin>>li_c;
		if(li_c>li_c_r)
		{
			li_mc++;
		}
	}
	int li_ans_f,li_ans_s;
	if(li_mc/n*n<li_mc)
	{
		li_ans_f=li_mc/n+1;
	}
	else
	{
		li_ans_f=li_mc/n;
	}
	if(li_ans_f%2==1)
	{
		li_ans_s=(li_mc-1)%n+1;
	}
	else
	{
		li_ans_s=n-(li_mc-1)%n;
	}
	cout<<li_ans_f<<" "<<li_ans_s;
	return 0;
}
