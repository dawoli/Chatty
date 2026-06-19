#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[10005][3],s2,s3;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i][1]>>s1[i][2];
	}
	while(q--){
		cin>>s2>>s3;
		int s=0,ff=1;
		for(int i=1;i<=n;i++){
			queue <char> q;
			int fff=0;
			for(int j=0;j<s2.size()-s1[i][1].size();j++){
				int f=1;
				for(int k=0;k<s1[i][1].size();k++){
					if(s1[i][1][k]!=s2[j+k]){
						f=0;
						break;
					}
				}
				if(f=0){
					q.push(s2[j]);
				}else{
					for(int k=0;k<s1[i][1].size();k++){
						q.push(s1[i][2][k]);
					}
					for(int k=q.size();k<s2.size();k++){
						q.push(s2[k]);
					}
					fff=1;
					break;
				}
			}
			if(fff){
				cout<<s3.size()<<" "<<q.size()<<endl;
				while(!q.empty()){
					char x=q.front();
					if(s3[s3.size()-q.size()]!=x){
						ff=0;
						break;
					}
					q.pop();
				}
				s+=ff;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
