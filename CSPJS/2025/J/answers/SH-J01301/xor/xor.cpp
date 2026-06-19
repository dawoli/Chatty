#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int num=0;
	if(k==0) {
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if(a[i]==k) cnt++;
		}
	}
	else {
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if(a[i]==k) cnt++,num=0;
			else if(num^a[i]==k) {
				cnt++;
				num=0;
			}
			else {
				if(num==0) num=a[i];
				else num^=a[i];
			}
		}
	}
	cout<<cnt;
	return 0;
}
