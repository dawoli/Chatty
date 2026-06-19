#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T;
struct member{
	int id; //成员编号
	long long c1; //成员竞争力 
};
priority_queue<member> q; //优先队列是大的在上面，我们需要的就是竞争力大的在上。 
bool operator<(member x,member y){
	return x.c1<y.c1; //有待研究。 
} 
vector<long long> want[5]; //want[i]表示第i个社团有多少人最想去 
long long n,a[N][5],cnt[5],ans,mx[N],secmx[N]; 
bool vst[N]; //vst[i]就表示成员i已经选过社团了 
//cnt[i]表示选社团i为第一志愿的有多少成员（有两个社团一样的不算） 
void initialze(){
	for(int i=1;i<=3;i++)
		want[i].clear();
	memset(cnt,0,sizeof(cnt));
	memset(mx,0,sizeof(mx));
	memset(secmx,0,sizeof(secmx));
	memset(vst,0,sizeof(vst));
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int ii=1;ii<=T;ii++){
		ans=0;
		cin>>n;
		initialze(); //要初始化的东西太多了。 
		for(int i=1;i<=n;i++){
			int tmp1=0; //表示最大值是哪个社团 
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>mx[i]){
					mx[i]=a[i][j];
					tmp1=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(j==tmp1)
					continue;
				secmx[i]=max(secmx[i],a[i][j]);
			}
			//到时候检查下最大值次大值这两个数组打得对不对 
			if(a[i][1]>a[i][2] and a[i][1]>a[i][3]){
				cnt[1]++;
				want[1].push_back(i); 
			}
			if(a[i][2]>a[i][1] and a[i][2]>a[i][3]){
				cnt[2]++; 
				want[2].push_back(i);
			}
			if(a[i][3]>a[i][1] and a[i][3]>a[i][2]){
				cnt[3]++;
				want[3].push_back(i);
			}
		}
		bool flag=0; //flag=0表示没有社团被争抢
		int x=0; //x表示哪个社团被争抢 
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				flag=1;
				x=i;
				break;
			}
		}
		if(flag){ //有社团被争抢，我们需要调度一下 
			//那么找每个人的竞争力，哪些人想要这个社团，want里面有
			for(int i=0;i<want[x].size();i++){
				int v=want[x][i]; //想要进这个社团的成员的编号 
				vst[v]=1; 
				int com=0; //她的竞争力是多少？就是第一志愿的满意度减去第二志愿的满意度
				com=mx[v]-secmx[v]; //最大值减去次大值
				//放进一个数据结构里排序，优先队列
				q.push((member){v,com});
			}
			//好了，现在我们找到了所有的想进这个社团的成员，我们把前n/2个拿出来
			//拿出来干什么？拿出来计算我们最后的答案：满意度
			int tmp=0; //tmp表示现在是第几个想去最热门社团的人，如果超过总人数半数，就去第二志愿 
			while(!q.empty()){ 
				tmp++; //多了一个人去到最受欢迎的社团 
			 	int u=q.top().id;
			 	q.pop();
			 	if(tmp<=n/2)
					ans+=mx[u]; 
				else
					ans+=secmx[u]; 
			}
			//好了，那冲突都解决了，剩下的人可以去自己喜欢的社团了
			//我怎么知道谁是剩下的？看来得再搞个数组标记一下(vst[i])
			for(int i=1;i<=n;i++){
				if(vst[i])
					continue;
				ans+=mx[i]; //我去自己喜欢的，没有人跟我抢 
			} 
		}
		else{
			//没有争抢，每个人找自己喜欢的就行了
			for(int i=1;i<=n;i++){
				ans+=mx[i];
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
} 
