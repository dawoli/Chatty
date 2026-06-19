#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const double minD=1e-10;

int n,m,L,V;

struct Range{
	int start;
	int end;
	void init(int d,int v,int a){
		if(a==0){
			if(v>V){
				this->start=d;
				this->end=L;
			}else{
				this->start=-1;
				this->end=-1;
			}
		}else if(a>0){
			if(v>V){
				this->start=d;
				this->end=L;
			}else{
				double overX=(double)(V*V-v*v)/(double)a/2.0;
				overX=ceil(overX)+(abs(overX-ceil(overX))<minD?1:0);
				this->start=min(d+(int)overX,L);
				this->end=L;
			}
		}else if(a<0){
			if(v<=V){
				this->start=-1;
				this->end=-1;
			}else{
				this->start=d;
				double lowerX=(double)(V*V-v*v)/(double)a/2.0;
				lowerX=floor(lowerX)-(abs(lowerX-floor(lowerX))<minD?1:0);
				this->end=min(d+(int)lowerX,L);
			}
		}
	}
};

struct Car{
	int d;
	int v;
	int a;
	Range range;
	void init(int d,int v,int a){
		this->d=d;
		this->v=v;
		this->a=a;
		this->range.init(d,v,a);
	}
};

Car carArr[100005];

struct ST{
	bool arr[21][1048600];
	int logArr[1048600];
	const int L=1048576;
	const int maxMi=20;
	ST(){
		for(int i=0;i<=L;i++){
			logArr[i]=(int)log2(i);
		}
	}
	void init(){
		for(int i=1;i<=maxMi;i++){
			int l=(int)pow(2,i);
			for(int j=0;j<=L-l;j++){
				arr[i][j]=arr[i-1][j]||arr[i-1][j+l/2];
			}
		}
	}
	bool inline query(int x,int y){
		int loga=logArr[y-x+1];
		return arr[loga][x]||arr[loga][y-(int)pow(2,loga)+1];
	}
	void inline clear(){
		memset(arr,0,L);
	}
};

ST st;

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			int d,v,a;
			cin>>d>>v>>a;
			carArr[i].init(d,v,a);
		}
		for(int i=0;i<m;i++){
			int p;
			cin>>p;
			st.arr[0][p]=1;
		}
		st.init();
		int ans=0;
		for(int i=0;i<n;i++){
			auto rang=carArr[i].range;
			if(rang.start!=-1&&st.query(rang.start,rang.end)){
				ans++;
			}
		}
		cout<<ans<<endl;
		st.clear();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
