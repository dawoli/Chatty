#include<bits/stdc++.h>
using namespace std;
int n,a[500],b[500],ans=52;
char s[5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%s",&s);
		if(a[s[0]]==0||a[s[1]]==0){
			ans--;
			a[s[0]]=1;a[s[1]]=1;
		}
	}
	printf("%d",ans);
	return 0;
}
