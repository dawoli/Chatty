#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
queue <int> q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=n;
	for(int i=1;i<=n;i++){
		if(q.empty()){
			q.push(a[i]);
			continue;
		}
		if(a[i]>q.front()){
			q.pop();
			cnt--;	
		}
		q.push(a[i]);
		
	}
	cout<<cnt;
}

