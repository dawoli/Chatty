#include<bits/stdc++.h>
using namespace std;
vector<int> s;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m,d;
	cin>>d;
	s.insert(s.end(),d);
	for(int i=1;i<l;i++) {
		int a;
		cin>>a;
		s.insert(s.end(),a);
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<l;i++) {
		if(s[i]==d) {
			int mm=i/n,nn=i%n;
			if(mm%2) nn=n-nn-1;
			mm++,nn++;
			cout<<mm<<" "<<nn;
			return 0;
		}
	}
	for(int i=0;i<l;i++) {
		cout<<s[i];
	}
	return 0;
}
