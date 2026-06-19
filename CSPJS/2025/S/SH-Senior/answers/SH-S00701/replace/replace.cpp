#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][3];
string t1,t2;
int ans=0;
int cnta=0,cntb=0;
bool is_spec(string str){
	cnta=0,cntb=0;
	for(int i=0;i<str.size();i++){
		if(str[i]!='a'&&str[i]!='b')	return 0;
		if(str[i]=='a')	++cnta;
		else ++cntb;
		if(cntb>1)	return 0;
	}
	if(cntb!=1)	return 0;
	if(cnta==0||cntb==0)	return 0;
	return 1;
}
bool check_easy=1,check_A=1,check_B=1;
void solve_A(){
	ans=0;
	for(int i=1;i<=n;i++){
		int l=s[i][1].size();
		int lt=t1.size();
		for(int j=0;j+l-1<lt;j++){
//			cout<<"YES!"<<endl;
//			cout<<t1.substr(j,l)<<" "<<s[i][1]<<endl;
			if(t1.substr(j,l)!=s[i][1])	continue;
			string x=t1.substr(0,j);
			string y=s[i][2];
			string z;
			if(j+l==lt+1)	z="";
			else z=t1.substr(j+l,lt-j-l+1);
//			cout<<"Check A:"<<j<<" "<<s[i][1]<<" "<<s[i][2]<<" "<<x<<" "<<y<<" "<<z<<endl;
			if(t2==x+y+z)	ans++;
		}
	}
	printf("%d\n",ans);
}
void solve_hard(){
}
map<int,int> mp;
void solve_B(){
	mp.clear();
	int pos1,pos2;
	int post1,post2;
	for(int j=0;j<t1.size();j++){
			if(t1[j]=='b'){
				post1=j;
				break;
			}
	}
	for(int j=0;j<t2.size();j++){
		if(t2[j]=='b'){
			post2=j;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]=='b'){
				if(t1.size()-post1<s[i][1].size()-j)	continue;
				if(post1<j)	continue;
				pos1=j;
				break;
			}
		}
		for(int j=0;j<s[i][2].size();j++){
			if(s[i][2][j]=='b'){
				if(t2.size()-post2<s[i][2].size()-j)	continue;
				if(post2<j)	continue;
				pos2=j;
				break;
			}
		}
		mp[pos1-pos2]++;
	}
	printf("%d\n",mp[post1-post2]);
	return;
}
void solve(){
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(!(n<=100&&q<=100))	check_easy=0;
	if(q!=1)	check_A=0;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		if(!is_spec(s[i][1])||!is_spec(s[i][2]))	check_B=0;
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");//10pts
			continue;
		}
		if(check_A)	solve_A();//20pts
		else if(check_B&&is_spec(t1)&&is_spec(t2))	solve_B();//10pts
		else if(check_easy)	solve_hard();
		else solve();
	}
	return 0;
}
