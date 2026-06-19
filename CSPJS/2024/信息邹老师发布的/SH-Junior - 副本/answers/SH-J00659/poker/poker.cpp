#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5][20];//1d 2c 3h 4s 
string s;
int f(int x){
	if(s[1]>='2' && s[1]<='9')a[x][s[1]-48]++;
	if(s[1]=='A')a[x][1]++;
	if(s[1]=='T')a[x][10]++;
	if(s[1]=='J')a[x][11]++;
	if(s[1]=='Q')a[x][12]++;
	if(s[1]=='K')a[x][13]++;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D')f(1);
		if(s[0]=='C')f(2);
		if(s[0]=='H')f(3);
		if(s[0]=='S')f(4);
	}
	for(int i=1;i<=4;i++)
	  for(int j=1;j<=13;j++)
	    if(!a[i][j])ans++;
	printf("%d",ans);
	return 0;
}
