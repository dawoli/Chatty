#include<bits/stdc++.h>
using namespace std;
int n,maxx=-1;
int a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		int xx;
		cin >> xx;
		a[xx]++;
		maxx=max(maxx,xx);
	}
	int duo=0;
	for(int i=1;i<=maxx;i++){
		duo-=a[i];
		duo=max(duo,0);
		duo+=a[i];
	}
	cout << duo;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
