#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,r,a;
bool flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&r);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a);
		if(a>r){
			if(!flag&&x==n||flag&&x==1){
				y++;
				flag=!flag;
			}
			else{
				x+=flag?-1:1;
			}
		}
	}
	printf("%d %d",y,x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
