#include<bits/stdc++.h>
using namespace std;

bool xoor(vector<int> arr,int k,int l,int r){
	if(l==r){
		return arr[l]==k;
	}else{
		for(int ma=l;ma<r;ma++){
			int it=0;int resi=0;
			vector<bool> res;
			while(it<31){
				bool aa=((arr[ma]>>it&1)^(arr[ma+1]>>it&1));
				res.push_back(aa);
				it++;
			}
			for(int i=0;i<res.size();i++){
				resi+=pow(2,i)*res[i];
			}
			arr[ma+1]=resi;
		}
		return arr[r]==k;
	}
}
int sub(vector<int> arr,vector<pair<int,int>> al,int k){
	int l,r;bool havesol=0;
	for(l=1;l<arr.size();l++){
		for(r=l;r<arr.size();r++){
			if(xoor(arr,k,l,r)){
				for(int i=0;i<al.size();i++){
					if(al[i].first<=l||al[i].second>=r||(al[i].first>=l&&al[i].second<=r)){
						return al.size();
					}
				}
				havesol=1;
			}
		}
	}
	if(havesol){
		pair<int,int> jie(l,r);
		al.push_back(jie);
		return sub(arr,al,k);
	}else{
		return al.size();
	}
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<pair<int,int>> al(0);
	cout<<sub(a,al,k)<<endl;
	return 0;
}
