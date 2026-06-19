#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
int lu[1000010];
int ans;
struct car{
	long long r,s,a;
	long long g,bg;
}c[100010];
struct ce{
	int d;
	int h;
	vector<int> v; 
}p[100010];
long long cnt;
void ji(int o){
//	cout <<cnt <<" "<< c[o].r << " " << c[o].s <<" " <<c[o].a<< endl;
	float db;
	long long x,y,z;
	if(c[o].a == 0){
		if(c[o].s > v){
			c[o].g = c[o].r;
			c[o].bg = l + 1 ;
		}
		else{
			c[o].g = l + 1;
			c[o].bg = l + 1;
		}
	}
	else{
		x = c[o].s;
		z = (v - x)  / 2 *(v + x) / c[o].a;
	}
	if(c[o].a > 0){
		if(c[o].s > v){
			c[o].g = c[o].r;
			c[o].bg = l;
		}
		else{
			c[o].g = z + c[o].r + 1;
			if(c[o].g > l)c[o].g = l;
			c[o].bg = l;
		}
	
	}
	else if(c[o].a <0){
		if(c[o].s > v){
			c[o].g = c[o].r;
			long long l1 = l;
			c[o].bg = min(l1,z +c[o].r);
			if(db == z){
				c[o].bg--;
			}
		}
		else{
			c[o].g = l +1;
			c[o].g = l +1;
		}
		
	}
//	cout <<c[o].g <<" " <<c[o].bg<<endl;
	bool flag = false;
	for(int i = c[o].g;i <= c[o].bg;i++){
		if(lu[i] > 0){
//			p[lu[i]].h++;
//			p[lu[i]].v.push_back(o);
			flag = true;
//			cout << o << " " << lu[i] <<endl;
			break;
		}
	}
	if(flag)ans++;
	
	
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&l,&v);
		cnt = 0;
//		cout <<n <<endl;
		ans = 0;
		memset(lu,0,sizeof(lu));
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&c[i].r,&c[i].s,&c[i].a);
//			cout <<c[i].g <<endl;
//			cout <<c[i].bg <<endl;
		}
		for(int i = 1;i <= m;i++){
			scanf("%d",&p[i].d);
			lu[p[i].d] = i;
		}
		for(int i = 1;i <= n;i++){
			cnt++;
			ji(i);
			
		}
		printf("%d ",ans);
		if(ans == 0){
			printf("%d\n",m);
			continue;
		}
		printf("%d\n",m - 1);
	}
	return 0;
} 
