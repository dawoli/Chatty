#include<bits/stdc++.h>
using namespace std;
const int N=5009,MOD=998244353;
int n,a[N],f[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int m=a[n],sum=0,sf=1;
	f[0]=1;
	for(int i=1;i<=n;i++){
		int fs=0;
		for(int j=0;j<=a[i];j++){
//			cout<<f[j]<<" ";
			fs=(fs+f[j])%MOD;
		}
//		cout<<i<<":"<<a[i]<<","<<fs<<endl;
		sum=((sum+sf)%MOD+MOD-fs)%MOD;
		sf=sf*2%MOD;
		for(int j=m;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%MOD;
		}
	}
	cout<<sum<<endl;
//[Main Window]\n[8:33]Get Problem\n[8:48]End Read First 3\n[8:55]End Read T4\n[8:56]Start write T12%ED[9:20](9:20)%\n[8:58](INT)Build folder\n[9:00](INTCTN)\n[9:20]Start write T34\n[[9:45]](INT)Linux\n[10:11]Linux:OKT1\n[10:18](INTCTN)\n[10:40]Test in linux\n[10:44]Sucess linux(400pts)\n[10:45]Final check\n[10:48]Copy catalog to Windows\n[11:12]Done\n[11:13]Last catalog write by hand\n[11:13]([EOF])\n[11:13]Only computer catalog\n[11:17]Find T4 file wrong, copy from linux\n[11:20]FINAL3 is double checked in linux(copy of FINAL)\n[11:20]Note:only have FINAL and FINAL3\n[11:24]Move file to E:\OI\jwbfile...\n[11:28]Trible checked folder\n[11:29]Than the log will be store in cpp file\n[11:30]Last catalog write in computer\n[EOF]\n\n[SubWindow1]\nT1:get digit->sort\nEg: b1a2c3->321\n8:38\nT2:sort->blank in\n(not by math)\nEg:\n%TABLE(3*3)[109,45,94,99,96,93,98,97,92]% %CONTAINER{\n3 3\n9 2 100...92(!=92)\n33}%\n[8:41]\nT3:dynamic programing\nfi:1-i can choose?\nuse array x s.t.\nfi<-max(xvi,fi-1)\nxviCIRC{ADD}k<-fi+1\n8:45\neg:\n1 1 0\n2 0 2 5 1 1 0 1 8 4 6\n[202][11][0] 3\n8:48\n[EOF]\n\n[SubWindow2]\nT4:1> %CONTAINER{\nn<=5000\nmax<=5000\n}%\nUp Down Left Right !(ch or)%ED:10.57(10.58)%\n%XoY([1,1]...[5,5])%(or y-=1)%ED:10.58(10.59)%\n%box{text{\nif can,first sort!\n}}%\ndown->up\nHow many sum\nbigger than ai\ndp:%CONTAINER{\nbag problem\n[01]}%\nm=2 MAXAI\n(ED 11:00(11:00)MAXAI)\nn=n\nO(nm)\nOk!\n8:55\n[EOF]\n\n[SubWindow3]\nT1:%CONTAINER{\nStart T 8:57\nEnd T [9:46]\nEXP T 15min\nREAL T 9min\nEXP PTT 100pts\nATT1 9:05\nFC AC}%\nT2:%CONTAINER{\nSTART T [9:06]%ED 9:09(9:10)%\nEND T 9:20\nEXP T 15min\nREAL T 14min\nEXP PTT 100pts\nATT1 9:13\nEG WA[2 2 4 1 2 3]\nATT2 4:16\nEG WA\n2 2\n2 1 3 4 -> 2 1\nEXP 2 2\nATT3 9:17\nEG WA\n2 2\n2 1 3 4 -> 2 1\nATT4 9:19\nEG [AC]\nFC [AC]\n9:20}%\n[EOF]\n\n[Folder]\n[8:58] MAIN\n[8:59] SUB\n[9:00] TEMPLATE\n\n[SubWindow4]\nT3:%CONTAINER{\nSTART T [9:20]%ED 9:22(9:22)%\nEND T 9:37\nEXP T 15min\nREAL T 17min\nEXP PTT 100pts\nATT1 9:32\nEG[WA]\n4 2\n2 1 0 3->0\nEXP 2\nATT2 9:35\nEG[AC]\nFC[AC]}%\nT4:%CONTAINER{\nSTART T 9:48\nEND T 10:39\nREAL T 57 min(-33 min=24 min)\nEXP T 30 min\nEXP PTT100pts\n[ED:10:28(10:29)]\nATT1[10:27]\nEG WA\n5\n1 2 3 4 5 -> 31\nEXP 9\nATT2[10:32]\nEG WA\n5\n1 2 3 4 5 -> 16\nEXP 9\nATT3[10:33]\nEG WA\n5\n1 2 3 4 5 -> 998 244 349\nEXP 9\nATT4[10:34]\nEG AC\nFC AC}%\n10:39\n[EOF]\n\n[SubWindow5]\n[10:46]Copied\n[10:47]T1 sucess\n[10:48]T4 sucess\n[10:48]T2 sucess\n[10:48]T3 sucess\n
	return 0;
}

