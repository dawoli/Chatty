#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q,l,cnt=0;
	string t1,t2,x;
	cin>>n>>q;
	if(n>=1e4){
		for(int i=1;i<=q;i++){
			cout<<"0\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		x=t1;
		l=t1.size();
		for(int i=1;i<=n;i++){
			for(int j=0,k=0;j<l;j++){
				if(t1[j]==s1[i][k]){
					while(t1[j]==s1[i][k]){
						t1[j]=s2[i][k];
						j++;k++;
					}
					if(k!=s1[i].size()-1) k=0;
					if(t1==t2) cnt++;
					t1=x;
				}
			}
		}
		cout<<cnt<<"\n";
		cnt=0;
	}
	return 0;
}

