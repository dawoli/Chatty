#include<bits/stdc++.h>
using namespace std;
int a,b,n,ans;
bool m[5][15];
char c1,c2;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	c1=getchar();
	for(int i=1;i<=n;i++){
		c1=getchar();
		c2=getchar();
		if(c1=='D'){
			a=1;
		}
		else if(c1=='C'){
			a=2;
		}
		else if(c1=='H'){
			a=3;
		}
		else{
			a=4;
		}
		if(c2>='0'&&c2<='9'){
			b=c2-'0';
		}
		else if(c2=='A'){
			b=1;
		}
		else if(c2=='T'){
			b=10;
		}
		else if(c2=='J'){
			b=11;
		}
		else if(c2=='Q'){
			b=12;
		}
		else{
			b=13;
		}
		m[a][b]=1;
		c1=getchar();
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!m[i][j])ans++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
