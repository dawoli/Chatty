#include<bits/stdc++.h>

using namespace std;

ifstream fin("poker.in");
ofstream fout("poker.out");
#define cin fin
#define cout fout

int n;

int main(){
	map<char,int> a,b;
	for(char i='2';i<='9';i++) a[i]=i-'0';
	a['T']=10,a['J']=11,a['Q']=12,a['K']=13,a['A']=1;
	b['S']=1,b['H']=2,b['C']=3,b['D']=4;
	vector<vector<int>> c(5,vector<int>(14,0));
	
	cin>>n;
	while(n--){
		char x,y;
		cin>>x>>y;
		c[b[x]][a[y]]=1;
	}
	
	int cnt=0;
	for(int i=1;i<=4;i++) for(int j=1;j<=13;j++) cnt+=!c[i][j];
	cout<<cnt<<endl;
	
	return 0;
}
