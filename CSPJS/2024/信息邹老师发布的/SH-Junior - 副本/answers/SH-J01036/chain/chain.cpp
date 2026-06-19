#include<iostream>
#include<vector>
using namespace std;
int t;
int n,k,q;
int l,tmp_wds;
vector<int> pl_words[100010];
int td_r[100010],td_c[100010];
int bgn,ed,tmp_cnt;
void fuc(int i){
	bgn=1;
	ed=td_c[i];
	for(int j=0;j<n;j++){
		tmp_cnt=0;
		for(int k=0;k<pl_words[j].size();k++){
			if(tmp_cnt==0 && pl_words[j][k]==bgn){
				tmp_cnt=1;
			}else if(pl_words[j][k]==ed){
				if(tmp_cnt<=k){
					cout<<1<<endl;
					return;
				}else{
					tmp_cnt=0;
				}
			}
			if(tmp_cnt!=0){
				tmp_cnt++;
			}
		}
	}
	cout<<0<<endl;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>l;
			while(l--){
				cin>>tmp_wds;
				pl_words[i].push_back(tmp_wds);
			}
		}
		for(int i=0;i<q;i++){
			cin>>td_r[i]>>td_c[i];
			if(td_r[i]==1){
				fuc(i);
			}else{
				cout<<0<<endl;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
