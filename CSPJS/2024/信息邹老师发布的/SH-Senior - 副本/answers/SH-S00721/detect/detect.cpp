#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
const int maxn = 1e5+10;

long long n,m,V,L;

struct carr{
	int d,v,a; //驶入 初始速度 加速度 
}car[maxn];
int p[maxn]; //测速仪位置 

bool overr[maxn]; //是否超速 

set<int> detect[maxn]; //每个测速仪测到的超速的车数maxn=maxm

void work1(){
	//计算超速的车辆数
	//枚举每辆车和每个测速仪位置 判断是否在此处超速
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int dis = p[j]-car[i].d;
			if(dis<0)continue;
			double speed;
			speed = double(car[i].v*car[i].v+2*car[i].a*dis);
			if(speed<0)continue;
			//speed = (double) sqrt(speed);
			//cout<<"CAR "<<i<<" POS"<<p[j]<<" SPEED"<<speed<<endl;
			if(speed>V*V){
				detect[j].insert(i);
				overr[i]=1; break;
			} 
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(overr[i]){
		//	cout<<"OVERR "<<i<<endl;
			cnt++;
		}
	}
	cout<<cnt<<" ";
}

int detected[maxn]; //每辆车被测到了多少次 
struct machine{
	int pos; int cars;
}pp[maxn];
bool cmp(machine one,machine two) {
	return one.cars<two.cars;
}

void clearall(){
	//cout<<"clear"<<endl;
	for(int i=1;i<=n;i++){
		car[i].a=car[i].d=car[i].v=0;
		overr[i]=0;
		detected[i]=0;
	}
	for(int j=1;j<=m;j++){
		p[j]=0;
		detect[j].clear();
		pp[j].pos=pp[j].cars=0;
	}
}
void work2(){
	//首先全选
	for(int i=1;i<=m;i++) {
		pp[i].cars=detect[i].size();
		for(auto x:detect[i]){
			detected[x]++;
		}
	}
	sort(pp+1,pp+m+1,cmp);
	int cnt = 0;
	for(int i=1;i<=m;i++){
	//	cout<<i<<endl;
		bool flag = 1;
		for(auto x:detect[i]){
			if(detected[x]==1){
				flag=0; break;
			}
		}
		if(flag){
			for(auto x:detect[i]){
				detected[x]--;
			}
			cnt++;
		}
	}
	cout<<cnt<<endl;
	//然后挨个关不需要的仪
	//按照测到的车个数排列 
}

int main(){
//	cout<<"FREOPEN\n";
//	cout<<"SCANF\n";
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T; cin>>T;
	while(T--){
		clearall();
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) {
			cin>>car[i].d>>car[i].v>>car[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		work1();
		work2();
	}
	return 0; 
}
