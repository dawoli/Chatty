#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int qpow(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) {
			ret = ret * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
int n, newn, a[5005];
struct qwq {
	int x, cnts;
} qwq[5005];
int can_put[100005];
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		if(a[i] != a[i - 1]) {
			qwq[++newn].x = a[i];
		}
		++qwq[newn].cnts;
	}
	can_put[0] = 1;
	int ans = 0;
	for(int i = 1, sum = 0; i <= newn; ++i) {
		int wnt = qwq[i].x;
		for(int T = 1; T <= qwq[i].cnts; ++T) {
			int tot = qpow(2, sum);
			for(int j = 0; j <= wnt; ++j) tot -= can_put[j];
			ans += (tot % mod) + mod;
			ans %= mod;
			for(int j = 10000; j >= 0; --j) {
				can_put[j + qwq[i].x] += can_put[j];
				can_put[j + qwq[i].x] %= mod;
			}
			++sum;
		}
	}
	cout << ans << endl;
	return 0;
}
/*

2025/11/01 Sat 09:09
Solved all four problems within 30 minutes, which is my personal best record.
Not allowed to submit and leave before contest ends...
Boring.
It is not a good idea to play games in the computer room.
What should I do?

2025/11/01 Sat 09:15
I just woke up 2 hours ago, so I don't want to sleep now.
Perhaps I can try to solve IMOSL2024C3 & N5 as I still remember them.
Those are quite hard problems.

2025/11/01 Sat 09:23
I was once hinted C3 by three lemmata. Lemmata 1 & 2 proven now.
Also, I heard that the plural form of lemma is lemmata.

2025/11/01 Sat 09:30
Every time I update this diary-like thing, I test it on lemonlime again.
I'm afraid that I may make this code wrong by accidentally typing a letter in the code.
Also I noticed that the STATISTICS bar in lemonlime splits the score into three levels.
PURE, FAR and LOST.
This reminds me of a game..?

2025/11/01 Sat 09:39
Lemma 3 is a bit hard. I'd like to present it to you.
There are 2n points equally seperated on a circle. n chords are drawn, connecting the 2n points.
Definition. Two chords are <intersecting> if they intersect at a point inside the circle.
Definition. We call the side of a chord with the center of the circle inside it as the outer side.
            If the center lies on the chord, define either side as the outer side.
Definition. Two chords are <enclosing> if the outer side of one chord is included in the other.
Definition. Two chords are <disjoint> if they neither intersect nor enclose.
Lemma 3. Prove that the number of enclosures is smaller than the number of disjoints.

2025/11/01 Sat 09:48
I think that nobody will be reading this.
To help anyone who may want to read strange or interesting codes to find me, here's some keywords you may search.
// freopen .ans CCF luogu mian //freopen

2025/11/01 Sat 09:56
I have no idea on Lemma 3. Maybe I'll stop trying this for a few minutes.
Now exploring linux.

2025/11/01 Sat 10:31
It has been more than 30 minutes since last update!
Note that this interval is longer than the time I used to solve CSP-J problems.
I think my classmates AKed too.
What are they doing?

2025/11/01 Sat 10:39
I will switch back to Windows now.

2025/11/01 Sat 02:43
Why is the date and time in Windows wrong?
It shows 2025/11/01 Sat 02:43 with UTC+8.
I should use UTC-8 and adjust the time one day further.
Strange.

2025/11/01 Sat 10:45
Time is correct now.

2085/11/01 Thu 10:47
*laugh*

2025/11/01 Sat 10:49
I will be saying nonsense things later on for a while.
You know what, in the first problem <number>, if you input 5, you should output five.
If you input 290es1q0, you should output 92100.
If you 0u050......7t0bx (90 characters truncated), you should output 99998......00000 (40 characters truncated).
These are the first three samples given.
The fourth sample consists of only numbers. 1e6 numbers.
That's quite a large number of numbers!
The second problem is good. The sample is small enough that I can present it here!
Though I don't want to. *laugh*
The third problem is an easy dp. I didn't even debugged because I passed all testcases on the first trial.
Trial is the noun form of a verb try. Not trytion or trition.
Speaking of trition, nutrition is a valid word. But nutry isn't, neither is nutri.
Speaking of nutrition, nutrimatic.org is a very powerful website to search for words with some certain expressions.
As a common example, if you want to find a seven-letter word with it's second, fourth and sixth letter being 't', you should search for "AtAtAtA".
It means that the first, third, fifth and seventh letter can be any letter and the remaining three are 't's.
Note that the expression contains the " symbols. They narrow down the result with only single words.
The first result should be statute. Did you think of the answer before I tell you this?

2025/11/01 Sat 11:00
One hour left!
Some more grammar of the nutrimatic searching expression can be found on the homepage of nutrimatic.org!
This website is commonly used to brute-force solutions out by providing only a few letters of the answer, which is incredibly useful in puzzle hunts.
Do you know about puzzle hunts? If yes, then that's great! You can contact luogu uid 747879 to try to hire a new team member who solved ~85% problems on his own during CCBC16 in your further puzzle hunts!
If no, I won't tell you anything about it [lol]. You can search puzzle hunt on baidu.com or bing.com or any searching engines to learn more about it.
Wow the length of this code is 5.5kb now, with only 1kb being the useful parts.
I once wrote a 3kb code during a simulation test. And I renamed the namespace's name with a long nonsensical paragraph which I spent one hour to wrote, making the code 11kb.
I'm good at writing meaningless things for a long time. Hope I produced no grammar errors.
Oh interesting. Number of numbers. Namespaces's names. Can you think of more interesting phrases like those?
Caps lock's cap. *laugh*
By the way, do you know that the cap of every keys such as caps lock is useless?
You can try taking them off and press the white little thing beneath. You will surprisingly find that it does the same thing as the key cap.
In fact the caps lock's cap of my computer at home was broken. Haha.

2025/11/01 Sat 11:14
Do you know a game called Antimatter Dimensions?
This is the best incremental game I've ever played. Now I will tell you the full content of this game.
First, you will have four antimatter dimensions, which I will call AD1~4 later on.
With enough progress, you can perform a dimension boost, giving you bonus and AD5.
Four dim boosts should give you all 8 ADs. After that, dim boosts will still give bonus but no more ADs. 
With enough progress, you can buy a galaxy. This resets you back to 4 ADs, but gives you a much stronger upgrade.
The cost of dim boosts and galaxies will become bigger and bigger as you progress.
After you buy a second galaxy, you will be able to reach 1.8e308 antimatter in some time, and everything will suddenly halt.
Pressing BIG CRUNCH resets everything and gives you one infinity point, which I will call IP later on.
You can use IP to buy infinity upgrades, IU. Every IU speeds you a little to get infinity.
Also, you will have access to normal challenges, C1~12. Each of them completed can give you an automation of AD1~8, tick upgrades, dim boosts, galaxies and big crunches.
You can reduce the cooldown and bulk of the automation by spending IPs. Once you reached a certain amount of IPs, you will be able to break infinity.
Breaking infinity gives you access to antimatter more than 1.8e308. Your IP gain now is based on the antimatter amount you reached.
There are break infinity upgrades and infinity challenges, IC1~8. Each of the ICs unlocks a new infinity dimension for you. (I suppose? I don't remember it very well.)
After 1e130 (or maybe something near) IPs, you will unlock replicanti. Replicanti amount grows slow at first, but with enough upgrades, it will be faster and faster.
Every time you hit 1.8e308 replicanti, you can buy a replicanti galaxy, resetting the replicanti amount. Replicanti galaxies does the same as a normal galaxy.
After you hit 1.8e308 IP, you will be able to eternity, resetting almost everything, except some very first progresses. At first, it will give you 1 eternity point, EP.
There are eternity milestones in the first few hundred or thousand eternities, giving you fewer and fewer resets. You also unlock further automations.
Also, you can buy time theorems, TTs with antimatter, IPs and EPs. There is a time study tree, which you will need strategy to deal with.
Every node on the tree costs TTs. The more TT you have, the deeper you have access to.
12 eternity challenges, EC, are seperated on the tree. You need to beat those challenges five times, named tiers, each with a harder requirement and a better reward.
After everything, you will have access to nearly everything on the tree and you unlock time dilation.
In dilation, everything will be very much slower, and you gain tachyon particles, TPs, based on your progress during dilation.
TPs produce dilated time, DT. You can use DT to buy upgrades, and you gain tachyon galaxies based on DTs. They also do the same as galaxies.
There are also time dimensions, TDs. You unlock TD1~4 once you eternity. And TD5~8 should be unlocked during time dilation stage, using very large amounts of TTs.
You can afford them because the finally upgrade in time dilation allows you to generate TTs.
After you hit 1e4000 EP, you can reality, resetting not only your progress, but achievements as well.
Making a new reality give you a glyph and a perk. You can use perk to buy perk upgrades, each giving you upgrades or reducing resets.
Glyphs are seperated into power glyphs, infinity glyphs, time glyphs, replication glyphs and dilation glyphs, each giving you upgrades.
You can equip five glyphs in every reality, and you need to figure out the combinations which best work to give you the desired currency.
You also unlock a new feature named automator. You can write codes to help you automatically run your strategy.
After this, you also unlock a black hole. You can upgrade it with reality machines, RMs, gained at every reality finished, amount based on EPs.
With certain progress, you unlock celestials. The first one is Teresa.
Every celestial have quotes (dialogues) and its unique reality. In it, your progress will be much reduced. If you reach reality in it, you beat this celestial.
Every celestial give you new upgrades. Effarig unlocks you a new glyph type, which have 8 effects at most.
The nameless ones allows you to charge black holes, V has six tiers of six challenges, Ra allows you to upgrade upgrades provided by previous celestials.
Lai'tela is complicated, which I don't really remember. And Pelle is the final boss.

2025/11/01 Sat 11:42
Once you enter Pelle's reality, known as doomed reality, you will have no choices but to progress. Everything will be reset. Everything.
You start with four ADs. Everything is the same. But you can Armageddon after you progress a few. This give you reality shards, RS.
RS can be used to buy Pelle upgrades. Pelle also has five special upgrades. I don't remember their name. 
There are certain stages in doomed reality. Every stage finished unlocks you a new special upgrades.
You can use your currency to fill up the upgrades. The milestones in the upgrades give you bonus.
Note that you cannot quit dilation in doomed reality. Instead, you gain tachyon particles every time in the dilation.
No glyphs can be equipped. More strategies are required. Finally, when you are near the end, you will be able to unlock galaxy generators.
They can be used to generate 1e5 galaxies at first, every time it is used up, you will sacrifice one of the five special upgrades to get more galaxies.
There are also tesseracts that I didn't mention before, unlocked by V. (I suppose?)
After everything, the 1e11 galaxies will push you to 1e(9e15) antimatter and you beat the game!
I beat it once. I spent almost one year.

2025/11/01 Sat 11:49
Enough bragging.
10 minutes until contest ends.
Goodbye!

- Written by Synthesize (luogu uid 747879).

*/
