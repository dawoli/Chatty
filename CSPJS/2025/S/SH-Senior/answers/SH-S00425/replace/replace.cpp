#include<bits/stdc++.h>
using namespace std;
#define N 200005
struct SP{
	int l;
	string s1,s2;
	bool operator < (const SP &b) const{
		return l<b.l;
	}
}s[N];
int n,q;
string s1[N],s2[N];
int judge(string q1,string q2){
	if(q1.length()!=q2.length()){return 0;}
	int ql=q1.length();
	int ans=0;
	for(int i=0;i<ql;i++){
		int j=1,sl=1;
		while(j<=n&&sl+i-1<ql){
			string y1=q1.substr(0,i);
			string y2=q1.substr(i,sl);
			string y3=q1.substr(sl+i);
			while(s[j].l==sl){
				if(y2==s[j].s1){
					if(y1+s[j].s2+y3==q2){
						ans++;}
				}
				j++;
			}
			sl=s[j].l;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[i]=SP{(int)s1.length(),s1,s2};
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=q;i++){
		string q1,q2;
		cin>>q1>>q2;
		cout<<judge(q1,q2)<<'\n';
	}
	return 0;
}
