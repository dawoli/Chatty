#include<bits/stdc++.h>
using namespace std;
int n,q;
int pos[200005][3];
int len[200005];
string s[200005][3];
string t1,t2;
bool isB=true;
void solveBF();
void solveb(){
	/*map<int,int>mp;
	for(int i=1;i<=n;i++)
		mp[s[i][1].find('b')-s[i][2].find('b')]++;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int pos1=t1.find('b');
		int pos2=t2.find('b');
		cout<<mp[pos1-pos2]<<endl;
	}*/
	solveBF();
}
void solveBF(){
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		int len=t1.size();
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			int len1=s[i][1].size();
			for(int j=0;j+len1<len+1;j++){
				if(t1.substr(j,len1)==s[i][1]){
					if(t1.substr(0,j)+s[i][2]+t1.substr(j+len1)==t2)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
			pos[i][j]=s[i][j].find('b');
			len[i]=s[i][j].size();
			if(pos[i][j]==-1)
				isB=false;
		}
	}
	solveBF();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
