#include <bits/stdc++.h>
using namespace std;
ifstream fin("xor.in");
ofstream fout("xor.out");
int n,k,B_cnt,a[500000];
bool A=true,B=true;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.second-x.first==y.second-y.first){
        return x.first < y.first;
    }
    return x.second-x.first<y.second-y.first;
}
int solve(){
    int ans=0;
    vector<pair<int,int> > vec;
    for(int i=0;i<n;++i){
        int xor_sum=0;
        for(int j=i;j<n;++j){
            xor_sum = xor_sum^a[j];
            if(xor_sum==k){
                vec.push_back(make_pair(i+1,j+1));
                break;
            }
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<vec.size();++i){
        int l=vec[i].first,r=vec[i].second;
        for(int j=i+1;j<vec.size();++j){
            int l1=vec[j].first,r1=vec[j].second;
            if(l1<=l&&r1>=l) {
                vec.erase(vec.begin()+j);
            }else if(l1<=r&&r1>=r) {
                vec.erase(vec.begin()+j);}
        }
        ++ans;
    }
    return ans;
}
int main(){
    fin>>n>>k;
    for (int i=0;i<n;++i){
        fin>>a[i];
        B_cnt+=a[i];
        if(a[i]>0)A=false;
        if(a[i]>1)B=false;
    }
    if(A)fout<<n/2<<endl;
    else if(B){
        if(k==0) fout<<B_cnt/2+n-B_cnt<<endl;
        else fout<<B_cnt<<endl;
    } else {
        fout<<solve()<<endl;
    }
    return 0;
}
