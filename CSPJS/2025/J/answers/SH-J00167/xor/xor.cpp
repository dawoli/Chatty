#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[255],n,k,t[255],c=1,rec1[255],rec2[255],ans;
	cin>>n>>k;
	if(k==0)cout<<1;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<n; i++) {
		for(int j=i; j<=n; j++) {
			t[c]=a[i]^a[j];
			rec1[c]=i;
			rec2[c]=j;
			c++;
		}
	}
	for(int i=1; i<n; i++) {
		for(int j=i; j<=n; j++) {
			if(t[i]==t[j]==k||(rec2[i]<rec1[i]||rec1[i]>rec2[j]))ans++;
			}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

