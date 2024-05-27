#include <iostream>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> ordered_configuration(std::string configuration) {
    std::vector<std::string> v;
    std::map<std::string, bool> mp;
    std::string temp = "";
    for (int i = 0; i < configuration.length(); i++) {
        if (configuration[i] != '|') {
            temp += configuration[i];
        } else {
            if (mp[temp]) {
                std::cout << "[\"Invalid configuration\"]" << std::endl;
                return {};
            }
            mp[temp] = true;
            v.push_back(temp);
            temp = "";
        }
    }
    // Push the last substring
    if (mp[temp]) {
        std::cout << "[\"Invalid configuration\"]" << std::endl;
        return {};
    }
    v.push_back(temp);
    return v;
}

int main() {
    std::string str = "0002f7c22e7904|000176a3a4d214|000305d29f4a4b";
    std::vector<std::string> v = ordered_configuration(str);
    for (const auto& s : v) {
        std::cout << s << std::endl;
    }
    return 0;
}