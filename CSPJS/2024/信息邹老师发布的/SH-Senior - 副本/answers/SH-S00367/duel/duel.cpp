#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int j=2,cnt=n;
	for(int i=1;i<=n;i++){
		while(j<=n&&a[j]==a[i])j++;
		if(j==n+1)break;
		cnt--;
		j++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

