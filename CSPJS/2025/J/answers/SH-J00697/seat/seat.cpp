#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int n,m;
int c[101];
int ans;
int cnt = 0;
bool cmp (const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*m;i++)
	    scanf("%d",&c[i]);
	ans=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int i = 1;i <= m;i++){//dijilie
	    if(i%2==1)
		   for(int j = 1;j <= n;j++){//dijihang
			   a[j][i]=c[++cnt];
		   }
		else
		    for(int j = n;j;j--)
		        a[j][i]=c[++cnt];
	}
	for(int i = 1;i <= m;i++)
	    for(int j = 1;j <= n;j++){
	    	if(a[j][i]==ans){
	    	   printf("%d %d",i,j);
	    	   return 0;
	        }
		}
	return 0;
} 
