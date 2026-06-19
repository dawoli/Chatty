#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
string s,ans;
priority_queue<char>q;
bool zero;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')q.push(s[i]);
	}
	if(q.top()=='0'){
		cout<<"0\n";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	while(q.size()){
		int f=q.top();
		q.pop();
		ans+=f;
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
