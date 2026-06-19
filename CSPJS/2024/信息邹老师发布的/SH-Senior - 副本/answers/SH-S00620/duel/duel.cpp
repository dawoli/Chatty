#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans=0;
	vector<int> l;
	stack<int> st;
	cin>>n;
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		l.push_back(s);
	}
	sort(l.begin(),l.end());
	st.push(l[0]);
	for(int i=1;i<n;i++){
		if(!st.empty() && st.top()<l[i]){
			st.pop();
			ans++;
		}
		else if(!st.empty() && st.top()==l[i]){
			st.push(l[i]);
		}
		else{
			st.push(l[i]);
		}
	}
	cout<<(n-ans)<<endl;
	return 0;
}
