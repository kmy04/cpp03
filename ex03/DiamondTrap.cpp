#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : _name("unknown") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	ClapTrap::_name = "unknown_clap_trap";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :  _name(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	ClapTrap::_name = _name + "_clap_trap";
    std::cout << "DiamondTrap name parameter constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : _name(other._name) {
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	ClapTrap::_name = _name + "_clap_trap";
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		ClapTrap::_name = _name + "_clap_trap";
        _name = other._name;
    }
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
    std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
