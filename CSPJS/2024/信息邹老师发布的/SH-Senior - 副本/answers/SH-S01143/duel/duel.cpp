#include<bits/stdc++.h> 
using namespace std;
const int N=100010;
int n,a[N],i,j,num;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	i=1;
	j=upper_bound(a+1,a+n+1,a[i])-a;
	num=n;
	while(j<=n){
		while(a[j]<=a[i]&&j<=n)
			j++;
		if(j>n)
			break;
		if(a[j]>a[i]){
			i++;
			j++;
			num--;
		}
	}
	printf("%d\n",num);
	return 0;
}
