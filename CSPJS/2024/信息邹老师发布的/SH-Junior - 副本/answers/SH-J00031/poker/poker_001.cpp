#include<cstdio>
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n, a, b, s=52;
	char t, u;
	bool f[4][13]={0};
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf(" %c%c", &t, &u);
		if(t=='D') a=0;
		else if(t=='C') a=1;
		else if(t=='H') a=2;
		else if(t=='S') a=3;
		if(u=='A') b=0;
		else if(u>='2'&&u<='9') b=u-49;
		else if(u=='T') b=9;
		else if(u=='J') b=10;
		else if(u=='Q') b=11;
		else if(u=='K') b=12;
		if(!f[a][b]){
			f[a][b]=1;
			s--;
		}
	}
	printf("%d", s);
	return 0;
} 
