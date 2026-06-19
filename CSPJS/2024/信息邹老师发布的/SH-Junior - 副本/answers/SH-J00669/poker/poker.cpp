#include<bits/stdc++.h>
using namespace std;
bool a[5][50];
short b[300],c[300],d[5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	b['D']=1;b['C']=2;b['H']=3;b['S']=4;
	for (int i = 2; i <= 9; i++) c[i+'0']=i;
	c['A']=1;c['T']=10;c['J']=11;c['Q']=12;c['K']=13;
	int n;
	cin>>n;
	while (n--){
		string s;
		cin>>s;
		if (!a[b[s[0]]][c[s[1]]]){
			a[b[s[0]]][c[s[1]]]=1;
			d[b[s[0]]]++;
		}
	}
	cout<<52-d[1]-d[2]-d[3]-d[4];
	return 0;
}
