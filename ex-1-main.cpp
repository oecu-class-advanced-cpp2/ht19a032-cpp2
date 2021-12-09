#include <iostream>
#include <cmath>
#include<vector>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

int corrent_answer_count = 0;

/* --------------------------------------------------------------- */
/*
* answer_check
*
* 出力結果と正解との比較を行う
*/
/* -------------------------------------------------------------- */
void answer_check(int ans) {
	int currect_answer[] = {92809,6709,12037,103,93523,14503,2,899429,5107,412717,22699,25673 };
		if (ans == currect_answer[corrent_answer_count]) {
			std::cout << "正解" << std::endl;
		}
		else {
			std::cout << "不正解" << endl;
		}
		corrent_answer_count++;
	}

/* --------------------------------------------------------------- */
/*
* gcd
*
* 与えられた2つの数の最大公約数を求める
*/
/* -------------------------------------------------------------- */
int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else {
		return(gcd(b, a % b));
	}
}


/* --------------------------------------------------------------- */
/*
* is_prime
*
* 与えられた正整数 num に対して、素数かどうか判定する
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int num) {
	if (num == 2) {
		return true;
	}
	else if (num % 2 ==0 || num < 2) {
		return false;
	}
	else
	{
		for (int i = 3; i <= sqrt(num); i += 2) {
			if (num % i == 0) {
				return false;
			}
		}
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

	if (a < 0 || d < 0 || n < 0 || gcd(a, d) != 1) {
		std::cout << "適切な入力ではありません" << endl;
		corrent_answer_count++;
		return false;
	}
	int num = a;
	int count = 0;//numが素数なら+1
	while(num < CPP2_PRIME_UPPER_LIMIT) {

		if (is_prime(num) == true) {
			count++;
		}
		if (count == n) {
			break;
		}
			num += d;
}
	answer_check(num);
	return num;
}



int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	std::cout << nth_prime(179, 10, 203) << std::endl;
	std::cout << nth_prime(271, 37, 39) << std::endl;
	std::cout << nth_prime(103, 230, 1) << std::endl;
	std::cout << nth_prime(27, 104, 185) << std::endl;
	std::cout << nth_prime(253, 50, 85) << std::endl;
	std::cout << nth_prime(1, 1, 1) << std::endl;
	std::cout << nth_prime(9075, 337, 210) << std::endl;
	std::cout << nth_prime(307, 24, 79) << std::endl;
	std::cout << nth_prime(331, 221, 177) << std::endl;
	std::cout << nth_prime(259, 170, 40) << std::endl;
	std::cout << nth_prime(269, 58, 102) << std::endl;


	// 以下、同様に、入出力例通りになるか確認せよ。
	cin.get();
	return 0;
}