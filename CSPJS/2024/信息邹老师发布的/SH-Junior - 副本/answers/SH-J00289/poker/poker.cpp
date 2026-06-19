#include<bits/stdc++.h>
using namespace std;
int n,b,cnt;
bool d[15],c[15],h[15],s[15];
char a,bb,ss[5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ss);
		a=ss[0],bb=ss[1];
		if(bb=='A') b=1;
		else if(bb=='T') b=10;
		else if(bb=='J') b=11;
		else if(bb=='Q') b=12;
		else if(bb=='K') b=13;
		else b=bb-'0';
		if(a=='D'&&d[b]==0) d[b]=1,cnt++;
		else if(a=='C'&&c[b]==0) c[b]=1,cnt++;
		else if(a=='H'&&h[b]==0) h[b]=1,cnt++;
		else if(a=='S'&&s[b]==0) s[b]=1,cnt++;
	}
	printf("%d",52-cnt);
	return 0;
}
