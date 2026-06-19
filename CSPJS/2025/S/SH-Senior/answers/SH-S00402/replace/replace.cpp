#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
map<pii,queue<pii>> x;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		int t=0,a,b,c,d;
		cin>>s1>>s2;
		int ss=s1.size();
		for(int j=0;j<ss;j++){
			if(s1[j]=='b'){
				a=t;
				t=-1;
			}
			t++;
		}
		b=t;
		t=0;
		for(int j=0;j<ss;j++){
			if(s2[j]=='b'){
				c=t;
				t=-1;
			}
			t++;
		}
		d=t;
		x[{c-a,d-b}].push({a,b});
	}
	
	for(int i=1;i<=q;i++){
		string s1,s2;
		int t=0,a,b,c,d;
		cin>>s1>>s2;
		int ss=s1.size();
		for(int j=0;j<ss;j++){
			if(s1[j]=='b'){
				a=t;
				t=-1;
			}
			t++;
		}
		b=t;
		t=0;
		for(int j=0;j<ss;j++){
			if(s2[j]=='b'){
				c=t;
				t=-1;
			}
			t++;
		}
		d=t;
		long long cnt=0;
		for(int k=1;k<=x[{c-a,d-b}].size();k++){
			pii f=x[{c-a,d-b}].front();
			x[{c-a,d-b}].pop();
			x[{c-a,d-b}].push(f);
			if(a>=f.first&&b>=f.second){
				cnt++;
			}
		}
		printf("%ld\n",cnt);
	}
	return 0;
}
