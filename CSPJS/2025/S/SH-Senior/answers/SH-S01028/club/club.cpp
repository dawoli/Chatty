#include<bits/stdc++.h>
using namespace std;
struct node{
	int f=0,s=0,t=0;
}op[100010],k[100010],g,ui[100010];
bool cmp1(node a,node b){
	return a.f>b.f;
}
bool cmp2(node a,node b){
	return a.s>b.s;
}
bool cmp3(node a,node b){
	return a.t>b.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,cnt=0;
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		g.f=0;
		g.s=0;
		g.t=0;
		for(int i=1;i<=n;i++){
			cin>>op[i].f>>op[i].s>>op[i].t;
			if(op[i].f>op[i].s){
				if(op[i].f>op[i].t){
					g.f++;
					k[g.f].f=i;
					ui[g.f].f=op[i].f-max(op[i].t,op[i].s);
				}
				else{
					g.t++;
					k[g.t].t=i;
					ui[g.t].t=op[i].t-max(op[i].f,op[i].s);
				}
			}
			else{
				if(op[i].s>op[i].t){
					g.s++;
					k[g.s].s=i;
					ui[g.s].s=op[i].s-max(op[i].f,op[i].t);
				}
				else{
					g.t++;
					k[g.t].t=i;
					ui[g.t].t=op[i].t-max(op[i].f,op[i].s);
				}
			}
			cnt+=max(op[i].f,max(op[i].s,op[i].t)); 
		}
		if(g.f>n/2){
			sort(ui+1,ui+g.f+1,cmp1);
			for(int i=g.f;i>n/2;i--){
				cnt-=ui[i].f;
				cout<<ui[i].f;
			}
		}
		else if(g.s>n/2){
			sort(ui+1,ui+g.s+1,cmp2);
			for(int i=g.s;i>n/2;i--){
				cnt-=ui[i].s; 
				cout<<ui[i].s;
			}
		}
		else if(g.t>n/2){
			sort(ui+1,ui+g.t+1,cmp3);
			for(int i=g.t;i>n/2;i--){
				cnt-=ui[i].t;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
	fclose(stdout);
	fclose(stdin);
} 
