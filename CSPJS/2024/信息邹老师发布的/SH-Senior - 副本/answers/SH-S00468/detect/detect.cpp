#include<bits/stdc++.h>
using namespace std;

struct car{
	int d,v,a;
};
struct bookmark{
	int l,r;
};
int T,n,m,L,V;
car c[100099];
bool csy[1000099];
int sxt[1000099];
int lxt[1000099];
bookmark qj[2000099];int cntqj=0;

bool cmp(bookmark aa,bookmark bb){return aa.r<bb.r or(aa.r==bb.r and aa.l<bb.l);}


signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		memset(csy,0,sizeof(csy));
		int ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++){int posi;cin>>posi;csy[posi]=1;}
		int cr=L+1;
		for(int i=L;i>=0;i--){if(csy[i])cr=i;sxt[i]=cr;}
		cr=-1;
		for(int i=0;i<=L+1;i++){if(csy[i])cr=i;lxt[i]=cr;}
		//for(int i=0;i<=L+1;i++){cerr<<lxt[i]<<" ";}
		//cout<<"T"<<T<<":"<<sxt[L]<<"/"<<L<<"\n";
		memset(qj,0,sizeof(qj));
		cntqj=0;
		for(int i=1;i<=n;i++){
			int d=c[i].d;
			int v=c[i].v;
			int a=c[i].a;
			if(v<=V and a<=0){continue;}
			int spg=0;//表示超速时所在位置 
			//对于加速车辆
			if(sxt[d]==L+1)continue;
			if(a==0){
				if(v>V){
					ans++;
					//cerr<<"第"<<i<<"辆将会在"<<sxt[d]<<"等于限速\n";
					qj[cntqj++]=(bookmark){d,L+1};
				}
			}else if(a>0){
				if(v>V){spg=d;}
				else{spg=d+(V*V-v*v)/(a*2)+1;}

				if(spg<d)spg=d;if(spg>L)spg=L;
				//if(i==3)cout<<sxt[spg]<<"\n";
				if(sxt[spg]==L+1){continue;}
				//cerr<<"第"<<i<<"辆将会在"<<sxt[spg]<<"等于限速\n";
				ans++;
				qj[cntqj++]=(bookmark){spg-1,L+1};
			}else if(a<0){
				//对于减速车辆
				if(v<=V){continue;}
				spg=d;
				if(spg<d)spg=d;if(spg>L)spg=L;
				int bcs=d+(V*V-v*v)/(a*2)+1;
				if(sxt[spg]>=bcs)continue;
				if(sxt[spg]==L+1 or sxt[spg]<d){continue;}
				ans++;
				//cerr<<"第"<<i<<"辆将会在"<<sxt[spg]<<"等于限速\n";
				qj[cntqj++]=(bookmark){d,min(bcs-1,L+1)};
			}
	 	}
	 	int ans2=0;
		sort(qj,qj+cntqj,cmp);
		//for(int i=0;i<cntqj;i++){cerr<<i<<": "<<qj[i].l<<"~"<<qj[i].r<<"    "<<lxt[qj[i].r]<<"\n";}
		int i=0;
		while(i<cntqj){
			//cerr<<"i="<<i<<"\n";
			//cerr<<qj[i].r<<" "<<lxt[qj[i].r]<<"\n";
			int rp=lxt[qj[i].r];
			//if(rp<qj[i].l){i++;continue;}
			//if(rp==-1)cerr<<"ERROR on"<<i<<"\n";
			ans2++;
			while(qj[i].l<=rp and qj[i].r>=rp)i++;
		}
		cout<<ans<<" "<<m-ans2<<"\n";
		
	}
} 

