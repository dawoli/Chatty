#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(char x:s){
		int c=x;
		if(48<=c&&c<=57){
			q.push(c-48);
		}
	}
	while(!q.empty()){
		int a=q.top();
		cout<<a;
		q.pop();
	}
	return 0;
} 
