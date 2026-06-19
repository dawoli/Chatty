#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int la=0;
	for(int i=2;i<=n;i++)
		if(a[i]>a[la+1])
			la++;
	printf("%d\n",n-la);
	return 0;
}
