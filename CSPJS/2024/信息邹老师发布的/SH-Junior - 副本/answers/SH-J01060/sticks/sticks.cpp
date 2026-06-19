#include<bits/stdc++.h>
using namespace std;
int used[10]={6,2,5,5,4,5,6,3,7,6};
string bfs(int n){
    queue<pair<string,int>> que;
    for(int i=1;i<10;i++){
        string rt;
        rt+=char(i+'0');
        if(n-used[i]>0){
        que.push(make_pair(rt,n-used[i]));
        }else if(n==used[i]){
            return rt;
        }
    }
    while(!que.empty()){
        pair<string,int> frt=que.front();
        que.pop();
        for(int i=0;i<10;i++){
            if(frt.second-used[i]>0){
            que.push(make_pair(frt.first+char('0'+i),frt.second-used[i]));
            }else if(frt.second==used[i]){
                return frt.first+char('0'+i);
            }
        }
    }
    return "-1";
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int stks,n;
    cin>>stks;
    for(int i=0;i<stks;i++){
        cin>>n;
        cout<<bfs(n)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}