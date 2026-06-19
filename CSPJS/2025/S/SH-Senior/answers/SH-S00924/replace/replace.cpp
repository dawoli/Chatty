#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,q,pre[N],succ[N];
string p1,p2,s1[N],s2[N];
bool check(int p,int s){
	for(int i=0;i<s1[s].size();i++){
		if(s1[s][i]!=p1[p+i]||s2[s][i]!=p2[p+i])return 0;
	}
	if(p!=0&&pre[p-1]!=p){
		return 0;
	}
	if(p+s1[s].size()!=p1.size()&&succ[p+s1[s].size()]!=(p1.size()-(p+s1[s].size()))){
		return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>p1>>p2;
		if(p1.size()!=p2.size()){
			cout<<"0"<<endl;
			continue;
		}
		pre[0]=(p1[0]==p2[0]);
		for(int i=1;i<p1.size();i++){
			pre[i]=pre[i-1]+(p1[i]==p2[i]);
		}
		succ[p1.size()-1]=(p1[p1.size()-1]==p2[p1.size()-1]);
		for(int i=p1.size()-2;i>=0;i--){
			succ[i]=succ[i+1]+(p1[i]==p2[i]);
		}
		int ans=0;
		for(int i=0;i<p1.size();i++){
			for(int j=1;j<=n;j++){
				if(i+s1[j].size()-1>=min(p1.size(),p2.size()) ) continue;
				ans+=check(i,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
