#include <bits/stdc++.h>
using namespace std;
int n;
int a[150000];
int ans=0;
void dfs(int x, int sum, int mv, int l){//Xi Jie Void
	if (x==n+1){
		if (sum>mv*2 && l>=3){
			ans++;
		}
		return ;
	}
	dfs(x+1,sum+a[x],max(mv,a[x]),l+1);//Y
	dfs(x+1,sum,mv,l);//N
}
int cf[150000];//Zenme Cf le??
int jc[140000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	if (n<=20){
		//Dfs
		//Edge Num
		//Max Selected Num
		//Chosen Edges
		dfs(1,0,0,0);
		cout << ans;
	}else{
		cf[1]=2;
		for (int i=2; i<=n; i++){
			cf[i]=2*(cf[i-1])%998244353;
		}
		//cout << cf[5] << " ";
		cout << int(cf[n]-n*(n-1)/2-n-1+998244353)%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
9:32 KaiTi
Look, #1-#3 Is N<3 Only 1 Possible Way(?) +12
And Maybe (Only Maybe, 4-10) Or 4-7: Dfs + JianZhi 12->40
For ai=1? Only zhen n bian xing is possible. So From 3->N cout << n-2?
So Maybe I can get #1 to #20 Except 11-14 (64 pts)
? Nope. It should be a factirial For: #15-20. From C(3,n) All the Way to C(n,n). Which is pow(2,n)-C(2,n)-C(1,n)-1. But I don't Need QSM
Highest Expection: 100+100+65+64=329 J1
Normal Expection:  100+100+30+50=280 Still J1
Hurry Up (9:37)
9:49 Finnished Dfs
9:51 Pass Sample 3 +40 Now 240.0 Start 2*n!
9:58 Finnish Another Part! I have To Make It By Hand 
     3: 1,2,3 Only 1 8-3-3-1=1
	 4: 1,2,3; 1,2,4; 1,3,4; 2,3,4; 1,2,3,4; 16-6-4-1=5!
	 5: 1,2,3; 1,2,4; 1,2,5; 1,3,4; 1,3,5; 1,4,5; 2,3,4; 2,3,5; (2,4,5;) 3,4,5; 1,2,3,4; 1,2,3,5; 1,2,4,5; 1,3,4,5; 2,3,4,5; 1,2,3,4,5;(15)
	 32-10-5-1=16?
	 Oh I forgot 2,4,5
10:03 Expected 64 Pts Write Freopen!
10:05 It's Hard to control my eyes to prevent seeing others code and have jinsaisannian, but I controled myself. Lol

HouJi Writen @ 11:21
Score: High: 100+100+65+64=329
       Middium: 100+100+30+40=270 
       At least, I have a great probrabillity to get a J1
Even though there are many unsure things in this test, but I tried for many times in this test.
I tried using greedy in T3, and wrote one of the longest code I've written in my test-- 100 rows
I feel very happy about the news that I can participate in Senior Group Round 2.
But if I didn't get any of J1 Or S2, I will be AFO
Thanks to Xiaomawang, giving a platform for me to learn programming.
Thanks to TongJi University, giving me further knowlege about mathmatics in OI
Thanks to SUIS, teaching me basic subjects and knowledge I need.
Thanks to Xrs, teaching me advanced maths.
Thanks to Hyperion_1210, teaching many teqniques in C++
Thanks to Mr.Xia Mr.Ding Mr.Diao, leading me in the wrold of C++
Thanks to my python teacher, which led me to programmig.
Thanks to my mom and dad, giving me a lot of supplies for learning C++
Thanks to shenboji and UPDATE, which gave me joy when I'm trainning.
Thanks to zhangluoqing. She's my strong oponet, and leads me go forward.(I want to be numver 1 In the Class)
Thanks to CCF's CSP, giving me an opunity to show my stelf (Without that, I won't be ale to participate that camp, and ry to go in qingshuruwenben)
Thanks to GESP, which Igot 90 pts and my mom give me 1h game time lol
Finaly, Thanks To myself, always tring my best in the hard path of OI
If I didn't do well in CSP-S, then this will be my second-last contest. 
But these will never be my last code.
Wish ShenZhaoQing, ZhangLuoqing and YangHanMing will RP++;
Wish me RP++;
Good Luck everyone, From AndyCGM(ACGO 507784/Luogu:?/?)
(Wish Naxida could give me good luck? (? )(xiaosheng)
It's Already 11:34, and I have to check my code.
Bye.
*/

