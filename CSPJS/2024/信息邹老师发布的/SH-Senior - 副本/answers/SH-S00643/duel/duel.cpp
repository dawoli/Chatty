#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],t[100005],ans=0;
struct node{
	long long val,sum;
	bool operator < (const node x)const{
		return val>x.val;
	} 
};
priority_queue<node> q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(t[a[i]]){
			t[a[i]]++;
			a[i]=0;
			continue;
		}
		t[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]) q.push({a[i],t[a[i]]});
	}
	long long sz=0;
	sz+=q.top().sum;
	q.pop();
	while(!q.empty()){
		if(sz<=q.top().sum){
			ans+=sz;
			sz=q.top().sum;
		}
		else{
			ans+=q.top().sum;
		}
		q.pop();
	}
	cout<<n-ans<<endl;
	return 0;
}
