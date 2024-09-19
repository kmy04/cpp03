#include "ScavTrap.hpp"

int main() {
    // virtual 키워드 테스트
	std::cout << "virtual 키워드 테스트" << std::endl;
	ClapTrap* ptr = new ScavTrap("Scavvy");
	
	std::cout << std::endl;


    std::cout << "ScavTrap 기본 생성자 및 이름을 받는 생성자 테스트" << std::endl;
    ScavTrap scav1;
    ScavTrap scav2("Scavvy");
	std::cout << std::endl;
    
    std::cout << "ScavTrap 복사 생성자 및 복사 대입 연산자 테스트" << std::endl;
    ScavTrap scav3(scav2);
    scav1 = scav2;
	std::cout << std::endl;
    
    std::cout << "기능 테스트" << std::endl;
	ptr->attack("target1");
	scav1.attack("target2");
	scav1.guardGate();
	std::cout << std::endl;

	std::cout << "소멸자 테스트" << std::endl;
	delete ptr;  // ScavTrap 소멸자 -> ClapTrap 소멸자 호출
    
    return 0;
}
