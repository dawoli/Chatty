#include<bits/stdc++.h>
using namespace std;
int d[20][100005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m,T;
	cin>>n>>m;
	int a0[n],a[n],c[m],x[4],ans=0;
	for(int i=0;i<n;i++){
		cin>>a0[i];
	}
	for(int i=0;i<m;i++){
		cin>>c[i];
	}
	int k=0;
	while(pow(2,k)<n){
		k++;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<pow(2,k-i-1);j++){
			cin>>d[i][j];
		}
	}
	cin>>T;
	for(int i=0;i<T;i++){
		for(int j=0;j<4;j++){
			cin>>x[j];
		}
		for(int j=0;j<n;j++){
			a[i]=a0[i]^x[i%4];
		}
		for(int y=0;y<m;y++){
			vector<int> al;
			for(int j=0;j<c[i];j++){
				al.push_back(j);
			}
			int j=0,cnt=0;
			while(al.size()>1){
				if(d[cnt][j]==0){
					if(a[j]>=cnt){
						al.erase(al.begin()+j+1);
					}
					else{
						al.erase(al.begin()+j);
					}
				}
				else{
					if(a[j+1]>=cnt){
						al.erase(al.begin()+j);
					}
					else{
						al.erase(al.begin()+j+1);
					}
				}
				j++;
				if(j>=(int)al.size()){
					cnt++;
					j-=al.size();
				}
			}
			ans^=(y*al[0]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
