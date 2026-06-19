#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
int t,n,k,q;
int cnt[200010]={};
vector <int> s[100000]={};
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	int a;
	int l,r,c,f;
	
	while (t--){
		memset(cnt,0,200010);
		cin>>n>>k>>q;
		for (int i=0;i<n;i++){
			s[i].clear();
			cin>>l;
			for (int j=0;j<l;j++){
				cin>>a;
				cnt[a]++;
				s[i].push_back(a);
			}
		}
		for (int i=0;i<q;i++){
			cin>>r>>c;
			if (cnt[c]<=0||cnt[1]<=0){
				cout<<0<<endl;
				continue;
			}else{
				if (k==int(2e5))f=1;
				else{
					f=0;
					if (r==1){
						for (int i=0;i<n;i++){
							for (int j=0;j<s[i].size();j++){
								if (s[i][j]==c){
									for (int p=j;p>max(j-k,-1);p--){
										if (s[i][p]==1){
											f=1;
											break;
										}
									}
								}
								if (f)break;
							}
							if (f)break;
						}
					}else{
						for (int i=0;i<n;i++){
							for (int j=0;j<s[i].size();j++){
								if (s[i][j]==c){
									for (int p=j-1;p>max(j-k,-1);p--){
										if (cnt[s[i][p]]>1){
											f=1;
											break;
										}
									}
								}
								if (f)break;
							}
							if (f)break;
						}
					}
				}
				if (f)cout<<1<<endl;
				else cout<<0<<endl;
			}
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//O(nlogn)
