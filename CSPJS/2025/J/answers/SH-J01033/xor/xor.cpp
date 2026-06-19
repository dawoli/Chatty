#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500050];
	scanf("%d%d",&n,&k);
	int cnt=0,h;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
		{
			h=a[l];
			for(int i=l+1;i<=r;i++) h=(h^a[i]);
			if(h==k){
				cnt++;l=r;break;
			}
		}
		printf("%d",cnt);
	return 0;
}
