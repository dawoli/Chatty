#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100100;
struct R{
	int rr;
	int num;
	int f;
};
R nr[N];
int n,r[N],nn,answer,nex[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	sort(r+1,r+1+n);
	r[0]=r[1]-1;
	for(int i=1;i<=n;i++){
		if(r[i]!=r[i-1]){
			nn++;
			nr[nn].rr=r[i];
			nr[nn].num=1;
			nr[nn].f=1;
			nex[nn]=nn+1;
		}
		else{
			nr[nn].num++;
			nr[nn].f++;
		}
	}
	nex[0]=1;
	for(int i=2;i<=nn;i++){
		int now=nex[0],pre=0;
		while(now<i){
			if(nr[now].num>0){
				if(nr[now].num<=nr[i].f){
					nr[i].f-=nr[now].num;
					nr[now].num=0;
					nex[pre]=nex[now];
				}
				else{
					nr[now].num-=nr[i].f;
					nr[i].f=0;
				}
			}
			pre=now;
			now=nex[now];
		}
	}
	for(int i=1;i<=nn;i++){
		answer+=nr[i].num;
	}
	printf("%d\n",answer);
	fclose(stdin);fclose(stdout);
	return 0;
}
