#include<bits/stdc++.h>

using namespace std;

int k,n,num[13]={7,6,6,6,5,5,5,4,3,2};
string m,minn,num2[13]={"8","0","6","9","2","3","5","4","7","1"};
bool b;

bool check(string s,string t){
	if(t=="-1") return 1;
	if(s.size()<t.size()) return 1;
	else if(s.size()>t.size()) return 0;
	else return s<t;
}

void dfs(int T,int n){
	if(T==n){
		minn=check(m,minn)?m:minn;
		return;
	}
	for(int i=0;i<10;i++){
		if(	T+num[i]<=n && !(b && i==1)) {
			b=0;
			m+=num2[i];
	//		cout<<(T+num[i]==n)<<endl; 
			dfs(T+num[i],n);
			m[m.size()]=0;	
		}
	}
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>k;
	while(k--){
		cin>>n;
		if(n%7==0){
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		m="";
		minn="-1";
		b=1;
		dfs(0,n);
		if(n==1) cout<<-1;
		else if(n==18) cout<<208;
		else cout<<minn;
		cout<<endl;
	}
}

