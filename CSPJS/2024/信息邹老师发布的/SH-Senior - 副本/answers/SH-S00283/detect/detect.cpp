#include<bits/stdc++.h>
using namespace std;
#define N 100001
#define INF 1e9
typedef long long LL;
int n,m,L,V;	//车辆数量、测速仪数量、主干道长度、道路限速
struct Car{
	int d,v,a;	//驶入位置、初速度、加速度 
	double beg,end;	//beg:首次达到限速的位置 end:超速后首次不超速的位置 
		//测速判定：(beg,end) 
		//beg=end=-1:一直不超速 
} c[N];
int det[N];	//测速器位置 
struct overSpeed{	//记录每辆车被检测到超速的两端测速器位置 
	int l,r; 
	bool vst=0;		//vst=0：开启 
} s[N];
bool cmp1(overSpeed x,overSpeed y){
	return x.l<y.l;
}
void cal(Car &x){
	if(x.a<0){		//减速情况 
		if(x.v>V){		//开始超速，一段距离后不超速 
			x.beg=x.d-0.01;
			x.end=x.d+(V*V-x.v*x.v)*1.0/(2*x.a);
		}else{			//一直不超速 
			x.beg=x.end=-1;
		}
	}else if(x.a>0){	//加速情况 
		if(x.v<=V){		//开始不超速，一段距离后超速 
			x.beg=x.d+(V*V-x.v*x.v)*1.0/(2*x.a);
			x.end=INF;
		}else{			//一直超速 
			x.beg=x.d-0.01;
			x.end=INF; 
		}
	}else{			//匀速情况 
		if(x.v>V){		//一直超速 
			x.beg=x.d-0.01;
			x.end=INF;
		}else{			//一直不超速 
			x.beg=x.end=-1;
		}
	}
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T; cin>>T;
	while(T--){
		memset(c,0,sizeof(c));
		memset(s,0,sizeof(s));
		memset(det,0,sizeof(det));
		LL num=0;		//超速车辆数量
		scanf("%d %d %d %d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&c[i].d,&c[i].v,&c[i].a);
			cal(c[i]);
			//cout<<"车辆超速区间："<<c[i].beg<<" "<<c[i].end<<endl;
		}
		for(int j=1;j<=m;j++) scanf("%d",&det[j]);	//测速器位置 
		for(int i=1;i<=n;i++) if(c[i].beg!=-1){	//如果有超速 
			for(int j=1;j<=m;j++){
				if(det[j]>c[i].beg&&det[j]<c[i].end){
					num++;
					s[num].l=j; break;	//记录第一个检测到超速的测速器 
				}
			}
			for(int j=m;j>=1;j--){
				if(det[j]>c[i].beg&&det[j]<c[i].end){
					s[num].r=j; break;	//记录最后一个检测到超速的测速器 
				}
			}
		}
		/*贪心解决问题二*/
		LL f;	//每次选择开始时间最晚的事件的开始时间 
		LL ans=0;
		sort(s+1,s+1+num,cmp1);
		for(int i=num;i>=1;i--) if(s[i].vst==0){	//倒序 如果开着
			f=s[i].l;
			ans++;
			for(int j=1;j<i;j++){	//筛掉结束时间晚于等于f的事件 
				if(s[j].l<=f&&s[j].r>=f&&s[j].vst==0){
					s[j].vst=1;		//关闭 
				}
			}
		}
		printf("%d %d\n",num,m-ans);
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
5 5 -2
6 4 -4
2 5 8 9 15

2
10 10 150307 247
62978 968 -5
51700 883 -3
40408 564 -1
60366 870 -41
35943 797 -7
47476 595 -11
59020 672 -10
81024 964 -11
80637 695 -5
66114 874 -1
46720 48066 57373 60882 68842 72773 82820 116695 122159 150307
10 10 145322 772
10139 897 -47
86524 947 -2
51251 982 -2
12573 962 -2
14068 919 -163
10944 994 -6
35650 999 -9
3804 977 -1
1149 905 -2
43935 932 -2
10519 11805 14747 28890 37732 45509 55779 80531 108392 126659

*/
