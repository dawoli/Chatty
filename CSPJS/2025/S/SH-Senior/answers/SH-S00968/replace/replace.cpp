#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string ln1[n],ln2[n];
	for (int i=0;i<n;i++){
		cin>>ln1[i]>>ln2[i];
	}
	for (int i=0;i<q;i++){
		int ans=0;
		string q1,q2;
		cin>>q1>>q2;
		// 换第几个 
		for (int j=0;j<n;j++){
			// 从哪开始 
			for (int k=0;k<q1.size()-ln1[j].size()+1;k++){
				// 判断 
				int tf=1;
				for (int l=0;l<ln1[j].size();l++){
					if (ln1[j][l]!=q1[k+l]){
						tf=0;
						break;
					}
				}
				tf=1;
				if (tf){
					for (int l=0;l<q1.size();l++){
						if (l<k||l>=k+ln1[j].size()){
							if (q1[l]!=q2[l]){
								tf=0;
								break;
							}		
						}
						else{
							if (ln2[j][l-k]!=q2[l]){
								tf=0;
								break;
							}
						}
					}
				}
				ans+=tf;
				if (tf==1){
					break;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
