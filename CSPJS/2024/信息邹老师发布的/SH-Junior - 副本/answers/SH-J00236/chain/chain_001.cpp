#include<iostream>
using namespace std;
int mp[15][15],num[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T,n,k,q;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n>>k>>q;
		for(int m=0,l=0,r=1;m<n;m++){
			int x;
			cin>>x;
			for(int i=0;i<x;i++){
				cin>>num[i];
				}
			while(r<x){
				mp[num[l]][num[r]]+=1;
				mp[num[r]][num[l]]+=1;
				r++;
				if(r-l>=k||r==x-1)l++;
			}
			}
		for(int Q=0;Q<q;Q++){
		    int r,c;
		    cin>>r>>c;
		    if(mp[1][c]>=r)cout<<1;
		    else cout<<0;
		    cout<<endl;
	    }
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
