#include <iostream>
#include <list>

bool func(std::string &a, std::string &b) {
    return a + b > b + a;
}

int main(){
    std::list<std::string> st;
    std::string inp;
    while (std::cin >> inp) st.push_back(inp);
    st.sort(func);
    for(std::string& i: st) std::cout << i;
    return 0;
}