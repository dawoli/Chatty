#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    string *cf=new string[n],*ct=new string[n];
    for(int i=0;i<n;i++){
        cin>>cf[i]>>ct[i];
    }
    for(int i=0;i<q;i++){
        string t,tt;ll ans=0;
        cin>>t>>tt;
        for(int j=0;j<n;j++){
            if(t.length()>=cf[j].length()&&t.find(cf[j])!=string::npos){
                ll pos=t.find(cf[j]);
                while(pos!=string::npos){
                    string ta=t;
                    for(int i=pos;i<pos+ct[j].length();i++){
                        ta[i]=ct[j][i-pos];
                    }
                    if(ta==tt){
                        ans++;
                        break;
                    }
                    pos=t.find(cf[j],pos+1);
                }
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}
