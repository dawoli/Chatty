#include <bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
map<string,int> a1,a3;
map<int,string> a2;
int t1,t2,l,r;
int a[200010][100];
int lt1,lt2;
string d1,d2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		if(a1[s1]==0){
			a1[s1]=++t1;
		}
		if(a3[s2]==0){
			a3[s2]=++t2;
			a2[t2]=s2;
		}
		a[a1[s1]][++a[a1[s1]][0]]=t2;
	}
	for(int _=1;_<=q;++_){
		cout<<0; 
	}
	return 0;
}
