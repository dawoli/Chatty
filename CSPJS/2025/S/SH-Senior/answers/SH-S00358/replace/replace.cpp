#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
string s1[N],s2[N],t1,t2;
int lth[N],l1,l2,lx0[N],rx0[N];
int n,q,mpcnt=0,vncnt=0;
map<string,int> mp;
map<string,int> mpx[N];
vector<int> vn[N];
void mx(int x){
	int l=0,r=lth[x]-1;
	for(l=0;l<lth[x];l++){
		if(s1[x][l]!=s2[x][l])
			break;
	}
//	cout<<lth[x]<<endl;
	if(l==lth[x])
		return ;
	for(r=lth[x]-1;r>=0;r--){
		if(s1[x][r]!=s2[x][r])
			break;
	}
//	cout<<l<<' '<<r<<endl;
	lx0[x]=l,rx0[x]=r;
	string x1=s1[x].substr(l,r-l+1),x2=s2[x].substr(l,r-l+1);
	int xx1,xx2;
	if(!mp.count(x1)){
		mpcnt++;
		xx1=mp[x1]=mpcnt;
	}
	else{
		xx1=mp[x1];
	}
	if(!mpx[xx1].count(x2)){
		vncnt++;
		xx2=mpx[xx1][x2]=vncnt;
	}
	else{
		xx2=mpx[xx1][x2];
	}
//	cout<<x1<<' '<<x2<<endl;
	vn[xx2].push_back(x);
}
bool chk(string t,int l,int r,int x){
	int lxx=t.size();
	for(int i=lx0[x]-1,j=l-1;i>=0;i--,j--){
		if(j<0||t[j]!=s1[x][i])
			return false;
	}
	for(int i=rx0[x]+1,j=r+1;i<lth[x];i++,j++){
		if(j>=lxx||t[j]!=s1[x][i])
			return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		lth[i]=s1[i].size();
		mx(i);
	}
//	cout<<vn[101].size()<<endl; 
	while(q--){
		cin>>t1>>t2;
		l1=t1.size(),l2=t2.size();
		if(l1!=l2){
			cout<<"0\n";
			continue;
		}
		int l,r;
		for(l=0;l<l1;l++){
			if(t1[l]!=t2[l])
				break;
		}
		for(r=l1-1;r>=0;r--){
			if(t1[r]!=t2[r])
				break;
		}
		string x1=t1.substr(l,r-l+1),x2=t2.substr(l,r-l+1);
//		cout<<x1<<endl<<x2<<endl;
		int xx1,xx2;
		if(!mp.count(x1)){
			cout<<"0\n";
			continue;
		}
		xx1=mp[x1];
		if(!mpx[xx1].count(x2)){
			cout<<"0\n";
			continue;
		}
		xx2=mpx[xx1][x2];
		int lzx=vn[xx2].size(),x0,ans=0;
		for(int zz=0;zz<lzx;zz++){
			x0=vn[xx2][zz];
			if(chk(t1,l,r,x0)){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
