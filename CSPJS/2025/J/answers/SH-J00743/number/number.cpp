#include <iostream>
#include <queue>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	priority_queue<int> que;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9') que.push(s[i]-'0');
	}
	while(!que.empty()){
		cout << que.top();
		que.pop();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
