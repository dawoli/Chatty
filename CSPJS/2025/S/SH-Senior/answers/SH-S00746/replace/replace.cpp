#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+10,Maxnn=5e6+10;
struct node{string x,y; int z;}a[2*Maxn];
int n,q,i,j,k,p,kmp[Maxnn],ans[Maxn];
string s[Maxn][3],t[Maxn][3];
vector<int>e;
bool cmp(node xx,node yy){
	if(xx.x==yy.x){
		if(xx.y==yy.y) return xx.z<yy.z;
		else return xx.y<yy.y; 
	}
	else return xx.x<yy.x;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		if(s[i][1].size()!=s[i][2].size()||s[i][1]==s[i][2]) continue;
		int l=0,r=s[i][1].size()-1;
		while(s[i][1][l]==s[i][2][l]) l++;
		while(s[i][1][r]==s[i][2][r]) r--;
		string d[3];
		d[1]=" "; d[2]=" ";
		for(j=l;j<=r;j++) d[1]+=s[i][1][j],d[2]+=s[i][2][j];
		a[++p].x=d[1]; a[p].y=d[2]; a[p].z=i;
	}
	for(i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size()) continue;
		bool flag=true;
		int l=0,r=0;
		for(j=0;j<t[i][1].size();j++){
			if(t[i][1][j]!=t[i][2][j]){
				if(l==0) l=j,r=j;
				else{
					if(r==j-1) r++;
					else{
						flag=false; break;
					}
				}
			}
		}
		if(!flag) continue;
		string d[3];
		d[1]=" "; d[2]=" ";
		for(j=l;j<=r;j++) d[1]+=t[i][1][j],d[2]+=t[i][2][j];
		a[++p].x=d[1]; a[p].y=d[2]; a[p].z=i+n;
	}
	for(i=1;i<=n;i++) s[i][1]=" "+s[i][1];
	for(i=1;i<=q;i++) t[i][1]=" "+t[i][1];
	sort(a+1,a+p+1,cmp);
	int cnt=0;
	for(i=1;i<=p;i++){
		if(a[i].z<=n){
			if(i==1||a[i].x!=a[i-1].x||a[i].y!=a[i-1].y) e.clear();
			e.push_back(i);
		}
		else{
			if(i==1||a[i].x!=a[i-1].x||a[i].y!=a[i-1].y) e.clear();
			else{
				for(p=0;p<e.size();p++){
					int u=e[p];
					int m=s[a[u].z][1].size();
					for(k=0;k<=m;k++) kmp[k]=0;
					j=0;
					for(k=2;k<m;k++){
						while(j&&s[a[i].z][k]!=s[a[i].z][j+1]) j=kmp[j];
						if(s[a[i].z][k]==s[a[i].z][j+1]) j++;
						kmp[k]=j;
					}
					m=t[a[i].z-n][1].size(); j=0;
					for(k=1;k<m;k++){
						while(j&&t[a[i].z][k]!=s[a[i].z][j+1]) j=kmp[j];
						if(t[a[i].z][k]==s[a[i].z][j+1]) j++;
						if(j==s[a[u].z][1].size()-1){
							ans[a[i].z-n]++; break;
						}
					}
				}
			}
		}
	}
	for(i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
}
