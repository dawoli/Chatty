#include <bits/stdc++.h>
using namespace std;
const double jd=0.00000001;
struct car{
	int d,v,a;
};
struct qvjian{
	int l,r;
};

double Myabs(double x){
	if(x<0)return -x;
	return x;
}
double max_M(double a,double b){
	if(a>b)return a;
	return b;
}
bool cmp(qvjian a,qvjian b){
	return a.l<b.l;
}
vector<qvjian> qj;
int sl[1000100];
bool yongguo[1001000];
car c[100100];
long long f[1000100];
bool cs[1000100];
int w[100100];
int main(){
	int T;
	int n,m,l,v,QWE;
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	int ans=0;
	int xb;
	while(T--){
		memset(f,0,sizeof(f));
		memset(cs,false,sizeof(cs));
		memset(w,0,sizeof(w));
		memset(yongguo,0,sizeof(yongguo));
		memset(sl,0,sizeof(sl));
		while(!qj.empty()){
			qj.erase(qj.begin());
		}
		ans=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&w[i]);
			f[w[i]]++;
			cs[w[i]]=true;
		}
		for(int i=1;i<=1000090;i++){
			f[i]+=f[i-1];
		}
//		printf("//debug:f[]:");
//		for(int i=0;i<=20;i++){
//			printf("%d ",f[i]);
//		}
//		cout<<endl;
		qvjian Q;
		double wy;
		bool dygzh=false;
		for(int i=1;i<=n;i++){
			if(c[i].a>0){
				wy=max_M(((1.0*v*v-c[i].v*c[i].v)*1.0)/(2*c[i].a),0);
				wy+=c[i].d;
				if(Myabs(wy-(int)(wy))<=jd)xb=(int)(wy);
				else xb=(int)(wy)+1;
				if(f[l]!=f[xb]||(cs[xb])){
//					printf("line 51:ans++:i=%d\n",i);
					ans++;
				}
				if(!dygzh)dygzh=1;
			}
			else if(c[i].a<0){
				wy=((1.0*v*v-c[i].v*c[i].v)*1.0)/(2*c[i].a);
				if(wy<jd)continue;
				wy+=c[i].d;
				xb=(int)(wy);
				if(f[c[i].d]!=f[xb]||(cs[c[i].d])){
//					printf("line 62:ans++:i=%d\n",i);
					Q.l=c[i].d;
					Q.r=xb;
					qj.push_back(Q);
					ans++;
				}
			}
			else{
				if(c[i].v>v&&(f[c[i].d]!=f[l]||(cs[c[i].d]))){
//					printf("line 68:ans++:i=%d\n",i);
					ans++;
				}
			}
		}
		printf("%d ",ans);
		//debug
		int qwe=0;
		//debugend
		ans=0;
		if(dygzh)yongguo[w[m]]=true;
		if(qj.empty()){
			cout<<m-1<<endl;
			continue;
		}
		sort(w+1,w+m+1);
		sort(qj.begin(),qj.end(),cmp);
		for(int i=0;i<qj.size();i++){
			if(qj[i].l<=w[m]&&w[m]<=qj[i].r){
				qj.erase(qj.begin()+i);
				i--;
			}
		}
		int R=w[1];
		for(int i=2;i<=m;i++){
			if(w[i]>qj[0].r)break;
			R=w[i];
		}
		yongguo[R]=true;
		int Fi=0; 
		for(int i=1;i<qj.size();i++){
			if(R>=qj[i].l&&R<=qj[i].r)continue;
			Fi=qj[i].r;
			while(!cs[Fi])Fi--;
			R=Fi;
			yongguo[Fi]=true;
		}
		for(int i=0;i<=1000001;i++){
			if(yongguo[i])ans++;
		}
		cout<<m-ans<<endl;
		//debug
		if(m-ans<=0)cout<<"debug::"<<qwe<<endl;
	}
	return 0;
}
