#include <bits/stdc++.h>
using namespace std;

string s;
priority_queue <char> q;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			q.push(s[i]);
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
