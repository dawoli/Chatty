#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n,m,L,V;
const double eps=1e-6;
struct Car{
	int d,v,a;
	int have;
	double start,end;
	int getl,getr;//qu bu qu zuo you
}car[100010];
int p[100010];
double ap[100010];
struct Line{
	int left,right;
}line[100010];
bool cmp(Line a,Line b){
	return a.right<b.right;
}
int read(){
	int f=1,x=0;
	char ch=getchar();
	if(ch=='-'){
		f=-1;
	}else{
		x=ch-'0';
	}
	while(1){
		ch=getchar();
		if(ch<'0'||ch>'9'){
			break;
		}
		x=x*10+ch-'0';
	}
	return x*f;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		memset(ap,0,sizeof(ap));
		memset(p,0,sizeof(p));
		for(int i=1;i<=100000;i++){
			line[i].left=0;
			line[i].right=0;
			car[i].d=0;
			car[i].v=0;
			car[i].a=0;
			car[i].have=0;
			car[i].start=0;
			car[i].end=0;
			car[i].getl=0;
			car[i].getr=0;
		}
		n=read();
		m=read();
		L=read();
		V=read();
		//cout<<n<<" "<<m<<" "<<L<<" "<<V<<endl;
		//scanf("%lld %lld %lld %lld",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			car[i].d=read();
			car[i].v=read();
			car[i].a=read();
			//scanf("%lld %lld %lld",&car[i].d,&car[i].v,&car[i].a);
			if(car[i].a==0){
				if(car[i].v>V){
					car[i].have=1;
					car[i].getl=1;
					car[i].getr=1;
					car[i].start=car[i].d;
					car[i].end=L;
				}else{
					car[i].have=0;
				}
			}else if(car[i].a<0){//ke neng ting
				if(car[i].v<=V){
					car[i].have=0;
				}else{
					car[i].have=1;
					car[i].getl=1;
					car[i].getr=0;
					//ji lu dao da su du shi jian
					//double usetime=1.0*(1.0*(car[i].v-V))/car[i].a;
					car[i].end=(1.0*(car[i].v*car[i].v)-(V*V))/(-2.0*car[i].a)+car[i].d;
					//[okleft,okright)
					if(car[i].end>L){
						car[i].end=L;
						car[i].getr=1;
					}
					car[i].start=car[i].d;
				}
			}else{
				if(car[i].v>V){
					car[i].have=1;
					car[i].getl=1;
					car[i].getr=1;
					car[i].start=car[i].d;
					car[i].end=L;
				}else{
					car[i].start=(1.0*(V*V)-(car[i].v*car[i].v))/(2.0*car[i].a)+car[i].d;
					//(start,end]
					if(car[i].start>=L){
						car[i].have=0;
					}else{
						car[i].have=1;
						car[i].getl=0;
						car[i].getr=1;
						car[i].end=L;
					}
				}
			}
			//cout<<car[i].getl<<" "<<car[i].getr<<" "<<car[i].start<<" "<<car[i].end<<" "<<car[i].have<<endl;
		}
		for(int i=1;i<=m;i++){
			p[i]=read();
			//scanf("%lld",&p[i]);
			ap[i]=p[i];
		}
		int pos=0;
		for(int i=1;i<=n;i++){
			if(car[i].have==0){
				continue;
			}
			if(car[i].getl==0){
				car[i].start+=eps;
			}
			if(car[i].getr==0){
				car[i].end-=eps;
			}
			int left=lower_bound(ap+1,ap+m+1,car[i].start)-ap;
			int right=upper_bound(ap+1,ap+m+1,car[i].end)-ap-1;
			if(left<=right){
				line[++pos].left=left;
				line[pos].right=right;
				//cout<<left<<" "<<right<<endl;
			}
		}
		if(pos==0){
			printf("%lld %lld\n",0,m);
		}else{
			sort(line+1,line+pos+1,cmp);
			int cur=line[1].right,ans=1;
			for(int i=2;i<=pos;i++){
				if(line[i].left>cur){
					ans++;
					cur=line[i].right;
				}
			}
			printf("%lld %lld\n",pos,m-ans);	
		}
	}
}
/*
1
10 10 99858 982
39033 1000 -2
26456 999 -1
25617 37 -242
28141 1000 -1
27960 995 -6
1452 988 -58
44970 993 -322
16069 998 -1
26508 999 -1
44686 993 -1
1460 14938 17798 29360 42181 44971 55154 55534 74909 99858
std:9 7
me:10 6
*/
