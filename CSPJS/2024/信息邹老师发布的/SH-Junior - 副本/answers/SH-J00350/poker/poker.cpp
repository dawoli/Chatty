#include <cstdio>
int d[13];
int c[13];
int h[13];
int s[13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	char ipt[2];
	int tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",ipt);
		if(ipt[1]=='T') tmp=10;
		else if(ipt[1]=='A') tmp=1;
		else if(ipt[1]=='J') tmp=11;
		else if(ipt[1]=='Q') tmp=12;
		else if(ipt[1]=='K') tmp=13;
		else tmp=int(ipt[1])-48;
		if(ipt[0]=='D') d[tmp-1]=1;
		else if(ipt[0]=='C') c[tmp-1]=1;
		else if(ipt[0]=='H') h[tmp-1]=1;
		else s[tmp-1]=1;
	}
	int ans=0;
	for(int i=0;i<13;i++){
		if(d[i]!=1) ans++;
		if(c[i]!=1) ans++;
		if(h[i]!=1) ans++;
		if(s[i]!=1) ans++;
	}
	printf("%d",ans);
	return 0;
}
