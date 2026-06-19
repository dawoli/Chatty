#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200009],s2[200009],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int k=t1.size(),l=-1,r=-1,cnt=0;
		for(int i=0;i<k;i++)
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		for(int i=k-1;i>=0;i--)
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		int len=r-l+1;
		string st1=t1.substr(l,len),st2=t2.substr(l,len);
		for(int i=1;i<=n;i++){
			if(s1[i].size()<len)continue;
			int st=s1[i].find(st1);
			if(st==-1)continue;
			int ed=st+len-1;
			if(s2[i].substr(st,len)==st2){
				int flag=1;
				for(int x=0;x<s1[i].size();x++)
					if(x<st||x>ed)
						if(s1[i][x]!=s2[i][x])
							flag=0;
				cnt+=flag;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
