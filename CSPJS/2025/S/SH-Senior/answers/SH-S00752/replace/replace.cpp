#include<bits/stdc++.h>
using namespace std;
int N,M;
string A,B;
map<string,string>Mp;
map<string,bool>P;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>A>>B;
		Mp[A]=B;
		P[A]=true;
	}
	for(int i=1;i<=M;i++){
		cin>>A>>B;
		if(A.size()!=B.size()){
			printf("0\n");
			continue;
		}
		int Ans=0;
		string X="",Y="";
		string Z[100000];
		Z[A.size()]="";
		for(int i=A.size()-1;i>=0;i--) Z[i]=A[i]+Z[i+1];
		for(int i=0;i<A.size();i++){
			Y="";
			for(int j=i;j<A.size();j++){
				Y+=A[j];
				if(P[Y]&&X+Mp[Y]+Z[j+1]==B) Ans++;
			}
			X+=A[i];
		}
		printf("%d\n",Ans);
	}
	return 0;
}
