#include<iostream>
#include<queue>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	priority_queue<int>q;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int t=s[i]-'0';
			q.push(t);
		}
	}
	while(q.size()){
		cout<<q.top();
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
