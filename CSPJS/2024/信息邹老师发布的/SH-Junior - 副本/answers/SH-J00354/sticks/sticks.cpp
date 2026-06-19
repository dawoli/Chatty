//GL@17SXYZ Y#C*GF@24
#include <bits/stdc++.h>
using namespace std;
struct k{
	char nums[1000000];
	int length=999999;
}ans,oans;
bool xiaoyu(k a,k b){
	//a,bµÈ³¤
	int i=0;
	while(i<a.length){
		if(a.nums[i]<b.nums[i])return true;
		if(a.nums[i]>b.nums[i])return false;
		i++;
	}
	return false;
}
int n,gun,flag=0,a[10]={7,2,5,5,4,5,6,3,7,6};
void dfs(int shenggun,int depth){
	if(shenggun==0){
		flag=1;
		if(oans.length>ans.length){
			cout << ans.nums << 'a' << oans.nums << 'a';
			oans=ans;
		}
		else if(oans.length==ans.length){
			cout << ans.nums << 'a' << oans.nums << 'a';
			oans=(xiaoyu(ans,oans)?ans:oans);
		}
		return;
	}
	for(int i=0;i<=9;i++){
		if(depth==1 && i==0)continue;
		if(shenggun>=a[i]){
			ans.nums[depth-1]=i+'0';
			if(ans.length==999999)ans.length=0;
			ans.length++;
			dfs(shenggun-a[i],depth+1);
			ans.length--;
			ans.nums[depth-1]='\0';
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> n;
	while(n--){
		flag=0;
		memset(ans.nums,0,sizeof ans.nums);
		memset(oans.nums,0,sizeof oans.nums);
		cin >> gun;
		cout << -1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
