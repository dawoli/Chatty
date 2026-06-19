#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,a[N];
queue<int> q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(q.empty()){
			q.push(a[i]);
		}
		else{
			if(q.front()<a[i])
				q.pop();
			q.push(a[i]);
		}
	}
	cout<<q.size();
} 
