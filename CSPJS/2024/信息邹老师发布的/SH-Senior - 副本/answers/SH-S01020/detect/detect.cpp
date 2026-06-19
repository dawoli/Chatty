#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e5+10;
int n,m,L,V;
//车辆数，测速仪数，主干道长度，道路限速 
int d[N],v[N],a[N];
//驶入的位置，初速度，加速度 
int p[N];
//测速仪的位置 

//以下是计算过程中要用到的变量
//需要每组数据memset清零 
bool cs[N];		//是否超速 
bool used[N];	//是否用到该加速仪

struct Node{	//区间 
	int st,ed;	//开始，结尾 
};
struct Node csjc[N];	//超速检测，csjs[i].st和ed分别表示检测的到车辆i的检测仪开始和结尾的范围 

bool csjc_cmp(Node a,Node b){
	//if(a.st<b.st)return true;
	//if(a.st==b.st && a.ed<b.ed)return true;
	if(a.ed<b.ed)return true;
	if(a.ed==b.ed && a.st>=b.st)return true;
	return false;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(csjc,0,sizeof(csjc));
		bool no_need_calc=true;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",d+i,v+i,a+i);
			if(a[i]<0)no_need_calc=false; 
		}
		for(int i=1;i<=m;i++){
			scanf("%d",p+i);
		}
		memset(cs,0,sizeof(cs));
		memset(used,0,sizeof(used));
		for(int i=1;i<=n;i++){
			bool is_first_run=true;
			for(int j=1;j<=m;j++){
				//第i辆车行驶到第j个测速仪 
				int s=p[j]-d[i];	//行驶路程 
				if(s<0)continue;
				double vt=sqrt(v[i]*v[i]+2*a[i]*s);		//行驶到该加速仪时的瞬时速度
				if(vt>V){
					cs[i]=true;
					//start一定是第一次进入这个分支 
					if(is_first_run)csjc[i].st=j;
					is_first_run=false;
					csjc[i].ed=j;
				}
				/*
L1: 
				if(a[i]<=0 && vt>V){
					cs[i]=true;
					used[j]=true;
					break;			//原因见后 
				}
				if(a[i]<=0 && vt<V){
					break;
				}*/
			}
			//printf("%d %d\n",csjc[i].st,csjc[i].ed);
			/*
			printf("%d: ",i);
			for(int j=1;j<=m;j++){
				if(used[j])printf("%d ",j);
			}
			printf("\n");*/
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cs[i])ans++;
		}
		printf("%d ",ans);
		//用来通过a>=0的测试数据 
		//加速程序运行
		if(no_need_calc){
			printf("%d\n",m-1);
		}
		else{
			
		
		//一个问题
		//a>0，如果某一个能判定到，则它之后的加速仪都能判定到
		//a<0，如果某一个能判定到，则它之前的加速仪都能判定到
		//那么保留的加速仪一定是最前或最后的
		
		//如果一车a>=0超速，则保留最后一个加速仪即可
		//如果一车a<0超速，则保留它刚进来时的那个加速仪即可
		//（等号取哪边都行） 
		
		//但这样有个问题
		//出口处的加速仪会堆积
		//如两个a<0的车，一车能被123检测到，一车能被234检测到
		//实际只保留2（或者3） 即可 
		//但是这一算法会保留12
		//如果单纯考虑保留最后一个加速仪，就变成保留34，答案也不对
		
		//唯一解法是排序之后按最后面的一个加速仪逐个列举
		//举例
		//1234,456,89,5678,2345,6789
		//按照第一个加速仪编号排序
		//1234,2345,456,5678,6789,89
		//先看第一辆，最后是4，如果开4，能覆盖掉前四辆车
		//所以下一步看第五辆
		//最后是8
		//开8正好可以把后三辆全部覆盖
		//所以结束
		//答案就是开4和8 
		//开的加速仪一定是连续的
		//所以存开头和结尾就行 
	
		//还有问题
		//不过没法解决了
		//疑似要用并查集但是时间不够写了 
		int ans=0;	//记录必要的测速仪的数量 
		sort(csjc+1,csjc+1+n,csjc_cmp);
		for(int i=1;i<=n;i++){
			//fprintf(stderr,"%d %d\n",csjc[i].st,csjc[i].ed);
		}
		for(int i=1;i<=n;i++){
			if(!cs[i])continue;
			for(int j=i+1;j<=n;j++){
				//判断csjc[i]的最后一个检测仪能覆盖多少个
				if(!(csjc[j].st<=csjc[i].ed && csjc[i].ed<=csjc[j].ed)){
					//排序排好的，所以这个不能覆盖，之后的都不可能覆盖了
					i=j;
					goto L131; 
				}
			}
			//如果走到这里，那么说明全部都覆盖完毕了
			ans++;
			goto L141; //不然如果i<n的话还要继续循环下去，必须加这个跳转 
L131:
			ans++;
		}
L141:
		printf("%d\n",m-ans);
   }}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
