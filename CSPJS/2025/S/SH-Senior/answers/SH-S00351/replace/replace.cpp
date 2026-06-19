#include<bits/stdc++.h>
#include<set>
using namespace std;
int n,q;
string ss[200005][4];
struct sh{
	string sa,sb;
	bool operator<(const sh &ssh)const{
		if(sa<ssh.sa){
			return 1;
		}
		if(sa>ssh.sa){
			return 0;
		}
		if(sb<ssh.sb){
			return 1;
		}
		return 0;
	}
};
map<sh,vector<int> > m;
bool maa(string &ssa,string &ssb,string &saa,string &sab){
	if(ssa.size()<saa.size()){
		return 0;
	}
	if(ssb.size()<sab.size()){
		return 0;
	}
	for(int i=saa.size()-1;i>=0;i--){
		int ii=i-saa.size()+ssa.size();
		if(ssa[ii]!=saa[i]){
			return 0;
		}
	}
	for(int i=0;i<sab.size();i++){
		if(ssb[i]!=sab[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string sa,sb;
		cin>>sa>>sb;
		int j,ka;
		for(j=0;j<sa.size()&&sa[j]==sb[j];j++){
			ss[i][0]+=sa[j];
		}
		ka=j;
		for(int k=j;k<sa.size();k++){
			if(sa[k]!=sb[k]){
				ka=k;
			}
		}
		for(int k=j;k<=ka;k++){
			ss[i][1]+=sa[k];
			ss[i][2]+=sb[k];
		}
		for(int k=ka+1;k<sa.size();k++){
			ss[i][3]+=sa[k];
		}
		sh ssh;
		ssh.sa=ss[i][1];
		ssh.sb=ss[i][2];
		m[ssh].push_back(i);
	}
	for(int i=0;i<q;i++){
		string sa,sb;
		cin>>sa>>sb;
		if(sa.size()!=sb.size()){
			cout<<0<<endl;
		}
		else{
			int j,ka;
			string sg[4];
			for(j=0;j<sa.size()&&sa[j]==sb[j];j++){
				sg[0]+=sa[j];
			}
			ka=j;
			for(int k=j;k<sa.size();k++){
				if(sa[k]!=sb[k]){
					ka=k;
				}
			}
			for(int k=j;k<=ka;k++){
				sg[1]+=sa[k];
				sg[2]+=sb[k];
			}
			for(int k=ka+1;k<=sa.size();k++){
				sg[3]+=sa[k];
			}
			sh ssh;
			ssh.sa=sg[1];
			ssh.sb=sg[2];
			if(m.find(ssh)!=m.end()){
				vector<int> v=m[ssh];
				int ans=0;
				for(int jj=0;jj<v.size();jj++){
					if(maa(sg[0],sg[3],ss[v[jj]][0],ss[v[jj]][3])){
						ans++;
					}
				}
				cout<<ans<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
