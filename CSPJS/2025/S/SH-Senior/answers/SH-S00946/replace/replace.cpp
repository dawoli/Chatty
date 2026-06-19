#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
string RP(string SA,int x,string SB1,string SB2){
	string SC=SA;
	for(int ind=0;ind<SB1.length();ind++){
		if(SC[x+ind]!=SB1[ind])return "";
		else SC[x+ind]=SB2[ind];
	}
	return SC;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
	string S1[MAXN],S2[MAXN];
	for(int i=0;i<n;i++){
		cin>>S1[i]>>S2[i];
	}
	for(int i=0;i<q;i++){
	
		string A;
		string B;
		cin>>A>>B;
		long long ans=0;
		for(int x=0;x<A.length();x++){
			for(int o=0;o<n;o++){
				if(RP(A,x,S1[o],S2[o])==B){
					ans+=1;
				}
			}
		}
		cout<<ans<<endl;
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
