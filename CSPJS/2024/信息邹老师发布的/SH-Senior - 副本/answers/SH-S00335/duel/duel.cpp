#include<bits/stdc++.h>
using namespace std;
int n,a[100009],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int top=1;
	for(int i=1;i<=n;i++){
		if (a[top]<a[i]){
			ans++;
			top++;
		}
	}
	cout<<n-top+1;
	return 0;
}
