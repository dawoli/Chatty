#include <bits/stdc++.h>
using namespace std;

// 判断s是否为GBE（合法括号序列）
bool isGBE(const string &s)
{
	stack<char> stk;
	for(char c:s)
	{
		if(c=='('||c=='[') stk.push(c);
		else
		{
			if(stk.empty()) return false;
			if((c==')'&&stk.top()!='(')||(c==']'&&stk.top()!='[')) return false;
			stk.pop();
		}
	}
	return stk.empty();
}

// 暴力递归，返回最少插入次数
int dfs(string s,int depth=0)
{
	if(isGBE(s)) return 0;
	//if(depth>10) return 100; // 防止爆栈，实际不会用到
	int res=100;
	for(int i=0; i<=(int)s.size(); ++i)
	{
		for(char c:{'(',')','[',']'})
		{
			string t=s;
			t.insert(t.begin()+i,c);
			res=min(res,1+dfs(t,depth+1));
		}
	}
	return res;
}

int main()
{
	string s;
	cin>>s;
	cout<<dfs(s)<<endl;
	return 0;
}