#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<int>v1,v2,v3;
        int n,s=0;
        cin>>n;
        for(int j=0;j<n;j++){
            int a,b,c;
            cin>>a>>b>>c;
            int maxn=max(a,max(b,c));
            s+=maxn;
            if(maxn==a){
                v1.push_back(min(abs(a-b),abs(c-a)));
            }else if(maxn==b){
                v2.push_back(min(abs(a-b),abs(b-c)));
            }else{
                v3.push_back(min(abs(b-c),abs(c-a)));
            }

        }  
		sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        if(v1.size()>n/2){
			for(int j=0;j<v1.size()-n/2;j++){
                s-=v1[j];
            }
        }else if(v2.size()>n/2){
			for(int j=0;j<v2.size()-n/2;j++){
                s-=v2[j];
            }
        }else if(v3.size()>n/2){
            for(int j=0;j<v3.size()-n/2;j++){
                s-=v3[j];
            }
        }
        cout<<s<<endl;
    }
    return 0;
}


