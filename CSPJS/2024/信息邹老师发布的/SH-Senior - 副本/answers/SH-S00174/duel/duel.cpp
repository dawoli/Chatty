#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[100010];
int v[100010];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1, a+1+n);
	int cnt = n;
	while(cnt>0){
		int flag = 0;
		for(int i=1; i<=n; i++){
			if(v[i]==0){
				flag = a[i];
				v[i] = 1;
				cnt--;
				break;
			}
		}
		for(int i=1; i<=n; i++){
			if(a[i]>flag&&v[i]==0){
				flag = a[i];
				v[i] = 1;
				cnt--;
			}
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
