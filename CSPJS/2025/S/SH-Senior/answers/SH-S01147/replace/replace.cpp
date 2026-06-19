#include<bits/stdc++.h>
using namespace std;
int n,q,d=1,dd=1,l,w,ans,ww,o,oo,h;
string s,ss;
struct p{
	vector<int> x;
	int z[30];
};
vector<p> ct,ctt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p a;
	a.x.clear();
	for(int i=0;i<=29;++i)
		a.z[i]=0;
	ct.push_back(a);
	ctt.push_back(a);
	cin>>n>>q;
	for(int j=1;j<=n;++j){
		cin>>s>>ss;
		l=s.size();
		w=0,ww=0;
		for(int i=0;i<l;++i){
			if(ct[w].z[s[i]-'a']==0){
				ct[w].z[s[i]-'a']=d;
				d++;
				ct.push_back(a);
			}
			if(ctt[ww].z[ss[i]-'a']==0){
				ctt[ww].z[ss[i]-'a']=dd;
				dd++;
				ctt.push_back(a);
			}
			w=ct[w].z[s[i]-'a'];
			ww=ctt[ww].z[ss[i]-'a'];
		}
		ct[w].x.push_back(j);
		ctt[ww].x.push_back(j);
	}
	while(q--){
		cin>>s>>ss;
		l=s.size();
		ans=0;
		h=-1;
		for(int i=l-1;i>=0;i--)
			if(s[i]!=ss[i]){
				h=i;
				break;
			}
		for(int i=0;i<l;++i){
			w=0,ww=0;
			if(i!=0&&s[i-1]!=ss[i-1])
				break;
			for(int j=i;j<l;++j){
				if(ct[w].z[s[j]-'a']==0)
					break;
				if(ctt[ww].z[ss[j]-'a']==0)
					break;
				w=ct[w].z[s[j]-'a'];
				ww=ctt[ww].z[ss[j]-'a'];
				if(j>=h&&ct[w].x.size()!=0&&ctt[ww].x.size()!=0){
					o=0,oo=0;
					while(o<ct[w].x.size()&&oo<ctt[ww].x.size()){
						while(o<ct[w].x.size()&&ct[w].x[o]<ctt[ww].x[oo])
							o++;
						while(oo<ctt[ww].x.size()&&ct[w].x[o]>ctt[ww].x[oo])
							oo++;
						if(ct[w].x[o]==ctt[ww].x[oo]){
							ans++;
							o++;
							oo++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
