#include <iostream>
#include <chrono>
#include <string>
#include <sstream>




int main() {
    std::string s;
    std::stringstream ss;
    long long res = 0;
    std::cin>>s;
    for (auto &ch : s) {
        if (ch == '-') {
            ch = ' ';
        }
    }
    ss << s << std::endl;
    int y, m, d;
    ss >> y >> m >> d;

    auto prev = std::chrono::year{y}/m/d;
    while (std::cin >> s) {
        if (s == "a") break;

        for (auto &ch : s) {
            if (ch == '-') {
                ch = ' ';
            }
        }
        ss << s << std::endl;
        ss >> y >> m >> d;

        auto cur = std::chrono::year{y}/m/d;
        res += abs((std::chrono::sys_days{cur} - std::chrono::sys_days{prev}).count());

        prev = cur;
    }


    std::cout << res << std::endl;
    return 0;
}


