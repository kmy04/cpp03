#include "FragTrap.hpp"

int main() {


    std::cout << "FragTrap 기본 생성자 및 이름을 받는 생성자 테스트" << std::endl;
    FragTrap frag1;
    FragTrap frag2("frag");
	std::cout << std::endl;
    
    std::cout << "FragTrap 복사 생성자 및 복사 대입 연산자 테스트" << std::endl;
    FragTrap frag3(frag2);
    frag1 = frag2;
	std::cout << std::endl;
    
    std::cout << "기능 테스트" << std::endl;
    frag2.attack("target");
    frag2.highFivesGuys();
	std::cout << std::endl;

	std::cout << "소멸자 테스트" << std::endl;
    
    return 0;
}
