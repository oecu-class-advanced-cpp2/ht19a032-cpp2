#include <iostream>
#include <string>
using namespace std;

namespace cpp2 {
    /* --------------------------------------------------------------------- */
    /*
       mcxi

       mcxi 記法を解析するクラスです。
     */
     /* --------------------------------------------------------------------- */
    class mcxi {
    private:
        int value_;
        int unit(char c) {
            switch (c) {
            case 'm': return 1000;
            case 'c': return  100;
            case 'x': return   10;
            case 'i': return    1;
            }
        }

    public:
        /* ----------------------------------------------------------------- */
        /*
           mcxi

           指定された文字列を解析して、オブジェクトを初期化します。
           以下の場合には例外が創出されます。

           1. [2-9,m,c,x,i] 以外の文字が出現した場合
           2. 2 文字続けて数字 (2-9) が出現した場合
           3. m, c, x, i がこの順序で出現しなかった場合
              ただし、例えば mx のように、特定の文字をスキップする事は許容
              されます。
         */
         /* ----------------------------------------------------------------- */
        mcxi(const std::string& s) : value_(0) {
            int num = 0;
            for (auto pos = s.begin(); pos != s.end(); ++pos) {
                //*pos は、char ! char ってことが分かってたら、もっと簡単にできるのでは？？
                if (*pos >= '2' && *pos <= '9') {
                    num = *pos - '0';
                }
                else if(*pos == 'm' || *pos=='c' || *pos=='x' || *pos == 'i'){
                    int u = unit(*pos);
                    value_ += std::max(num, 1) * u;
                    num = 0;
                }
                else {
                    std::cout << "不適切な文字です" << std::endl;
                }
            }
        }

        /* ----------------------------------------------------------------- */
        /*
           operator+

           2 つのオブジェクトの加算結果を取得します。
         */
         /* ----------------------------------------------------------------- */
        mcxi operator+(const mcxi& rhs) {
            mcxi tc(rhs);
            tc.value_ = this->value_ + rhs.value_;
            return tc;
        }

        /* ----------------------------------------------------------------- */
        /*
           to_string

           現在の値を mcxi 記法に変換します。
         */
         /* ----------------------------------------------------------------- */
        std::string to_string() const {
            std::string mcxi;
            int calc = value_;
            if (calc / 1000 >= 1) {
                if (calc / 1000 == 1) {
                    mcxi += "m";
                    calc = calc - 1000;
                }
                else {
                    mcxi += std::to_string(calc / 1000) + "m";
                    calc = calc - (calc / 1000) * 1000;
                }
            }
            if (calc / 100 >= 1) {
                if (calc / 100 == 1) {
                    mcxi += "c";
                    calc = calc - 100;
                }
                else {
                    mcxi += std::to_string(calc / 100) + "c";
                    calc = calc - (calc / 100) * 100;
                }
            }
            if (calc / 10 >= 1) {
                if (calc / 10 == 1) {
                    mcxi += "x";
                    calc -= 10;
                }
                else {
                    mcxi += std::to_string(calc / 10) + "x";
                    calc = calc - (calc / 10) * 10;
                }
            }
            if (calc % 10 >= 1) {
                if (calc % 10 == 1) {
                    mcxi += "i";
                }
                else {
                    mcxi += std::to_string(calc % 10) + "i";
                }
            }
            return mcxi;
        }
    };

  
    void answer_check(string mcxi_a, string mcxi_b, string answer) {
        cpp2::mcxi a(mcxi_a);
        cpp2::mcxi b(mcxi_b);
        cpp2::mcxi result = a + b;
        
        if (result.to_string() == answer) {
            std::cout << "正解" << " " << mcxi_a << " " << mcxi_b << " " << answer << " " << result.to_string() << std::endl;
        }
        else {
            std::cout << "不正解" << std::endl;
        }
    }
}


int main() {
    cpp2::answer_check("xi", "x9i", "3x");
    cpp2::answer_check("i", "9i", "x");
    cpp2::answer_check("c2x2i", "4c8x8i", "6cx");
    cpp2::answer_check("m2ci", "4m7c9x8i", "5m9c9x9i");
    cpp2::answer_check("9c9x9i", "i", "m");
    cpp2::answer_check("i", "9m9c9x8i", "9m9c9x9i");
    cpp2::answer_check("m", "i", "mi");
    cpp2::answer_check("i", "m", "mi");
    cpp2::answer_check("m9i", "i", "mx");
    cpp2::answer_check("9m8c7xi", "c2x8i", "9m9c9x9i");
    cpp2::answer_check("9m8c7xi", "c2x8i", "3x");
    cpp2::answer_check("mcx", "1x", "3x");
    cpp2::answer_check("amcx", "x", "3x");
    cpp2::answer_check("mcx", "32x", "3x");

}
