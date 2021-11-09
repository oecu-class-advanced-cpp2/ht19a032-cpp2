#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
/* --------------------------------------------------------------- */
/*
* is_prime
*
* 与えられた正整数 x に対して、素数かどうか判定する
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int x) {
	//2からx-1までの数がxを割れるかチェック
	//もし割れたら即falseを返す
	for (unsigned int i = 2; i < x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}


/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int num = a;
	int count = 0;//numが素数なら+1
	while (1) {
		if (is_prime(num)) {
			count++;
		}
		if (count == num) {
			std::cout << num << endl;
			break;
		}
		num += d;
	}
	return 0;
}


int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	
	// 以下、同様に、入出力例通りになるか確認せよ。
	cin.get();
	return 0;
}