#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
const double acr=1e-6;
struct car{
	int d,v,a;
	double cl,cr;
	bool c;
	int pl,pr;
} s[3005];
int p[3005];
bool oc[3005];
int tmp[3005],cnt;
int ans1,ans2,aaa;

void solve1(){
	for(int i=1;i<=n;++i){
		if(s[i].a==0){
			if(s[i].v<=V) continue;
			else s[i].cl=s[i].d,s[i].cr=L;
		}
		else if(s[i].a>0){
			s[i].cl=s[i].d+(V*V-s[i].v*s[i].v)/(2.0*s[i].a)+3*acr;
			if(s[i].cl>L) s[i].cl=0;
			else s[i].cr=L;
		}
		else{
			s[i].cr=s[i].d+(V*V-s[i].v*s[i].v)/(2.0*s[i].a)-3*acr;
			if(s[i].cr<0) s[i].cr=0;
			else s[i].cl=s[i].d;
		}
		//cout<<s[i].cl<<' '<<s[i].cr<<endl;//
		if(s[i].cl*s[i].cr==0) continue;
		for(int j=1;j<=m;++j){
			if((s[i].cl<1.0*p[j]+acr)&&(s[i].cr>1.0*p[j]-acr)){
				if(!s[i].c) s[i].pl=j;
				s[i].c=1;
			}
			else if(s[i].c&&(!s[i].pr)) s[i].pr=j-1;
		}
		if(!s[i].pr&&s[i].c) s[i].pr=m;
		ans1+=s[i].c;
		//cout<<s[i].pl<<' '<<s[i].pr<<endl;//
	}
}

void solve2(){
	for(;cnt<ans1&&ans2<m;){
		for(int i=1;i<=n;++i){//²î·Ö 
			if(s[i].pl*s[i].pr==0) oc[i]=1;
			if(!oc[i]) ++tmp[s[i].pl],--tmp[s[i].pr+1];
		}
		int tp2=0,maxn=0,maxi=1;
		for(int i=1;i<=m;++i){
			tp2+=tmp[i];
			if(tp2>maxn) maxn=tp2,maxi=i;
		}
		++ans2;cnt+=maxn;
		for(int i=1;i<=n;++i){
			if(s[i].pl<=p[maxi]&&s[i].pr>=p[maxi]) oc[i]=1;
		}
	}
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	//orz
	//orz
	//orz
	cin>>T;
	for(;T--;){
		ans1=ans2=cnt=0;
		memset(s,0,sizeof(s));
		memset(p,0,sizeof(p));
		memset(oc,0,sizeof(oc));
		memset(tmp,0,sizeof(tmp));
		cin>>n>>m>>L>>V;
		if(n>3000||m>3000) continue;
		for(int i=1;i<=n;++i) scanf("%d%d%d",&s[i].d,&s[i].v,&s[i].a);
		for(int i=1;i<=m;++i) scanf("%d",p+i);
		solve1();
		solve2();
		cout<<ans1<<' '<<m-ans2<<endl;
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
