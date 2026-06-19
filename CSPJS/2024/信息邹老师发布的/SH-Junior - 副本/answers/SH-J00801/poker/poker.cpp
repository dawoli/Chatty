#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,ct;
bool a[4][13];
char p1[4]={'D','C','H','S'},p2[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char s[2];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	while(n--) {
		scanf("%s",&s);
		for(int i=0;i<4;i++)
			for(int j=0;j<13;j++)
				if(s[0]==p1[i] && s[1]==p2[j]) a[i][j]=true;
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(!a[i][j]) ct++;
	printf("%d\n",ct);
	fclose(stdin),fclose(stdout);
	return 0;
}
