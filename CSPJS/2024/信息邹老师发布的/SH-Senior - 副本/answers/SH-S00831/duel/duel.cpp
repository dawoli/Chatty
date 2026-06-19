#include<bits/stdc++.h>
using namespace std;
struct d{
	int i,v;
	bool operator<(const d k)const{
		if(k.v==v){
			return i<k.i;
		}
		return v<k.v;
	}
};
int v[100005];
vector<int>vi,ve;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v[t]++;
	}
	for(int i=0;i<100005;i++){
        if(v[i]!=0){
            vi.push_back(v[i]);
            ve.push_back(vi[vi.size()-1]);
        }
	}
	for(int i=1;i<ve.size();i++){
        ve[i]+=ve[i-1];
	}
	int c=n;
	for(int i=1;i<vi.size();i++){
		if(i!=0){
			c-=min(ve[i-1]-n+c,vi[i]);
		}
	}
	cout<<c;
}
