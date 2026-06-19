#include<bits/stdc++.h>
using namespace std;
string a;
priority_queue<char,vector<char> >q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a;
	for(int i=0;i<a.size();i++){
		if (a[i]>='0'&&a[i]<='9'){
			q.push(a[i]);
		} 
	}
	while(!q.empty()){
		cout << q.top();
		q.pop();
	}
	return 0;
} 
