#include<bits/stdc++.h>

using namespace std;

ifstream fin("sticks.in");
ofstream fout("sticks.out");
#define cin fin
#define cout fout

#define ssiz(x) (signed)x.size()

const int N=1e5+9;
const int B=4e2;
const string inf="-1";
const int c[10]={6,2,5,5,4,5,6,3,7,6};

string f[N],g[N];
void ChMin(string &s,string t){
	if(s==inf) s=t;
	else if(ssiz(t)<ssiz(s)) s=t;
	else if(ssiz(t)==ssiz(s)&&t<s) s=t;
}

int main(){
	for(int i=1;i<=B;i++){
		f[i]=g[i]=inf;
		for(int j=0;j<10;j++){
			if(i<c[j]) continue ;
			string tmp="";
			tmp+=char(j+'0');
			if(j) ChMin(f[i],tmp+g[i-c[j]]);
			ChMin(g[i],tmp+g[i-c[j]]);
		}
	}
	
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		string tmp;
		while(n>B) n-=c[8],tmp.push_back('8');
		cout<<f[n]+tmp<<endl;
	}
	
	return 0;
}
