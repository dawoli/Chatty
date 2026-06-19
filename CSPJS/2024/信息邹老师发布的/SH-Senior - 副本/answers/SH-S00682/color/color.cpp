#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;
const int N=200050;
const int M=1000060;
int t,n;
int s[N];
int buc[M],score;
set<int>st;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(buc,0,sizeof(buc));
		st.clear();
		score=0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			buc[s[i]]++;
		}
		for(int i=0;i<n;i++)if(buc[s[i]]==1)buc[s[i]]=0;
		for(int i=0;i<n;i++){
			if(buc[s[i]]--){
				if(st.find(s[i])!=st.end()){
					score+=s[i];
					if(!buc[s[i]]){
						st.erase(st.find(s[i]));
					}
				}
				else{
					st.insert(s[i]);
					if(st.size()>2){
						st.erase(min_element(st.begin(),st.end()));
					}
				}
			}
		}
		cout<<score<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
