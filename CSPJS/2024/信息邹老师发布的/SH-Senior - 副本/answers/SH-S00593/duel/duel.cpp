#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int r[N];
queue<int> s;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	s.push(r[1]);
	for(int i=2;i<=n;i++){
		if(r[i]>s.front()) s.pop(),s.push(r[i]);
		else s.push(r[i]);
	}
	int ans=0;
	while(!s.empty()) s.pop(),ans++;
	cout<<ans;
	return 0;
}

