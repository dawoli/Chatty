#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	priority_queue<int>q;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')q.push(s[i]-'0');
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
