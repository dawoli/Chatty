#include<bits/stdc++.h>
using namespace std;
queue<int>b;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;cin>>n;int a[n];for(int i=0;i<n;i++)cin>>a[i];sort(a,a+n);
	for(int i=0;i<n;i++){b.push(a[i]);if(b.front()<b.back())b.pop();}
	cout<<b.size();
	return 0;
}
