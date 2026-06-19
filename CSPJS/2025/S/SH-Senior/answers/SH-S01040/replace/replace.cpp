#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,q;
string s1[N],s2[N];
vector<int> kmp[N];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	cout<<1;
	for(int i=1;i<=n;i++){
//		cout<<i<<" ";
		cin>>s1[i]>>s2[i];
//		cout<<"!!!";
//		cout<<s1[i][1]<<"!!!!";
		int j=-1;
		kmp[i].push_back(-1);
		for(int k=2;k<=(int)(s1[i].size());k++){
//			cout<<1;
			while(j>=0&&s1[i][k-1]!=s1[i][j+1]) j=kmp[i][j];
			if(s1[i][k-1]==s1[i][j+1]){
				j++;
			}
			kmp[i].push_back(j);
		}
//		for(int k=0;k<kmp[i].size();k++){
//			cout<<kmp[i][k]<<" ";
//		}
//		cout<<endl;
	}
	for(int t=1;t<=q;t++){
		string q1,q2;
		cin>>q1>>q2;
		int ans=0;
		if(q1.size()!=q2.size()){
			cout<<0<<endl;
			continue;
		}
//		int ll=0,rr=0
		for(int i=1;i<=n;i++){
//			cout<<i;
			
			if(q1.size()>=s1[i].size()){
				int j=-1;
				for(int k=1;k<=(int)(q1.size());k++){
//					cout<<
					while(j>=0&&q1[k-1]!=s1[i][j+1]) j=kmp[i][j];
					if(q1[k-1]==s1[i][j+1]){
						j++;
					}
//					cout<<j;
					if(j>=0&&j==(int)(s1[i].size()-1)){
//						cout<<j<<endl;
						bool flag=0;
						for(int l=k-1;l>=(k-(int)(s1[i].size()))&&!flag;l--){
//							cout<<i<<" "<<l<<" "<<q2[l]<<" "<<s2[i][j]<<endl;
//							cout<<l;
							if(q2[l]==s2[i][(j-(k-1-l))]) continue;
							flag=1;
						}
						for(int l=0;l<(k-(int)(s1[i].size()))&&!flag;l++){
							if(q1[l]==q2[l]) continue;
							flag=1;
						}
						for(int l=k;l<q1.size()&&!flag;l++){
							if(q1[l]==q2[l]) continue;
							flag=1;
						}
						if(!flag){
//							cout<<ans;
							ans++;
						}
						j=kmp[i][j];
//						cout<<j;
					}
//					else j=kmp[i][j+1];
				}
			}
		}
		cout<<ans<<endl;
		
//		kmp[i].push_back(-1);
		
	}
	return 0;
}
