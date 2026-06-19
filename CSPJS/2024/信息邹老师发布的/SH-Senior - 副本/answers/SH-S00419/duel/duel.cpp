#include<stdio.h>
#include<algorithm>
using namespace std;

int n,rtop,ans;
int r[100005];
int chr[100005];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		r[x]+=1;
	}
	for(int i=1;i<=100000;i++){
		if(r[i]!=0){
			chr[++rtop]=r[i];
		}
	}
	for(int i=1;i<=rtop;i++){
		int	k=i;
		int atk=chr[i];
		while(k--&&atk>0){
			if(atk>=chr[k]){
				ans-=chr[k];
				atk-=chr[k];
				chr[k]=0;
			}else{
				ans-=atk;
				chr[k]-=atk;
				atk=0;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
