#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Name parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		_hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
		std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << _name << " has no energy left to perform this action" << std::endl;
	}
	else if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " has no hit points left and can\'t act!" << std::endl;
	}
	else {
		setEnergyPoints(_energyPoints - 1);
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}