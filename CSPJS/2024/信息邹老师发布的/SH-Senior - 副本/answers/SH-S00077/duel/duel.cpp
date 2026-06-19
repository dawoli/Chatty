#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+5;

int n,r[N];
int tot[N];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		tot[r[i]]++;
		maxn=max(maxn,r[i]);
	}
	sort(tot+1,tot+1+maxn,cmp);
	
	cout<<tot[1]<<"\n";
	
	return 0;
}

/*
10
136 136 136 2417 136 136 2417 136 136 136

136 136 136 136 136 136 136 136 2417 2417


1 1 3 3 4 4 4 

1 2 3 4 
1 2 3 4
1 2 3 4
1 3 4
1 3 4
4
 
*/
