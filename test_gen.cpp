#include <string>
#include <climits>
#include <random>
#include <cstdlib>
#include <cstdio>
using namespace std;

void writeRaw(const string& s) {
    fwrite(s.data(), 1, s.size(), stdout);
}

string base26(unsigned long long num, int width) {
    string s(width, 'a');
    for (int i = width - 1; i >= 0; i--) {
        s[i] = char('a' + num % 26);
        num /= 26;
    }
    return s;
}
//int
void genInt1() {
    int n = 100000;
    writeRaw(to_string(n) + "\n");

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            writeRaw(to_string(INT_MIN) + "\n");
        }
        else {
            writeRaw(to_string(INT_MAX) + "\n");
        }
    }
    writeRaw("\n");
}

void genInt2() {
    int n = 100000;
    writeRaw(to_string(n) + "\n");

    for (int i = 0; i < n / 2; i++) {
        writeRaw(to_string(i * 10) + "\n");
    }

    for (int i = n / 2; i > 0; i--) {
        writeRaw(to_string(i * 10) + "\n");
    }
}

void genInt3() {
    int n = 100000;
    writeRaw(to_string(n) + "\n");

    int start_val = 50000;
    for (int i = 0; i < n; i++) {
        writeRaw(to_string(start_val - i) + "\n");
    }
}

void genInt4() {
    int n = 100000;
    writeRaw(to_string(n) + "\n");

    mt19937 rng(1337);
    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    for (int i = 0; i < n; i++) {
        writeRaw(to_string(dist(rng)) + "\n");
    }
}

void genInt5() {
    int n = 100000;
    writeRaw(to_string(n) + "\n");

    long long start_val = 2512044713LL;
    writeRaw(to_string(start_val) + "\n");

    long long current_val = -start_val;
    for (int i = 1; i < n; i++) {
        writeRaw(to_string(current_val) + "\n");
        current_val--;
    }
}

//strlenxi
void genStrlexi1() {
    const int N = 100000;
    writeRaw("100000\n");
    string prefix(96, 'a');
    unsigned long long start = 1;
    for (int i = 0; i < 4; i++)
        start *= 26;
    start -= 1;
    for (int i = 0; i < N; i++) {
        writeRaw(prefix + base26(start - i, 4) + "\n");
    }
}

void genStrlexi2() {
    const int N = 100000;
    writeRaw("100000\n");
    string prefix(99, 'm');
    int base = N / 26;
    int rem = N % 26;
    int block = 0;
    for (char c = 'z'; c >= 'a'; --c, ++block) {
        int cnt = base + (block < rem ? 1 : 0);
        for (int i = 0; i < cnt; ++i) {
            writeRaw(prefix + c + "\n");
        }
    }
}

void genStrlexi3() {
    const int N = 100000;
    writeRaw("100000\n");
    string s(100, 'q');
    s += '\n';
    for (int i = 0; i < N; ++i)
        writeRaw(s);
}

void genStrlexi4() {
    const int N = 100000;
    writeRaw("100000\n");
    string prefix(96, 'b');
    for (int x = 0; x < N; x += 2) {
        writeRaw(prefix + base26(x, 4) + "\n");
    }
    for (int x = N - 1; x >= 1; x -= 2) {
        writeRaw(prefix + base26(x, 4) + "\n");
    }
}

void genStrlexi5() {
    const int N = 100000;
    writeRaw("100000\n");
    string prefix = string("aa") + string(90, 'c');
    unsigned long long start = 1;
    for (int i = 0; i < 8; ++i)
        start *= 26;
    start -= 1;
    for (int i = 0; i < N; ++i) {
        writeRaw(prefix + base26(start - i, 8));
        if (i + 1 < N)
            writeRaw("\n");
    }
}

//strlenlexi
void genStrlenlexi1() {
    const int N = 10000;
    writeRaw("10000\n");
    string prefix(96, 'a');
    for (int i = N - 1; i >= 0; --i) {
        writeRaw(prefix + base26(i, 4) + "\n");
    }
}

void genStrlenlexi2() {
    const int N = 10000;
    writeRaw("10000\n");
    string prefix(99, 'b');
    int printed = 0;
    int blockSize = (N + 25) / 26;
    for (char c = 'z'; c >= 'a'; --c) {
        int idx = c - 'a';
        int limit = (26 - idx) * blockSize;
        while (printed < N && printed < limit) {
            writeRaw(prefix + c + "\n");
            ++printed;
        }
    }
    while (printed < N) {
        writeRaw(prefix + string("a\n"));
        ++printed;
    }
}

void genStrlenlexi3() {
    const int N = 10000;
    writeRaw("10000\n");
    string s(100, 'm');
    s += '\n';
    for (int i = 0; i < N; ++i)
        writeRaw(s);
}

void genStrlenlexi4() {
    const int N = 10000;
    writeRaw("10000\n");
    int typeCount = 91;
    int base = N / typeCount;
    int rem = N % typeCount;
    for (int L = 100; L >= 10; --L) {
        int idx = L - 10;
        int cnt = base + (idx < rem ? 1 : 0);
        int suffixWidth = (L >= 14) ? 4 : (L - 9 > 1 ? L - 9 : 1);
        int prefixLen = L - suffixWidth;
        char ch = char('a' + (L % 26));
        string prefix(prefixLen, ch);
        for (int i = cnt - 1; i >= 0; --i) {
            writeRaw(prefix + base26(i, suffixWidth) + "\n");
        }
    }
}

void genStrlenlexi5() {
    const int N = 10000;
    writeRaw("10000\n");
    string prefix(92, 'c');
    int lo = 0, hi = N - 1;
    int printed = 0;
    while (lo <= hi) {
        writeRaw(prefix + base26(lo, 8));
        ++printed;
        if (printed < N)
            writeRaw("\n");
        if (lo != hi) {
            writeRaw(prefix + base26(hi, 8));
            ++printed;
            if (printed < N)
                writeRaw("\n");
        }
        ++lo;
        --hi;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3)
        return 1;
    string problem = argv[1];
    int id = atoi(argv[2]);

    if (problem == "int") {
        if (id == 1)
            genInt1();
        else if (id == 2)
            genInt2();
        else if (id == 3)
            genInt3();
        else if (id == 4)
            genInt4();
        else if (id == 5)
            genInt5();
        else
            return 1;
    }
    else if (problem == "strlexi") {
        if (id == 1)
            genStrlexi1();
        else if (id == 2)
            genStrlexi2();
        else if (id == 3)
            genStrlexi3();
        else if (id == 4)
            genStrlexi4();
        else if (id == 5)
            genStrlexi5();
        else
            return 1;
    }
    else if (problem == "strlenlexi") {
        if (id == 1)
            genStrlenlexi1();
        else if (id == 2)
            genStrlenlexi2();
        else if (id == 3)
            genStrlenlexi3();
        else if (id == 4)
            genStrlenlexi4();
        else if (id == 5)
            genStrlenlexi5();
        else
            return 1;
    }
    else
        return 1;
    return 0;
}
