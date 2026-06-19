#include <bits/stdc++.h>
using namespace std;
int getas(vector<int> nums,vector<bool> sts){
    int lt=-1,lf=-1;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==(sts[i]?lt:lf)){
            ans+=nums[i];
        }else{
            if(sts[i]){
                lt=nums[i];
            }else{
                lf=nums[i];
            }
        }
    }
    return ans;
}
int dfs(vector<int> nums,vector<bool> sts,int k){
    if(k==0){
        return getas(nums,sts);
    }else{
        sts.push_back(true);
        int rt=dfs(nums,sts,k-1);
        sts.pop_back();
        sts.push_back(false);
        rt=max(rt,dfs(nums,sts,k-1));
        sts.pop_back();
        return rt;
    }
}
int main()
{
    freopen("color.in", "r", stdin);
    fstream fout("color.out",ios::out);
    int bats;
    cin>>bats;
    for(int asd=0;asd<bats;asd++){
        int n;
        cin>>n;
        vector<int> nums(n,0);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        vector<bool> tmp;
        fout<<dfs(nums,tmp,n);
    }
    fclose(stdin);
    fout.close();
}
