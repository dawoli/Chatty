#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+2;
int n;
int r[maxn];
int ans;

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out","w",stdout);
	
	
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		r[x]++;
	}
	int cnt=r[1];
	for(int i=1;i<maxn;i++){
		ans=max(0, ans-r[i]);
		ans+=r[i];
	}
	printf("%d", ans);
	
	return 0;
} 
