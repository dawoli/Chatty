#include<bits/stdc++.h>
using namespace std;
const int N=200009,C=5000009;
map<string,string> sub;
map<string,int> num;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		char x[C],y[C];
		int s,l;
		cin>>s1>>s2;
		for(int i=0;i<s1.length();i++){
			if(s1[i]!=s2[i]){
				s=i;
				break;
			}
		}
		for(int i=s1.length()-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				l=i;
				break;
			}
		}
		for(int i=s;i<=l;i++)
			x[i-s]=s1[i],y[i-s]=s2[i];
		sub[x]=y;
		num[y]++;
		//cout<<x<<endl<<y<<endl;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		char x[C],y[C];
		int s,l;
		cin>>s1>>s2;
		for(int i=0;i<s1.length();i++){
			if(s1[i]!=s2[i]){
				s=i;
				break;
			}
		}
		for(int i=s1.length()-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				l=i;
				break;
			}
		}
		for(int i=s;i<=l;i++)
			x[i-s]=s1[i],y[i-s]=s2[i];
		if(sub[x]==y) cout<<num[y]<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
