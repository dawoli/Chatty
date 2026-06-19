#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans,num;
int a[N];
priority_queue<int,vector<int> ,greater<int> > q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		int m=q.top();
		if(m<a[i]){
			q.pop();
			num++;
		}
	}
	ans=n-num;
	cout<<ans;
	return 0;
}
