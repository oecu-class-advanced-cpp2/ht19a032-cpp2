#include <iostream>
#include <cmath>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
/* --------------------------------------------------------------- */
/*
* is_prime
*
* 与えられた正整数 num に対して、素数かどうか判定する
*/
/* -------------------------------------------------------------- */
bool is_prime(int num) {
	if (num == 1) {
		return false;
	}

	//2からx-1までの数がxを割れるかチェック
	//もし割れたら即falseを返す
	for (unsigned int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
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
int nth_prime(int a, int d, int n) {
	int num = a;
	int count = 0;//numが素数なら+1
	while (num < CPP2_PRIME_UPPER_LIMIT) {

		if (is_prime(num)) {
			count++;
		}
		if (count == n) {
			break;
		}
		num += d;
	}
	return num;
}


int main() {
	std::cout << nth_prime(367, 186, 151) << " " << "92809" << std::endl;
	std::cout << nth_prime(179, 10, 203) << " " << "6709" << std::endl;
	std::cout << nth_prime(271, 37, 39) << " " << "12037" << std::endl;
	std::cout << nth_prime(103, 230, 1) << " " << "103" << std::endl;
	std::cout << nth_prime(27, 104, 185) << " " << "93523" << std::endl;
	std::cout << nth_prime(253, 50, 85) << " " << "14503" << std::endl;
	std::cout << nth_prime(1, 1, 1) << " " << "2" << std::endl;
	std::cout << nth_prime(9075, 337, 210) << " " << "899429" << std::endl;
	std::cout << nth_prime(307, 24, 79) << " " << "5107" << std::endl;
	std::cout << nth_prime(331, 221, 177) << " " << "412717" << std::endl;
	std::cout << nth_prime(259, 170, 40) << " " << "22699" << std::endl;
	std::cout << nth_prime(269, 58, 102) << " " << "25673" << std::endl;
	
	// 以下、同様に、入出力例通りになるか確認せよ。
	cin.get();
	return 0;
}