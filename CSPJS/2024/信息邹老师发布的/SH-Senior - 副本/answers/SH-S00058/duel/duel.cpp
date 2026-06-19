#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,r[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&r[i]);
	sort(r,r+n);
	for(int i=0;i<n;i++)
		if(i!=k&&r[i]>r[k])k++;
	printf("%d",n-k);
	return 0;
}
