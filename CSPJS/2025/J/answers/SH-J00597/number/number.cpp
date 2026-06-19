#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int n,cnt[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s),n=strlen(s);
	for(int w=0;w<n;w++)if(s[w]>='0'&&s[w]<='9')cnt[s[w]-'0']++;
	for(int w=9;w>=0;w--)for(int x=1;x<=cnt[w];x++)printf("%d",w);
	return 0;
}
