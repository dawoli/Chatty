#include <bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string s1, s2;
} f[200009];
string q1,q2;

int num=0;
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<q1.length();j++){
			if(q1[j]==f[i].s1[0]){
				bool judge=1;
//				cout <<i<<" " <<j<<endl;
				for(int k=0; k<f[i].s1.length(); k++) {
					if(q1[j+k]!=f[i].s1[k]) {judge=0; break;}
				}
				if(judge){
					string temp=q1;
					for(int k=0;k<f[i].s1.length();k++) {
						temp[j+k]=f[i].s2[k];
					}
//					cout<<temp<<endl;
					if(temp==q2) num++;
				}
			}
		}
		
		
	}
}

void solve2(){
	int place1, place2;
	for(int i=0;i<q1.length();i++) {
		if(q1[i]=='b')place1=i;
		if(q2[i]=='b')place2=i;	
	}
	int askdiff=max(place1-place2,place2-place1);
	for(int i=1;i<=n;i++) {
		for(int j=0;j<f[i].s1.length();j++) {
			if(f[i].s1[j]=='b')place1=i;
			if(f[i].s2[j]=='b')place2=i;	
		}
		int actualdiff=max(place1-place2,place2-place1);
		if(askdiff==actualdiff) num++;
	}
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>f[i].s1>>f[i].s2;
	}
	while(q--) {
		num=0;
		cin>>q1>>q2;
		if(n<=100&&q<=100) solve1();
		else solve2();
		cout<<num<<endl;
	}
	return 0;
}
