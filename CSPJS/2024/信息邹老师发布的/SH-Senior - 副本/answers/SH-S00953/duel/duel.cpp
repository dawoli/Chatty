#include<bits/stdc++.h>
using namespace std;

int n, a[100010], t, k, st=1, ans;
bool used[100010];

bool cmp(int a, int b) {
	if(a==0) a=10000000;
	if(b==0) b=10000000;
	return a<b;
}

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	memset(used, 0, sizeof(used));
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	
	for(int i=1;i<=n;i++) {
		st=max(i+1, st);
		while(a[st]<=a[i]||used[st]) st++;
		if(st>n) break;
		used[st]=1;
		ans--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
