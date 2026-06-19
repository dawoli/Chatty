#include <stdio.h>
#include <math.h>
#define ld double
#define cur cars[i]
const int maxn=1e5+10;
int T;
struct Qujian{
	ld l,r;
	bool L,R;
};
bool isin(Qujian a,int p){
	if (a.l<p&&a.r>p)return true;
	if (a.L&&a.l==p)return true;
	if (a.R&&a.r==p)return true;
	return false;
}
struct Car{
	int d,v,a;
	Qujian q;
	bool flg;
}cars[maxn];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		int n,m,L,V;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&cur.d,&cur.v,&cur.a);
			cur.flg=false;
			if (cur.a>0){
				if (cur.v>V)cur.q.l=cur.d,cur.q.L=true;
				else{
					cur.q.l=cur.d+(V*V-cur.v*cur.v)/2.0/cur.a,cur.q.R=false;
				}
				cur.q.r=L;
				cur.q.L=true;
				if (cur.q.l>cur.q.r)cur.q={0,0,0,0};
			}else if (cur.a==0){
				if (cur.v>V)cur.q.l=cur.d,cur.q.L=true,cur.q.r=L,cur.q.R=true;
			}else if (cur.a<0){
				if (cur.v>V){
					cur.q.l=cur.d;
					cur.q.L=true;
					cur.q.r=cur.d+(V*V-cur.v*cur.v)/2.0/cur.a;
					cur.q.R=false;
					ld end=cur.d-cur.v*cur.v/2.0/cur.a;
					if (end<cur.q.r){
						cur.q.r=end;
						cur.q.R=true;
					}
				}
				
			}
			//printf("%d:%lf-%lf\n",i,cur.q.l,cur.q.r);
		}
		
		int ans1=0;
		for (int j=1;j<=m;j++){
			int p;
			scanf("%d",&p);
			for (int i=1;i<=n;i++){
				if (cur.flg)continue;
				if (isin(cur.q,p)){
					cur.flg=true;
					ans1++; 
					//printf("%d:%d\n",j,i);
				}
			}
		}
		printf("%d\n",ans1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ©\2
6 4 ©\4
2 5 8 9 15
*/
