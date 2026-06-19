#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
bool a[256][256];
char s[3];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		if(!a[s[0]][s[1]])ans-=a[s[0]][s[1]]=true;
	}
	printf("%d",ans);
	return 0;
}
