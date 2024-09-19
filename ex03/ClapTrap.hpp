#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
// private에서 protected로 변경한 이유는 private은 상속되지 않기 때문이다. 
// 과제에 요구사항에서 ScavTrap은 ClapTrap의 속성들을 사용할 것이라고 했기 때문에
// protected로 변경해줬다.
protected :
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
public :
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	// 소멸자 앞에 virtual 키워드를 붙이는 이유는 다형성(polymorphism)을 지원하기 위해서이다. 
	// 특히, 상속을 사용하는 클래스에서 소멸자를 가상 함수로 정의함으로써, 기본 클래스(부모 클래스)의 포인터로 파생 클래스(자식 클래스) 객체를 가리킬 때, 
	// 해당 포인터를 통해 객체가 삭제될 경우 올바르게 파생 클래스의 소멸자가 호출되도록 보장하는 역할을 한다.
	// C++에서 다형성을 사용할 때, 기본 클래스의 포인터로 파생 클래스 객체를 가리키는 경우가 자주 발생한다.
	// 예를 들어 ClapTrap* ptr = new ScavTrap("Scavvy");
	// delete ptr;  // ScavTrap 객체를 삭제하지만, ClapTrap 포인터로 삭제
	// 위와 같은 상황에서, 기본 클래스인 ClapTrap의 소멸자가 가상 함수가 아닌 경우, delete ptr;는 ClapTrap의 소멸자만 호출하고,
	// ScavTrap의 소멸자는 호출하지 않는다. 이로 인해, 파생 클래스의 자원(예: 동적 할당된 메모리)이 적절하게 해제되지 않을 수 있습니다.
	virtual ~ClapTrap();

	const std::string& getName() const;
	const unsigned int& getHitPoints() const;
	const unsigned int& getEnergyPoints() const;
	const unsigned int& getAttackDamage() const;

	void setName(const std::string& name);
	void setHitPoints(const unsigned int& hitPoint);
	void setEnergyPoints(const unsigned int& energyPoints);
	void setAttackDamage(const unsigned int& attackDamage);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif