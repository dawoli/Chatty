#include<bits/stdc++.h>
using namespace std;
int n,q;
struct change{
	string s1,s2;
}s[50005];
int find(string s,string to){
	int len=to.size();
	///cout<<s<<" "<<to;
	for(int i=0;i<s.size()-len+1;i++){
		//cout<<1;
		bool b=1;
		for(int j=0;j<len;j++){
			if(to[j]!=s[j+i]){
				//printf("%c %c \n",to[j],s[j+i]);
				b=0;break;
			}
		}
		//cout<<i;
		if(b){
			return i;
		}
	}
	return -1;
}
int main() {
	//½â×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s[i].s1>>s[i].s2;
	}
	if(n>200005){
		while(q--){
			string t,to;
			cin>>t>>to;
			printf("0\n");
		}
		return 0;
	}
	while(q--){
		int ans=0;
		string t,to;
		cin>>t>>to;
		for(int i=1;i<=n;i++){
			int an=find(t,s[i].s1);
			if(an!=-1){
				string tt=t;
				for(int j=an;j<an+s[i].s1.size();j++){
					 tt[j]=s[i].s2[j-an];
				//cout<<tt<<endl;
				}
				if(tt==to) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
