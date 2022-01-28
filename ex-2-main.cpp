1	#include <iostream>
2	#include <string>
3	using namespace std;
4	
5	namespace cpp2 {
6	    /* --------------------------------------------------------------------- */
7	    /*
8	       mcxi
9	
10	       mcxi 記法を解析するクラスです。
11	     */
12	     /* --------------------------------------------------------------------- */
13	    class mcxi {
14	    private:
15	        int value_;
16	        int unit(char c) {
17	            switch (c) {
18	            case 'm': return 1000;
19	            case 'c': return  100;
20	            case 'x': return   10;
21	            case 'i': return    1;
22	            }
23	        }
24	
25	    public:
26	        /* ----------------------------------------------------------------- */
27	        /*
28	           mcxi
29	
30	           指定された文字列を解析して、オブジェクトを初期化します。
31	           以下の場合には例外が創出されます。
32	
33	           1. [2-9,m,c,x,i] 以外の文字が出現した場合
34	           2. 2 文字続けて数字 (2-9) が出現した場合
35	           3. m, c, x, i がこの順序で出現しなかった場合
36	              ただし、例えば mx のように、特定の文字をスキップする事は許容
37	              されます。
38	         */
39	         /* ----------------------------------------------------------------- */
40	        mcxi(const std::string& s) : value_(0) {
41	            int num = 0;
42	            for (auto pos = s.begin(); pos != s.end(); ++pos) {
43	                //*pos は、char ! char ってことが分かってたら、もっと簡単にできるのでは？？
44	                if (*pos >= '2' && *pos <= '9') {
45	                    num = *pos - '0';
46	                }
47	                else if(*pos == 'm' || *pos=='c' || *pos=='x' || *pos == 'i'){
48	                    int u = unit(*pos);
49	                    value_ += std::max(num, 1) * u;
50	                    num = 0;
51	                }
52	                else {
53	                    std::cout << "不適切な文字です" << std::endl;
54	                }
55	            }
56	        }
57	
58	        /* ----------------------------------------------------------------- */
59	        /*
60	           operator+
61	
62	           2 つのオブジェクトの加算結果を取得します。
63	         */
64	         /* ----------------------------------------------------------------- */
65	        mcxi operator+(const mcxi& rhs) {
66	            mcxi tc(rhs);
67	            tc.value_ = this->value_ + rhs.value_;
68	            return tc;
69	        }
70	
71	        /* ----------------------------------------------------------------- */
72	        /*
73	           to_string
74	
75	           現在の値を mcxi 記法に変換します。
76	         */
77	         /* ----------------------------------------------------------------- */
78	        std::string to_string() const {
79	            std::string mcxi;
80	            int calc = value_;
81	            if (calc / 1000 >= 1) {
82	                if (calc / 1000 == 1) {
83	                    mcxi += "m";
84	                    calc = calc - 1000;
85	                }
86	                else {
87	                    mcxi += std::to_string(calc / 1000) + "m";
88	                    calc = calc - (calc / 1000) * 1000;
89	                }
90	            }
91	            if (calc / 100 >= 1) {
92	                if (calc / 100 == 1) {
93	                    mcxi += "c";
94	                    calc = calc - 100;
95	                }
96	                else {
97	                    mcxi += std::to_string(calc / 100) + "c";
98	                    calc = calc - (calc / 100) * 100;
99	                }
100	            }
101	            if (calc / 10 >= 1) {
102	                if (calc / 10 == 1) {
103	                    mcxi += "x";
104	                    calc -= 10;
105	                }
106	                else {
107	                    mcxi += std::to_string(calc / 10) + "x";
108	                    calc = calc - (calc / 10) * 10;
109	                }
110	            }
111	            if (calc % 10 >= 1) {
112	                if (calc % 10 == 1) {
113	                    mcxi += "i";
114	                }
115	                else {
116	                    mcxi += std::to_string(calc % 10) + "i";
117	                }
118	            }
119	            return mcxi;
120	        }
121	    };
122	
123	  
124	    void answer_check(string mcxi_a, string mcxi_b, string answer) {
125	        cpp2::mcxi a(mcxi_a);
126	        cpp2::mcxi b(mcxi_b);
127	        cpp2::mcxi result = a + b;
128	        
129	        if (result.to_string() == answer) {
130	            std::cout << "正解" << " " << mcxi_a << " " << mcxi_b << " " << answer << " " << result.to_string() << std::endl;
131	        }
132	        else {
133	            std::cout << "不正解" << std::endl;
134	        }
135	    }
136	}
137	
138	
139	int main() {
140	    cpp2::answer_check("xi", "x9i", "3x");
141	    cpp2::answer_check("i", "9i", "x");
142	    cpp2::answer_check("c2x2i", "4c8x8i", "6cx");
143	    cpp2::answer_check("m2ci", "4m7c9x8i", "5m9c9x9i");
144	    cpp2::answer_check("9c9x9i", "i", "m");
145	    cpp2::answer_check("i", "9m9c9x8i", "9m9c9x9i");
146	    cpp2::answer_check("m", "i", "mi");
147	    cpp2::answer_check("i", "m", "mi");
148	    cpp2::answer_check("m9i", "i", "mx");
149	    cpp2::answer_check("9m8c7xi", "c2x8i", "9m9c9x9i");
150	    cpp2::answer_check("9m8c7xi", "c2x8i", "3x"); //答えが異なる
151	    cpp2::answer_check("mcx", "1x", "3x");　//bが異なる
152	    cpp2::answer_check("amcx", "x", "3x");　//aが異なる153	154	}
