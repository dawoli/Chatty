#include <bits/stdc++.h>
using namespace std;
int n,q;
struct String{
	string a,b;
	int l1,l2;
}str[200010];
bool cmp(const String&a,const String &b){
	if(a.l1<=b.l1) return true;
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>str[i].a>>str[i].b;
		str[i].l1=str[i].a.size(),str[i].l2=str[i].b.size();
	}
	sort(str,str+n,cmp);
	for(int i=0;i<q;i++){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int j=0;j<a.size();j++){
			for(int k=0;k<n;k++){
				if(j+str[k].l1>a.size()) break;
//				if(str[k].l1>a.size()||j+str[k].l1>n) continue;
				string tmp1="",tmp2="",tmp3="";
				if(a.size()==str[k].l1){
					tmp1=a.substr(0,max(0,j));
					tmp2=a.substr(j,min(j+str[k].l1,(int)a.size()));
					tmp3=a.substr(min((int)a.size(),j+str[k].l1),a.size());
//					cerr<<"FUNC1"<<tmp1<<"-"<<tmp2<<"-"<<tmp3<<"-j="<<j<<" k="<<k;
//					cerr<<"len="<<str[k].l1<<" str[k]="<<str[k].a<<" "<<str[k].b;
//					cerr<<endl<<min(j+str[k].l1,(int)a.size())<<endl;
				}
				else{
					tmp1=a.substr(0,max(0,j));
					tmp2=a.substr(j,min(j+str[k].l1-1,(int)a.size())-1);
					tmp3=a.substr(min((int)a.size(),j+str[k].l1),a.size());
//					cerr<<"FUNC2"<<tmp1<<"-"<<tmp2<<"-"<<tmp3<<"-j="<<j<<" k="<<k;
//					cerr<<"len="<<str[k].l1<<" str[k]="<<str[k].a<<" "<<str[k].b;
//					cerr<<endl<<min(j+str[k].l1-1,(int)a.size())<<" "<<a.size()<<endl;
				}
				if(tmp2==str[k].a){
					string s=tmp1+str[k].b+tmp3;
//					cerr<<s;
					if(s==b) ans++;/*cerr<<"---YES"<<endl;*/
				}
//				cerr<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
