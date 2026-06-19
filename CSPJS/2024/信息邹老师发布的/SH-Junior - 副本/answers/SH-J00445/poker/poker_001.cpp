#include<bits/stdc++.h>
#define N 14
using namespace std;
int n,num,a[55];
char str1,str2;
int ans=52;
int k=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	ans-=n;
	for(int i=1;i<=n;i++){
		scanf("%c%c",&str1,&str2);
		if(str2>='2' && str2<='9') a[i]=(str1-'A'+1)+(str2-'0');
		else a[i]=(str1-'A'+1)*100+(str2-'A'+1);
		for(int j=1;j<i;j++){
			if(a[i]==a[j]){
				ans++;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
