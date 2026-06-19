#include<bits/stdc++.h>
using namespace std;
int T,N,A[1000001],N1,top;
struct co{
	int num;
	int id;
	int color;
}a[100001];
struct p{
	int x,y;
};
int b[100001];
int f;
int read(){
	char c;int s;
	c=getchar();
	while(c<'0'||c>'9') c= getchar();
	s=c-'0';
	c=getchar();
	while(c>='0'&&c<='9'){
		s=c-'0'+s*10;
		c=getchar();
	}
	return s;
}
bool cmp(co x,co y){
	return x.id<y.id;
}
p find(int left,int right,int n){
	int x,y;
	for(int i=left;i<=right;i++)
		if(b[i]==n) {
			x=i;break;
		}
	for(int i=right;i>=left;i--)
		if(b[i]==n) {
			y=i;break;
		}
	p o={x,y};
	return o;
}
void col(int x,int y,int n){
	if(x+1==y)	a[x].color=n,a[y].color=n;
	
}

void prepare(){
	memset(A,0,sizeof(A));
		N=read();N1=N;top=0;
		for(int i=1;i<=N;i++){
			a[i].num=read();
			a[i].id=i;
			A[a[i].num]++;
			if(A[a[i].num]==2)	b[++top]=a[i].num;
		}	
		for(int i=1;i<=N;i++)
			if(A[a[i].num]==1){
				N1-=1;a[i].id=100001;
			}	
		sort(a+1,a+N+1,cmp);
		sort(b+1,b+top+1);
}
int main(){
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		prepare();
		f=N1;
		p c=find(1,N1,b[top]);
		col(c.left,c.right,1);
		
	}
	
	return 0;
}
//3 3 1 2 1 4 1 2 3 4 8 3 5 2 5 1 2 1 4
