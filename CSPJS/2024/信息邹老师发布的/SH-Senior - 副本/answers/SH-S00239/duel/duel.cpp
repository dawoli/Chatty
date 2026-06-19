#include<bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> s1;
stack<int> s2;
int n;
int a[100000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n-1,cmp);
	for(int i=0;i<n;i++)
	{
		s.push(a[i]);
	}
	int cnt1=0,cnt2=0;
	int temp1=s.top();
	while(s.top()==temp1)
	{
		s1.push(s.top());
		s.pop();
		cnt1++;
	}
	while(!s.empty())
	{
		int temp2=s.top();
		while(s.top()==temp2)
		{
			s2.push(s.top());
			s.pop();
			cnt2++;
		}
		if(cnt2>cnt1)
		{
			while(!s1.empty())
			{
				s1.pop();
				cnt1--;
			}
			while(!s2.empty())
			{
				s1.push(s2.top());
				cnt1++;
				s2.pop(); 
				cnt2--;
			} 
		}
		if(cnt2<=cnt1)
		{
			for(int i=0;i<cnt2;i++)
			{
				s1.pop();
				cnt1--;
			}
			while(!s2.empty())
			{
				s1.push(s2.top());
				cnt1++;
				s2.pop(); 
				cnt2--;
			} 
		}
	}
	cout<<cnt1;
	return 0;
}
