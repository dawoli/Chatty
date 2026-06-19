#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool pk[5][15];
char c[5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		if(c[2]>='2'&&c[2]<='9'){
			if(c[1]=='D'){
				pk[1][c[2]-'0']=1;
			}
			else if(c[1]=='C'){
				pk[2][c[2]-'0']=1;
			}
			else if(c[1]=='H'){
				pk[3][c[2]-'0']=1;
			}
			else{
				pk[4][c[2]-'0']=1;
			}
		}
		else if(c[2]=='A'){
			if(c[1]=='D'){
				pk[1][1]=1;
			}
			else if(c[1]=='C'){
				pk[2][1]=1;
			}
			else if(c[1]=='H'){
				pk[3][1]=1;
			}
			else{
				pk[4][1]=1;
			}
		}
		else if(c[2]=='T'){
			if(c[1]=='D'){
				pk[1][10]=1;
			}
			else if(c[1]=='C'){
				pk[2][10]=1;
			}
			else if(c[1]=='H'){
				pk[3][10]=1;
			}
			else{
				pk[4][10]=1;
			}
		}
		else if(c[2]=='J'){
			if(c[1]=='D'){
				pk[1][11]=1;
			}
			else if(c[1]=='C'){
				pk[2][11]=1;
			}
			else if(c[1]=='H'){
				pk[3][11]=1;
			}
			else{
				pk[4][11]=1;
			}
		}
		else if(c[2]=='Q'){
			if(c[1]=='D'){
				pk[1][12]=1;
			}
			else if(c[1]=='C'){
				pk[2][12]=1;
			}
			else if(c[1]=='H'){
				pk[3][12]=1;
			}
			else{
				pk[4][12]=1;
			}
		}
		else if(c[2]=='K'){
			if(c[1]=='D'){
				pk[1][13]=1;
			}
			else if(c[1]=='C'){
				pk[2][13]=1;
			}
			else if(c[1]=='H'){
				pk[3][13]=1;
			}
			else{
				pk[4][13]=1;
			}
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(pk[i][j]==0){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
