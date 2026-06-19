#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q,l;
	scanf("%d",&t);
	while£¨t--){
		scanf("%d%d%d",&n,&k,&q)
		vector<vector<int>> ll;
		for(int i=0; i<n; i++){
			cin>>l;
			vector<int> l;
			for(int j=0; j<l; j++){
				int tmp;
				cin>>tmp;
				l.push_back(tmp);
			}
			ll.push_back(l);
		}
		vector<int>r; vector<int>c;		
		for(int i=1; i<q; i++){
			int tp,tp2;
			cin>>tp>>tp2;
			r.push_back(tp); c.push_back(tp2);
		}	
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
