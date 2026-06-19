#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	priority_queue<int,vector<int>,greater<int> >q;
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int>v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
		q.push(v[i]);
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<n;i++){
		if(q.top()<v[i]){
			ans++;
			q.pop();
		}
	}
	cout<<n-ans<<endl;
}
