#include <iostream>
#include <string>
#include <stack>
#include <vector>

int main () {
  std::string zoo;
  std::cin >> zoo;
  const int n = zoo.size();
  std::vector<int> vec(n / 2);
  std::stack<char> stck;
  std::stack<int> animals;
  std::stack<int> traps;
  stck.push(-1);
  int animal_id = 0;
  int trap_id = -1;
  for (std::size_t i = 0; i < n; i++) {
    char cur = zoo[i];
    if (!islower(cur)) {
      trap_id += 1;
      traps.push(trap_id);
    }
    if (islower(cur)) {
      animal_id += 1;
      animals.push(animal_id);
    }
    if (cur == (stck.top() + 32) || cur == (stck.top() - 32)) {
      stck.pop();
      vec[traps.top()] = animals.top();
      animals.pop();
      traps.pop();
    } else {
      stck.push(cur);
    }
  }
  stck.pop();
  if (stck.empty()) {
    std::cout << "Possible" << std::endl;
    for(std::size_t j = 0; j < (n / 2); j++) {
      std::cout << vec[j] << " ";
    }
  } else std::cout << "Impossible" << std::endl;
  return 0;
}