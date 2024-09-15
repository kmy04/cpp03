#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	const std::string& getName();
	const unsigned int & getHitPoints();
	const unsigned int & getEnergyPoints();
	const unsigned int & getAttackDamage();

	void setName(const std::string& name);
	void setHitPoints(const unsigned int& hitPoint);
	void setEnergyPoints(const unsigned int& energyPoints);
	void setAttackDamage(const unsigned int& attackDamage);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif