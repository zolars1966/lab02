#include <iostream>

int main() {
    int s = 0;

    for (int i = 1; i <= 5; ++i) {
        int x = i * 2;

        if (x % 3 == 0) {
            s = s + x;
        } else {
            s = s + x * 2;
        }
    }

    std::cout << s;
    return 0;
}
