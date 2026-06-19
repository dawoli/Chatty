#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,d,v,a,s[N];
struct l{
	int s,e;
	bool isnear; 
}qj[N];
struct smartbb{
	bitset<N> b;
	//bool ish=0;
}sc[N];
bitset<N> ans;
long long anslast;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		memset(s,0,sizeof(s));
		memset(qj,0,sizeof(qj));
		memset(sc,0,sizeof(sc));
		int n,m,L,V;//车辆数量、测速仪数量、主干道长度和道路限速
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){//——————初始化部分 
			cin>>d>>v>>a;//位置驶入,初速度,加速度
			if(a>0){//----大于 
				if(v>V) qj[i].s=d,qj[i].e=L;//一直超速 
				else {
					if((V*V-v*v)%(2*a)!=0) qj[i].isnear=1;//需要提前 
					qj[i].s=ceil(1.0*(1.0*(V*V-v*v)/(2*a)))+d;//往后 
					qj[i].s-=qj[i].isnear; 
					if(qj[i].s>L) qj[i].s=0,qj[i].e=0;
					else qj[i].e=L; 
					//cout<<"s----   "<<qj[i].s<<endl;
				}
			}
			if(a<0){//----小于 
				if(v<=V) qj[i].s=0,qj[i].e=0;//没超速 
				else {
					qj[i].e=floor(1.0*(1.0*(V*V-v*v)/(2*a)))+d;//往前 
					if(qj[i].e>L) qj[i].e=L;//记得特判 
					qj[i].s=d; 
					//cout<<"e----   "<<qj[i].s<<"   "<<qj[i].e<<endl;
				}
			}if(a==0){//----等于 
				if(v>V) qj[i].s=d,qj[i].e=L;
				else qj[i].s=0,qj[i].e=0;//cout<<"m----   "<<endl;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>s[i];
		}//——————初始化部分end 
		long long cnt=0;
		for(int i=1;i<=n;i++){
			int qwe=upper_bound(s+1,s+1+m,qj[i].e)-s-1;
			if((qj[i].s!=0&&qj[i].e!=0)&&s[qwe]>qj[i].s){
				cnt++;//可以发现 
				sc[i].b|=1<<i;
				int starp=upper_bound(s+1,s+1+m,qj[i].s)-s-1;
				for(int i=starp;i<=qwe;i++){//从大于到小于等于 
					ans|=1<<i;
				}
			}//cout<<i<<":   "<<upper_bound(s+1,s+1+m,qj[i].e)-s-1<<"   :   "s[upper_bound(s+1,s+1+m,qj[i].e)-1-s]<<"   cnt:  "<<cnt<<endl;
		}cout<<cnt<<" ";//考虑踩线 
		for(int i=1;i<=m;i++){
			if(ans[s[i]]==0) anslast++;
		}cout<<anslast<<endl;
	}
	return 0;
}/*1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

1
10 10 69458 227
41471 989 -41
54266 987 -6
65335 774 -29
5337 999 -10
60091 567 -12
52229 845 -42
4754 810 -5
6632 637 -2
46771 771 -375
52434 992 -79
9324 36862 44559 51022 52755 53293 60089 60120 63342 69458
*/ 

