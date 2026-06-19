#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e6+10;
//精度！！！数据类型？ 
int T;
int n,m,L,V;
struct node{
	int d,v,a;
	int typ;//是否超速 
	int l,r;//可被拍到的区域 包含端点 
} car[N];
struct nd{
	int l,r;
	bool operator < (const nd& t) const {
		return r<t.r;
	}
} qj[N];
int g[N];//编号为i的区间是否被覆盖 
int det[M];//第i个摄像头的位置 
int b[M];//0~i位置上摄像头个数的总和 
void upd(int i){
	int st=car[i].d;
	int a=car[i].a;
	int v=car[i].v;
	int l=-1,r=-1;
	int flg=0;
	if(a<0){
		if(v>V){
			l=st;
		//	double temp=1.0*(v-V)/a;
			double temp=0.5*(v-V)*(v+V)/(0-a);//刚好速度达到V时 行进的路程 
			int tp=(int)temp;
			r=st+tp;
			r=min(r,L);
			flg=1;
		}
	}
	else if(a==0){
		if(v>V){
			l=st;
			r=L;
			flg=1;
		}
	}
	else{
		if(v>V){
			l=st;
			r=L;
			flg=1;
		}
		else{
			double temp=0.5*(V-v)*(V+v)/a;
			int tp=(int)temp;
			l=st+tp+1;//v>V后 第一个端点 
			if(temp-tp==0)	l+=1;////////精度？ 
			r=L;
			if(l>L){
				flg=0;
			}
			else{
				flg=1;
			}
		}
	}
	car[i].typ=flg;
	if(car[i].typ==1){
		car[i].l=l;
		car[i].r=r;
	}
	return;
}
void _init(){
	///////////////////////
	memset(b,0,sizeof(b));
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&n,&m,&L,&V);
		_init();
		
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&car[i].d,&car[i].v,&car[i].a);
			upd(i);
		}
		
		for(int i=1;i<=m;i++){
			scanf("%d",&det[i]);
			b[det[i]]+=1;
		}
		for(int i=1;i<=L;i++){
			b[i]+=b[i-1];
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(car[i].typ==0)	continue;
			int l=car[i].l;
			int r=car[i].r;
			if(b[r]-b[l-1]>=1){
				sum++;
				qj[sum]={l,r};
				//能被拍到的车辆 
			}
		}
		sort(qj+1,qj+sum+1);


		int cnt=0;//必要保留的摄像头 
		int t=1,i=1;//当前未使用的摄像头的下标  当前未被覆盖的区间 
		while(i<=sum&&t<=m){
		 	
			int j=t;
			int l=qj[i].l,r=qj[i].r;
			while(j+1<=m&&det[j+1]<=r){////?
				j++;//找到最靠近r端 在区间内的 t 
			} 
			t=j;
			//找下一个i 
		//	cout<<i<<"     "<<t<<endl;
			i++;//当前区间已经符合 
			while(i<=sum&&det[t]>=qj[i].l){
				i++;
			}	
			t++; 
			cnt++;
		
		}
		cout<<sum<<" "<<m-cnt<<endl;
	
	}
	

	return 0;
} 

//1
//10 10 145322 772
//10139 897 -47
//86524 947 -2
//51251 982 -2
//12573 962 -2
//14068 919 -163
//10944 994 -6
//35650 999 -9
//3804 977 -1
//1149 905 -2
//43935 932 -2
//10519 11805 14747 28890 37732 45509 55779 80531 108392 126659
