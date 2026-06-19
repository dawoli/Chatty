#include<cstdio>
int n,res;
bool st[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		char str[4];
		scanf("%s",str);
		int tp,w;
		if(str[0]=='D')
			tp=1;
		else if(str[0]=='C')
			tp=2;
		else if(str[0]=='H')
			tp=3;
		else tp=4;
		if(str[1]=='A')
			w=1;
		else if(str[1]=='T')
			w=10;
		else if(str[1]=='J')
			w=11;
		else if(str[1]=='Q')
			w=12;
		else if(str[1]=='K')
			w=13;
		else w=str[1]-'0';
		st[tp][w]=true;
	}
	for(int tp=1;tp<=4;tp++)
		for(int w=1;w<=13;w++)
			if(!st[tp][w])
				res++;
	printf("%d\n",res);
	return 0;
}
