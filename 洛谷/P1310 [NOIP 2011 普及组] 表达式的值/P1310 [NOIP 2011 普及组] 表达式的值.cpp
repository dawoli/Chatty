#include<bits/stdc++.h>
using namespace std;
int l,a_s;
string s,r;
queue<char> q;
pair<int,vector<pair<bool,bool>>> exam(char _o ,bool exp)
{
	if(_o=='+')
	{
		if(exp==1)
		{
			int x=3;
			vector<pair<bool,bool>> a;
			a.push_back(make_pair(0,1));
			a.push_back(make_pair(1,0));
			a.push_back(make_pair(1,1));
			return make_pair(x,a);
		}
		if(exp==0)
		{
			int x=1;
			vector<pair<bool,bool>> a;
			a.push_back(make_pair(0,0));
			return make_pair(x,a);
		}
	}
	if(_o=='*')
	{
		if(exp==0)
		{
			int x=3;
			vector<pair<bool,bool>> a;
			a.push_back(make_pair(0,0));
			a.push_back(make_pair(0,1));
			a.push_back(make_pair(1,0));
			return make_pair(x,a);
		}
		if(exp==1)
		{
			int x=1;
			vector<pair<bool,bool>> a;
			a.push_back(make_pair(1,1));
			return make_pair(x,a);
		}
	}
}
void dfs(bool exp)
{
	if(q.front()=='_')
	{
		q.pop();
		dfs(exp);
	}
	if(q.front()=='+'||q.front()=='*')
	{
		
	}
}
int main()
{
	cin>>l>>s;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='*')
		{
			if(s[i+1]=='+')r.append("(_*_)");
			else if(s[i+1]=='*')r.append("(_*_)");
			else if(s[i+1]=='(')r.append("_*(");
		}
		else if(s[i]=='+')
		{
			if(s[i+1]=='*')r.append("_+");
			else if(s[i+1]=='+')r.append("(_+_)");
			else if(s[i+1]=='(')r.append("_+(");
		}
		else if(s[i]=='(')r.append("(");
		else if(s[i]==')')r.append(")");
	}
}
