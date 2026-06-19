#include<bits/stdc++.h>
using namespace std;
int a[101][101],s[101],n,m,k;
int main(){
	freopen("seat.in","R",stdin);
	freopen("seat.out","W",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
	}
	k=s[1];
	sort(s+1,s+n*m+1);
	int top=n*m;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=s[top];
				top--;
				if(a[i][j]==k){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				a[i][j]=s[top];
				top--;
				if(a[i][j]==k){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
	}
	return 0;
}
