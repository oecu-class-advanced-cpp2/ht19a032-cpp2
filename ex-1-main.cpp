#include <iostream>
#include <cmath>
#include<vector>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B

int corrent_answer_count = 0;

/* --------------------------------------------------------------- */
/*
* answer_check
*
* �o�͌��ʂƐ����Ƃ̔�r���s��
*/
/* -------------------------------------------------------------- */
void answer_check(int ans) {
	int currect_answer[] = {92809,6709,12037,103,93523,14503,2,899429,5107,412717,22699,25673 };
		if (ans == currect_answer[corrent_answer_count]) {
			std::cout << "����" << std::endl;
		}
		else {
			std::cout << "�s����" << endl;
		}
		corrent_answer_count++;
	}

/* --------------------------------------------------------------- */
/*
* gcd
*
* �^����ꂽ2�̐��̍ő���񐔂����߂�
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
* �^����ꂽ������ num �ɑ΂��āA�f�����ǂ������肷��
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
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {

	if (a < 0 || d < 0 || n < 0 || gcd(a, d) != 1) {
		std::cout << "�K�؂ȓ��͂ł͂���܂���" << endl;
		corrent_answer_count++;
		return false;
	}
	int num = a;
	int count = 0;//num���f���Ȃ�+1
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


	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
	cin.get();
	return 0;
}