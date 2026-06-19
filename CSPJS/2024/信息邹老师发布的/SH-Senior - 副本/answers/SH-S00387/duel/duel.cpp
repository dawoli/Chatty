#include<bits/stdc++.h>
using namespace std;
long long n,j[100005],ans;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>j[i];
		q.push(j[i]);
	}
	ans=n;
	sort(j+1,j+1+n);
	
	for(int i=1;i<=n;i++){
		if(q.empty()) break;
		while(q.top()<=j[i]){
			q.pop();
			if(q.empty()) break;
		}
		if(q.empty()) break;
		ans--;
		q.pop();
	}
	cout<<ans<<endl;
	return 0;
}//郑源植（鬼）知道对不对 
