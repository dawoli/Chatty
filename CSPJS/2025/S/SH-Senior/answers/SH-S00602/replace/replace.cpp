#include<bits/stdc++.h>
using namespace std;
string s1,s2;
struct re{
	string s1,s2;
}r[200010];
int n,q,cnt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=0;i<n;i++){
		cin>>r[i].s1>>r[i].s2;
	}for (int i=0;i<q;i++){
		cnt=0;
		cin>>s1>>s2;
		for (int j=0;j<n;j++){
			int k=0;
			while (s1.find(r[j].s1,k)!=string::npos){
				if (s1.substr(0,s1.find(r[j].s1,k))!=s2.substr(0,s1.find(r[j].s1,k))){
					break;
				}if ((s2.substr(s1.find(r[j].s1,k),r[j].s2.size())==r[j].s2) && s2.substr(s1.find(r[j].s1,k)+r[j].s2.size(),s2.size()-s1.find(r[j].s1,k)+r[j].s2.size()+1)==s1.substr(s1.find(r[j].s1,k)+r[j].s2.size(),s2.size()-s1.find(r[j].s1,k)+r[j].s2.size()+1)){
					cnt++;
				}k=s1.find(r[j].s1,k)+1;
			}
		}cout<<cnt<<endl;
	}
}
