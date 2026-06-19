#include<bits/stdc++.h>
using namespace std;
struct node{
	int v, l;
} a[200001][3];
int b[3][200001];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k, n, r, s, top[3];
	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		s=0, top[0]=0, top[1]=0, top[2]=0, r=-1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d", &a[i][0].v, &a[i][1].v, &a[i][2].v);
			a[i][0].l=0, a[i][1].l=1, a[i][2].l=2;
			sort(a[i],a[i]+3,cmp);
			s+=a[i][0].v;
			b[a[i][0].l][++top[a[i][0].l]]=a[i][0].v-a[i][1].v;
		}
		for(int i=0;i<3;i++){
			if(top[i]*2>n){
				r=i;
				break;
			}
		}
		if(r==-1){
			printf("%d\n", s);
			continue;
		}
		sort(b[r],b[r]+top[r]);
		for(int i=1;i<=top[r]-n/2;i++){
			s-=b[r][i];
		}
		printf("%d\n", s);
	}
	return 0;
}
