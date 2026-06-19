#include <bits/stdc++.h>
using namespace std;
int t;

struct carr{//名为车，实际上是区间 
	int left;//左端点 
	int right;//右端点 
};
int qzdn[1000010]={};//测速点前缀和,太大了必须拿出来 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		for(int j=0;j<1000010;j++)qzdn[j]=0; 
		int ans1=0;
		int n,m,l,v,qjs=0;//不是所有车都能形成区间，所以要有区间数 
		carr qj[100010]={};
		int dn[100010]={};//测速点 
		bool songf=1;//判断数据点是否为送分形的数据点 
		cin>>n>>m>>l>>v;
		for(int j=1;j<=n;j++){
			int d,v2,a;
			cin>>d>>v2>>a;//车的三个数据，要将它们转换为左右端点
			if(a<0){
			    songf=0;//有减速就不是送分（）
		    }
			int le=floor(d+1.0*(v*v-v2*v2)/(1.0*2*a));
			if(a<0){//先处理减速 
				if(v2>v){
					qj[++qjs].left=d;//左端点为起始
					qj[qjs].right=min(l,le);
				}
			}
			else if(a==0&&v2>v){
				qj[++qjs].left=d;
				qj[qjs].right=l;
			}
			else if(a>0){
				if(v2>v){
				    qj[++qjs].left=d;
				    qj[qjs].right=l;
				}
				else{
					if((d+1.0*(v*v-v2*v2)/(1.0*2*a))>le)le++;
					if(le<=l){
						qj[++qjs].left=le;
						qj[qjs].right=l; 
					}
				}
			}//至此车被转化为了区间
		}
		for(int j=1;j<=m;j++){
			cin>>dn[j];
		    qzdn[dn[j]]=1;
		}
		for(int j=0;j<=l;j++){
			qzdn[j]+=qzdn[j-1];
		}//处理测速点 
		for(int j=1;j<=qjs;j++){//回答问题1
		    if(qj[j].left==0&&qzdn[qj[j].right]>0)ans1++;
			else if(qzdn[qj[j].right]>qzdn[qj[j].left-1])ans1++;
		}
		cout<<ans1<<" ";
		if(songf==1){
		    if(qjs>0)cout<<m-1;
			else cout<<m;	
		}
		cout<<endl;
	}
	return 0;
}
