#include<bits/stdc++.h>
using namespace std;
char p[101][2];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;scanf("%d",&n);
	int d=0;
	for(int i=1;i<=n;i++){
		char c[2];scanf("%s",&c);
		bool f=true;
		for(int j=1;j<=d;j++)
			if(c[0]==p[j][0] && c[1]==p[j][1]){
				f=false;
				break;
			}
		if(f){
			++d;
			p[d][0]=c[0],p[d][1]=c[1];
		}
	}
	printf("%d\n",52-d);
	return 0;
} 
