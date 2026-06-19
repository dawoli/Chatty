#include<bits/stdc++.h>
using namespace std;
int t_,n_,m_,k_,x_,y_,d_,num_[1001][1001],sum_;
char map_[1001][1001];
int main(){
		freopen("explore.in","r",stdin);
		freopen("explore.in","w",stdout);
	cin>>t_;
	for(int i=1;i<=t_;i++){
		sum_=0;
		for(int j=1;j<=1000;j++){
			for(int k=1;k<=1000;k++){
				num_[j][k]=0;
			}
		}
		cin>>n_>>m_>>k_>>x_>>y_>>d_;
		for(int j=1;j<=n_;j++){
			for(int k=1;k<=m_;k++){
				cin>>map_[j][k];
			}
		}
		num_[x_][y_]=1;
		for(int j=1;j<=k_;j++){
			if(d_==0){
				if(map_[x_][y_+1]=='.'){
					y_++;
				}
				else{
					d_=(d_+1)%4;
				}
			}
			else if(d_==1){
				if(map_[x_+1][y_]=='.'){
					x_++;
				}
				else{
					d_=(d_+1)%4;
				}
			}
			else if(d_==2){
				if(map_[x_][y_-1]=='.'){
					y_--;
				}
				else{
					d_=(d_+1)%4;
				}
			}
			else{
				if(map_[x_-1][y_]=='.'){
					x_--;
				}
				else{
					d_=(d_+1)%4;
				}
			}
			num_[x_][y_]=1;
		}
		for(int j=1;j<=n_;j++){
			for(int k=1;k<=m_;k++){
				if(num_[j][k]==1){
					sum_++;
				}
			}
		}
		cout<<sum_<<endl;
	}
	return 0;
}
