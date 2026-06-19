#include<bits/stdc++.h>
#define FILE(X) freopen(X".in","r",stdin); freopen(X".out","w",stdout);
#define ll long long
using namespace std;
const int N=200050,L=5000060;
int n,q;
string a[N],b[N];
string t1,t2;
string s1,s2;

bool match_s(string less_,string more_,int pos) {
	for(int i=0;i<less_.size();i++) {
		if(less_[i]!=more_[pos+i]) return false;
	}
	return true;
}

bool same_s(int pos) {
	for(int i=0;i<pos;i++) if(t1[i]!=t2[i]) return false;
	for(int i=pos+s1.size();i<t1.size();i++) if(t1[i]!=t2[i]) return false;
	return true;
}

bool check(int i) {
	s1=a[i],s2=b[i];
	if(t1.size()<s1.size()) return false;
	for(int i=0;i<=t1.size()-s1.size();i++) {
		if(match_s(s1,t1,i)&&match_s(s2,t2,i)&&same_s(i)) return true;
	}
	return false;
}

int main() {
	FILE("replace");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++) {
		cin>>a[i]>>b[i];
	}
	while(q--) {
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) { cout<<0<<"\n"; continue; }
		int cnt=0;
		for(int i=0;i<n;i++) {
			if(check(i)) cnt++;
//				cout<<cnt<<"\n"; // ต๗สิ  
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
