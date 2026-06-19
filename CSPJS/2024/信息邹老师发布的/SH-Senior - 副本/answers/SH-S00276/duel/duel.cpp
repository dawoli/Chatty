#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100010], ans=0;
bool book[100010];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int i=1,j=2;
	while(i<=n&&j<=n){
		if(a[i]<a[j]){
			ans++;
			i++,j++;
		}
		else{
			j++;
		}
	}
	printf("%d",n-ans);
	return 0;
}
