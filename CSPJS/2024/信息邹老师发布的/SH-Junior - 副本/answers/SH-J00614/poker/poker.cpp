#include<bits/stdc++.h>
using namespace std;
int n,poker[6][15];
char in[5];
int mpp[200];
void init(){
	for(int i='1';i<='9';i++)mpp[i]=i-'0';
	mpp['D']=1;
	mpp['C']=2;
	mpp['H']=3;
	mpp['S']=4;
	mpp['A']=1;
	mpp['T']=10;
	mpp['J']=11;
	mpp['Q']=12;
	mpp['K']=13;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	init();int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&in);
		poker[mpp[in[0]]][mpp[in[1]]]=1;	
	}for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(!poker[i][j])
				ans++;
	printf("%d\n",ans);
	return 0;
}
