#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string> >a[26];
signed main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[s1[0]-'a'].push_back(make_pair(s1,s2));
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		for(int i=0;i<s1.length();i++){
			for(int p=0;p<a[s1[i]-'a'].size();p++){ 
				pair<string,string>snake=a[s1[i]-'a'][p];
//				cout<<snake.first<<endl;
				if(snake.first.length()-snake.second.length()!=s1.length()-s2.length()) continue;
				bool flag=false;
//				cout<<"Yes"<<endl;
				for(int j=0;j<snake.first.length();j++){
					if(s1[i+j]!=snake.first[j]) flag=true;
					if(flag) {
//						cout<<s1[i+j]<<" "<<snake.first[j]<<endl;
						break;
					}
				}if(flag)continue;
//				cout<<"YES"<<endl;
				string s3="";
				for(int j=0;j<i;j++) s3+=s1[j];
				s3+=snake.second;
				for(int j=i+snake.first.length();j<s1.length();j++) s3+=s1[j];		
				if(s3==s2) ans++;
//				if(s3==s2) cout<<s3<<" HERE!"<<endl;
//				else cout<<s3<<" NOT HERE!"<<endl;
			}
		}printf("%d\n",ans);
	}	return 0;
}
