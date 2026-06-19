#include<bits/stdc++.h>
using namespace std;
string read(){
	string res;
	char c;
	while((c=getchar())!=' ' && c!='\n') res+=c;
	return res;
}
constexpr int N=200001;
struct REP{
	string f,t;
	int df;
};
REP r[N];
vector<int> rdf;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	read();
	for(int i=0;i<n;++i) {
		r[i].f=read(),r[i].t=read();
		int st=0,ed=r[i].f.size();
		while(st<r[i].f.size() && r[i].f[st]==r[i].t[st]) st++;
		if(st<r[i].f.size() && r[i].f[st]!=r[i].t[st]) st--;
		while(ed>=st && r[i].f[ed]==r[i].t[ed]) ed--;
		if(ed<r[i].f.size() && r[i].f[ed]!=r[i].t[ed]) ed++;
		r[i].df=ed-st;
	}
	sort(r,r+n,[](REP a, REP b){ return a.df<b.df; });
	for(int i=0;i<n;++i) rdf.push_back(r[i].df);
	for(int i=0;i<q;++i){
		string q1=read(),q2=read();
		int st=0,ed=q1.size(),ans=0;
		while(st<q1.size() && q1[st]==q2[st]) st++;
		if(st<q1.size() && q1[st]!=q2[st]) st--;
		while(ed>=st && q1[ed]==q2[ed]) ed--;
		if(ed<q1.size() && q1[ed]!=q2[ed]) ed++;
		int qdf=ed-st;
		int jed=upper_bound(rdf.begin(),rdf.end(),qdf)-rdf.begin();
		for(int j=lower_bound(rdf.begin(),rdf.end(),qdf)-rdf.begin();j<jed;++j){
			size_t pos=q1.find(r[j].f);
			if(pos!=string::npos){
				ans+=(r[j].t==q2.substr(pos,r[j].f.size()));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
