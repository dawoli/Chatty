#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100001][4];
int club[4][100001];
int lost[100001];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i = 1;i <= t;i++){
		ans=0;
		scanf("%d",&n);
		for(int j = 1;j <= n;j++)
		   scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
		int l[4];
		l[1]=l[2]=l[3]=0;
		for(int j = 1;j <= n;j++){
			int g=-1;
			int m;
			for(int k = 1;k <= 3;k++)
			    if(a[j][k]>g){
			    	g=a[j][k];
			    	m=k;
				}
		    l[m]++;
		    club[m][l[m]]=j;
		    ans+=g;
		}
		if(l[1]>n/2){
			for(int j = 1;j <= l[1];j++){
				sort(a[club[1][j]]+1,a[club[1][j]]+4);
				lost[j]=a[club[1][j]][3]-a[club[1][j]][2];
			}
			sort(lost+1,lost+l[1]+1);
			for(int j = 1;j <= l[1]-n/2;j++)
			    ans-=lost[j];
		}
		if(l[2]>n/2){
			for(int j = 1;j <= l[2];j++){
				sort(a[club[2][j]]+1,a[club[2][j]]+4);
				lost[j]=a[club[2][j]][3]-a[club[2][j]][2];
			}
			sort(lost+1,lost+l[2]+1);
			for(int j = 1;j <= l[2]-n/2;j++)
			    ans-=lost[j];			
		}
		if(l[3]>n/2){
			for(int j = 1;j <= l[3];j++){
				sort(a[club[3][j]]+1,a[club[3][j]]+4);
				lost[j]=a[club[3][j]][3]-a[club[3][j]][2];
			}
			sort(lost+1,lost+l[3]+1);
			for(int j = 1;j <= l[3]-n/2;j++)
			    ans-=lost[j];			
		}
		printf("%d\n",ans);
	}
	return 0;
}
