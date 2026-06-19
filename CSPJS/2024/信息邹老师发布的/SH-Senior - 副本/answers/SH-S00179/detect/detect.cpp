#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
using namespace std;
int p[100100],chafen[100100];
int lp[100100],rp[100100];
int qfront=0,qback=0;
int upperbound(int l,int r,int *a,int num){
	while(l!=r){
		int mid=(l+r)>>1;
		if(a[mid]<num){
			l=mid+1;
		}
		if(a[mid]==num){
			return mid;
		}
		if(a[mid]>num){
			r=mid;
		}
		//printf("low,l=%d,r=%d,a[mid]=%d,num=%d",l,r,a[mid],num);
	}
	return r;
}
int lowerbound(int l,int r,int *a,int num){
	while(l!=r){
		int mid=(l+r+1)>>1;
		if(a[mid]>num){
			r=mid-1;
		}
		if(a[mid]<num){
			l=mid;
		}
		if(a[mid]==num){
			return mid;
		}
	}
	return l;
}

typedef struct car{
	int in;
	int out;
	bool operator<(const struct car &that){
		return this->in<that.in;
	}
} car;
typedef struct car0{
	int in;
	int out;
	bool operator<(const struct car0 &that){
		return this->out<that.out;
	}
} car0;
car cars[100100];
car0 cars0[100100];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int n,m,L,V;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int j=0;j<n;j++){
			int d,a,v;
			scanf("%d%d%d",&d,&v,&a);
			cars[j].in=cars[j].out=210000000;
			if(a==0){
				if(v>V){
					cars[j].in=d;
					cars[j].out=L;
				}
			}
			else if(a>0){
				if(v>V){
					cars[j].in=d;
					cars[j].out=L;
				}else{
					cars[j].in=(V*V-v*v+2*a)/(2*a)+d;
					cars[j].out=L;
				}
			}
			else if(a<0){
				if(v>V){
					cars[j].in=d;
					int tmp=(V*V-v*v+1)/(2*a)+d;
					cars[j].out=tmp>L?L:tmp;
				}
			}
		}
		for(int j=0;j<m;j++){
			scanf("%d",p+j);
		}
		for(int j=0;j<n;j++){
			if(cars[j].in==210000000&&cars[j].out==210000000)continue;
			
			cars[j].in=upperbound(0,m-1,p,cars[j].in);
			cars[j].out=lowerbound(0,m-1,p,cars[j].out);
			int q=upperbound(0,m-1,p,cars[j].out); 
			if(q==cars[j].in){
				cars[j].in=210000000;
				cars[j].out=210000000;
			}
		}
		for(int j=0;j<n;j++){
			cars0[j].in=cars[j].in;
			cars0[j].out=cars[j].out;
		}
		sort(cars0,cars0+n-1);
		for(int j=0;j<n;j++){
			cars[j].in=cars0[j].in;
			cars[j].out=cars0[j].out;
		}
		sort(cars,cars+n);
		
		cars[n].in=210000000;
		n=0;
		while(cars[n].in!=210000000){
			n++;
		}
		printf("%d ",n);
		chafen[n-1]=cars[n-1].out;

		for(int j=n-2;j>=0;j--){
			chafen[j]=(chafen[j+1]<cars[j+1].out)?chafen[j+1]:cars[j+1].out;
		}
		for(int j=0;j<n;j++){
			if(chafen[j]<cars[j].out){
				cars[j].in=210000000;
			}
		}
		sort(cars,cars+n);
		cars[n].in=210000000;
		n=0;
		while(cars[n].in!=210000000){
			n++;
		}

		cars[n].in=-1;
		qfront=0;
		qback=0;
		for(int j=0;j<m;j++){
			while(cars[qback].in<=j&&qback<n){
				qback++;
			}
			while(cars[qfront].out<j&&qfront<=qback){
				qfront++;
			}
			if(qfront==qback){
				lp[j]=-1;
				rp[j]=-1;
			}else{
				lp[j]=qfront;
				rp[j]=(qback>=n)?(n-1):(qback-1);
			}
		}

		int lastrp=0,maxrp=0;
		qback=0;
		int ans=0;
		lp[m]=1000000,rp[m]=1000000;
		while(lastrp-1<n-1){
			maxrp=0;
			while(lp[qback]<=lastrp){
				maxrp=maxrp<rp[qback]?rp[qback]:maxrp;
				qback++;

			}
			lastrp=maxrp+1;
			ans++;
		}
		printf("%d\n",m-ans);
	}
			
	return 0;
}
