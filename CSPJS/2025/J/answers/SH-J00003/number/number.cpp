#include<iostream>
#include<queue>
using namespace std;
string s="";
priority_queue<char> que;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			que.push(s[i]);
		}
	}
	while(!que.empty()){
		cout<<que.top();
		que.pop();
	}
	return 0;
} 
