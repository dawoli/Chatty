#include <bits/stdc++.h>
using namespace std;

void testIO()
{
	int n;
	cin >> n;
	cout << n << endl;
}

const int N = 1000 + 5;
int n, a[N];
int f[N];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	// testIO();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (a[j] <= a[i])
			{
				f[i] = max(f[i], f[j] + 1);
			}
		}
	}
	cout << f[n] + 1 << endl;
	return 0;
}

// import random
// import time
// from math import floor, sqrt

// # My Highest:      16 308 952
// # Program Highest:    733 008

// random.seed(1629 + time.time() + time.perf_counter())

// cards = {
//     "A": {
//         "damage": 10,
//         "protect": 2,
//         "life": 0,
//     },
//     "B": {
//         "damage": 2,
//         "protect": 15,
//         "life": 5,
//     },
//     "C": {
//         "damage": 50,
//         "protect": 0,
//         "life": 0,
//     },
//     "D": {
//         "damage": 10,
//         "protect": 10,
//         "life": 5,
//     },
//     "E": {

//     },
//     "F": {
//         "damage": 0,
//         "protect": 100,
//         "life": 50,
//     },
//     "G": {
//         "damage": 90,
//         "protect": 0,
//         "life": 0,
//     },
//     "H": {
//         "damage": 50,
//         "protect": 50,
//         "life": 50,
//     },
//     "I": {
//         "damage": -10,
//         "protect": 0,
//         "life": 0,
//     },
//     "J": {
//         "damage": 80,
//         "protect": 50,
//         "life": 50,
//     },
//     "NUCLEAR": {
//         "damage": 100,
//         "protect": -50,
//         "life": -50,
//     }
// }

// # A: less than D in self. B: heal. C:big damage. D: ordinary. E: good. F: best heal. G: biggest damage. H: average performance and best heal

// # Damage: G, J, H, C, D, A, B
// # Heal & Protect: F, J, H, B, D
// # I: Our newest nonsense rubbish



// cheat = 1

// cardb = {
//     "A": floor(20 * cheat),
//     "B": floor(20 * cheat),
//     "C": floor(15 * cheat),
//     "D": floor(10 * cheat),
//     "E": floor(5 * cheat),
//     "F": floor(10 * cheat),
//     "G": floor(1 * cheat),
//     # "G": 1,
//     "H": floor(5 * cheat),
//     "I": 100,
//     "J": floor(10 * cheat),
//     "NUCLEAR": 0,
// }

// sum_cardb = sum(list(cardb.values()))

// proc = cheat

// cardb2 = {
//     "A": 20 * proc,
//     "B": 20 * proc,
//     "C": 15 * proc,
//     "D": 10 * proc,
//     "E": 5 * proc,
//     "F": 10 * proc,
//     "G": 1 * proc,
//     "H": 5 * proc,
//     # "I": 96 * proc,
//     "I": 100,
//     "J": 10 * proc,
//     # "NUCLEAR": 2 * proc,
//     "NUCLEAR": 0,
// }

// # A: less than D in self. B: heal. C:big damage. D: ordinary. E: good. F: best heal. G: biggest damage. H: average performance and best heal

// # Damage: G, J, H, C, D, A, B
// # Heal & Protect: F, J, H, B, D
// # I: Our newest nonsense rubbish

// def choose(l):
//     for i in l:
//         if cardb2[i] > 0:
//             return i

// def heal():
//     l = ['F', 'J', 'H', 'B', 'D', 'A', 'E', 'G', 'C', 'I']
//     return choose(l)

// def attack():
//     l = ['G', 'J', 'E', 'H', 'C', 'D', 'A', 'B', 'F', 'I']
//     return choose(l)

// def slight_attack():
//     l = ['B', 'A', 'D', 'C', 'H', 'E', 'J', 'G', 'F', 'I']
//     return choose(l)

// def small_attack():
//     l = ['G', 'J', 'H', 'C', 'D', 'A', 'B', 'F', 'E', 'I']
//     return choose(l)

// def ai(HumanBlood, MyBlood, humanE, humanI, humanG):
//     if humanG:
//         return 'E'
//     elif humanI:
//         return attack()
//     elif MyBlood < 30:
//         return heal()
//     elif MyBlood < HumanBlood - 200 and MyBlood < 100:
//         return slight_attack()
//     elif MyBlood < HumanBlood - 200:
//         return small_attack()
//     elif MyBlood < HumanBlood - 50 and not humanE:
//         return choose(['E', 'F', 'J', 'H', 'B', 'D'])
//     elif MyBlood < HumanBlood - 20:
//         return heal()
//     else:
//         return attack()

// # cardb2 = cardb
// sum_cardb2 = sum(list(cardb2.values()))

// def build_list(db):
//     l = []
//     for (k, v) in db.items():
//         l += [k] * v
//     return l
    
// # print(build_list())

// blood_man = 100
// blood_program = 100

// print("Welcome to the game.")
// print("We have {} cards!".format(len(cards.keys())))

// def calc(bloodA, bloodB, cardbA, cardbB, sumA, sumB):
//     return floor((bloodA ** 2 - bloodB ** 2) + (100 * sum(list(cardbA.values())) / sumA) ** 3)

// round_number = 1

// while True:
//     print("\033c", end = '')
//     print("Round {}".format(round_number))
//     print("YOU {} V.S. PROGRAM {}".format(blood_man, blood_program))
//     if sum(list(cardb.values())) == 0:
//         print("You have no cards!")
//         break
//     if sum(list(cardb2.values())) == 0:
//         print("Program have no cards!")
//         break
//     print("You now have", end = ' ')
//     for k, v in cardb.items():
//         print("{} {}".format(k, v), end = ', ')
//     print()
//     print("Program now have", end = ' ')
//     for k, v in cardb2.items():
//         print("{} {}".format(k, v), end = ', ')
//     print()
//     print("Your point {} VS Program point {}".format(calc(blood_man, blood_program, cardb, cardb2, sum_cardb, sum_cardb2), calc(blood_program, blood_man, cardb2, cardb, sum_cardb2, sum_cardb)))
//     if blood_man <= 0:
//         print("You lose with program winning the point {}!".format(calc(blood_program, blood_man, cardb2, cardb, sum_cardb2, sum_cardb)))
//         break
//     if blood_program <= 0:
//         print("You win with point {}!".format(calc(blood_man, blood_program, cardb, cardb2, sum_cardb, sum_cardb2)))
//         break
//     user_choice = input("Enter your choice: ")
//     # user_choice = 'E'
//     # user_choice = random.choice(build_list(cardb))
//     if user_choice not in cards.keys() or cardb[user_choice] <= 0:
//         print("Error!")
//         continue
//     # pro_choice = random.choice(build_list(cardb2))
//     pro_choice = ai(blood_man, blood_program, user_choice == 'E', user_choice == 'I', user_choice == 'G')
//     if cardb2[pro_choice] <= 0:
//         print("Error!")
//         continue
//     print("Program choose {}!".format(pro_choice))
//     if user_choice == 'E' and pro_choice == 'E':
//         print("Sorry: Can't choose E together.")
//         continue
//     user_a = cards[user_choice]
//     user_b = cards[pro_choice]
//     cardb[user_choice] -= 1
//     cardb2[pro_choice] -= 1
//     if pro_choice == 'NUCLEAR':
//         # time.sleep(1)
//         pass
//     if user_choice != 'E' and pro_choice != 'E':
//         blood_man = max(0, blood_man - user_b["damage"] + user_a["protect"] + user_a["life"])
//         blood_program = max(0, blood_program - user_a["damage"] + user_b["protect"] + user_a["life"])
//     elif user_choice == 'E':
//         blood_man = max(0, blood_man + user_b["protect"] + user_b["life"] + user_b["damage"])
//         blood_program = max(0, blood_program - user_b["damage"] + user_b["life"] + user_b["protect"])
//     else:
//         blood_man = max(0, blood_man - user_a["damage"] + user_a["life"] + user_a["protect"])
//         blood_program = max(0, blood_program, user_a["protect"] + user_a["life"] + user_a["damage"])
//     # time.sleep(0.5)
//     round_number += 1

// if blood_man > blood_program:
//     print("You win with point {}!".format(calc(blood_man, blood_program, cardb, cardb2, sum_cardb, sum_cardb2)))
// elif blood_man < blood_program:
//     print("You lose with program winning the point {}!".format(calc(blood_program, blood_man, cardb2, cardb, sum_cardb2, sum_cardb)))
// else:
//     print("Tie!")