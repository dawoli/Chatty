#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
const int maxlen=1e7+10;
int n,q,cha[maxn],cnt[maxlen];
string s1[maxn],s2[maxn],t1,t2;

bool issame(int x,string s1,string s2){
	int len=s2.length(),len1=s1.length();
	if(x+len>len1) return 0;
	//cout<<len<<" ";
	for(int i=x;i<x+len;i++){
		//cout<<s1[x]<<" "<<s2[i-x]<<"\n";
		if(s1[i]!=s2[i-x]){
			return 0;
		}
	}return 1;
}

void baoli(){
	while(q--){
		cin>>t1>>t2;
		int cnt=0;
		int len1=t1.length();
		for(int i=0;i<len1;i++){
			for(int j=1;j<=n;j++){
				int len3=s2[j].length();
				if(issame(i,t1,s1[j])){
					//cout<<i<<" "<<j<<"\n";
					bool flag=1;
					for(int x=0;x<i;x++){
						if(t1[x]!=t2[x]){
							//cout<<x<<"\n";
							flag=0;
							break;
						}
					}
					if(flag){
						for(int x=i;x<i+len3;x++){
							if(s2[j][x-i]!=t2[x]){
								//cout<<s2[j][x-i]<<" "<<t2[x]<<" "<<x<<"\n";
								flag=0;
								break;
							}
						}
					}
					if(flag){
						for(int x=i+len3;x<len1;x++){
							if(t1[x]!=t2[x]){
								//cout<<x<<"\n";
								flag=0;
								break;
							}
						}
					}
					if(flag) cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
}

bool spe(){
	for(int i=1;i<=n;i++){
		int len4=s1[i].length();
		for(int j=0;j<len4;j++){
			if(s1[i][j]!='a'&&s1[i][j]!='b'&&s2[i][j]!='a'&&s2[i][j]!='b') return 0;
		}
	}return 1;
}

void solve1(){
	for(int i=1;i<=1e7;i++){
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		int pl1,pl2;
		int len5=s1[i].length();
		for(int j=0;j<len5;j++){
			if(s1[i][j]=='b') pl1=j;
			if(s2[i][j]=='b') pl2=j;
		}
		cnt[pl1-pl2+5000000]++;
		//cout<<pl1-pl2+5000000<<"\n";
	}
	while(q--){
		cin>>t1>>t2;
		int ple1,ple2;
		int len6=t1.length();
		for(int j=0;j<len6;j++){
			if(t1[j]=='b') ple1=j;
			if(t2[j]=='b') ple2=j;
		}
		cout<<cnt[ple1-ple2+5000000]<<"\n";
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//freopen("replace3.in","r",stdin);
	//freopen("out.ans","w",stdout);
	//string x1="114514",x2="14";
	//cout<<x1[4]<<" "<<x1[5]<<" "<<x2[0]<<" "<<x2[1]<<"\n";
	//cout<<issame(4,x1,x2)<<"\n";
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(spe()){
		solve1();
	}
	else{
		baoli();
	}
}
