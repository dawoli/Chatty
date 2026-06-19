#include<bits/stdc++.h>
using namespace std;
#define N 100005//注意设置大小
typedef long long ll;

struct Speed{
	double s,e;
	bool ts,te;
	void set(double a,double b,bool c=true,bool d=true){
		s=a,e=b,ts=c,te=d;
	}
	bool isOver(double pos){
		if(s!=-1&&e!=-1) if(pos>s&&pos<e||pos==s&&ts||pos==e&&te) return 1;
		return 0;
	}
};

struct Car{
	double d,v,a,outRoad;
	Speed s;
	bool isCs=false;
	void clear(){
		d=v=a=outRoad=0;
		isCs=false;
	}
	void initOutRoad(int l){
		isCs=false;
		if(a>=0) outRoad=l;
		else outRoad=((-v*v)/(a*2.0)+d>l?l:(-v*v)/(a*2.0)+d);
	}
	void initCs(int l,int cv){
		if(a>0){
			if(v>cv) s.set(d,l);
			if(v==cv) s.set(d,l,false);
			if(v<cv){
				if(outRoad>2*d) s.set((cv*cv-v*v)/(a*2.0)+d,outRoad,false);
				else s.set(-1,-1);
			}
		}
		else if(a==0){
			if(v>cv) s.set(d,outRoad);
			else s.set(-1,-1);
		}
		else{
			if(v>cv){
				if((cv*cv-v*v)/(a*2.0)+d>outRoad) s.set(d,outRoad);
				else s.set(d,(cv*cv-v*v)/(a*2.0)+d,true,false);
			}
			else s.set(-1,-1);
		}
		
	}
};

int T,n,m,l,cv,st[N],ct,cto;//st[i]:第i个测速仪的位置 
Car c[N];

int main(){
	cin.tie(nullptr);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>l>>cv;
		for(int i=1;i<=n;++i){
			cin>>c[i].d>>c[i].v>>c[i].a;
			c[i].initOutRoad(l);
		}
		for(int i=1;i<=m;++i) cin>>st[i];
		for(int i=1;i<=n;++i){
			c[i].initCs(l,cv);
			if(c[i].s.isOver(st[m])) ct++;
		}
		cout<<ct<<' '<<(ct==0?m:m-1)<<endl;
		
		ct=cto=n=m=l=cv=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

