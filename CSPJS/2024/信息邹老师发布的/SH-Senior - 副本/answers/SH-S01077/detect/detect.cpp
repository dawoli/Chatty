#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x^=x;
	int f=1;
	char a=getchar();
	while('0'>a||a>'9'){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x*=10;
		x+=a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}

const int SIZE=100009,SIZEM=10000009;
int T,n,m,l,v,c[SIZE],Nc,ans1,ans2;
struct node{
	int d,v,a;
	int l,r;
}d[SIZE];
bool cmp(const node&a,const node&b){
	return a.l>b.l;
}
void cal(int x){
	if(d[x].a==0){
		if(d[x].v>v){
			d[x].l=d[x].d;
			d[x].r=l;
		}
		else d[x].l=-1;
	}
	else if(d[x].a>0){
		double dis=1.0*(v*v-d[x].v*d[x].v)/d[x].a/2;
		if(dis<0){
			d[x].l=d[x].d;
			d[x].r=l;
		}
		else{
			d[x].l=d[x].d+dis+1;
			d[x].r=l;
		}
	}
	else{
		double dis=1.0*(v*v-d[x].v*d[x].v)/d[x].a/2;
		if(dis<=0)d[x].l=-1;
		else{
			d[x].l=d[x].d;
			if(dis==(long long)dis)dis--;
			d[x].r=min(d[x].d+dis,(double)l);
		}
	}
	return ;
	
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	read(T);
	int i,temp;
	while(T--){
		read(n);
		read(m);
		read(l);
		read(v);
		Nc=-1;
		ans1^=ans1;
		ans2^=ans2;
		for(i=1;i<=n;i++){
			read(d[i].d);
			read(d[i].v);
			read(d[i].a);
			cal(i);
		}
		for(i=0;i<m;i++){
			read(c[i]);
		}
		c[m]=SIZEM;
		sort(d+1,d+1+n,cmp);
		for(i=1;i<=n;i++){
			if(d[i].l>d[i].r)continue;
			if(d[i].l==-1)continue;
			temp=lower_bound(c,c+1+m,d[i].l)-c;
			if(c[temp]>d[i].r)continue;
			ans1++;
			if(Nc!=-1){
				if(d[i].l<=Nc&&Nc<=d[i].r)continue;
			}
			Nc=c[temp];
			ans2++;
		}
		printf("%d %d\n",ans1,m-ans2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
