#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,op=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*op;
}
const int L=3e6+9;
int n,q;

struct Node{
	int nb1,nb2;
};
vector<Node> hs[2*L];
void solve(string t1,string t2){
	int n1,n2;
	for(int i=0;i<t1.size();i++){
		if(t1[i]=='b'){
			n1=i;
			break;
		}
	}
	for(int i=0;i<t2.size();i++){
		if(t2[i]=='b'){
			n2=i;
			break;
		}
	}
	int cnt=0;
	for(int i=0;i<hs[n2-n1+L].size();i++){
		if(hs[n2-n1+L][i].nb1<=n1&&hs[n2-n1+L][i].nb2<=t1.size()-n1-1){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2; 
		int nb1,nb2;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b'){
				nb1=j;
				nb2=s1.size()-j-1;
				break;
			}
		}
		int P=0;
		for(int j=0;j<s1.size();j++){
			if(s2[j]=='b'){
				P=j;
				break;
			}
		}
		int cg=P-nb1;
		hs[cg+L].push_back((Node){nb1,nb2});
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		solve(t1,t2);
	}
	return 0;
}
/*


*/
