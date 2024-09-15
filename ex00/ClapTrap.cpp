#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("unknown")
, _hitPoints(10)
, _energyPoints(10)
, _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: _name(name)
, _hitPoints(10)
, _energyPoints(10)
, _attackDamage(0)
{
	std::cout << "Name parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
: _name(other._name)
, _hitPoints(other._hitPoints)
, _energyPoints(other._energyPoints)
, _attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

const std::string& ClapTrap::getName() {
	std::cout << "Name getter called" << std::endl;
	return (_name);
}
const unsigned int& ClapTrap::getHitPoints() {
	std::cout << "Hit points getter called" << std::endl;
	return (_hitPoints);
}
const unsigned int& ClapTrap::getEnergyPoints() {
	std::cout << "Energy points getter called" << std::endl;
	return (_energyPoints);
}

const unsigned int& ClapTrap::getAttackDamage() {
	std::cout << "Attack damage getter called" << std::endl;
	return (_attackDamage);
}

void ClapTrap::setName(const std::string& name){
	std::cout << "Name setter called" << std::endl;
	_name = name;
}

void ClapTrap::setHitPoints(const unsigned int& hitPoint){ 
	std::cout << "Hit points setter called" << std::endl;
	_hitPoints = hitPoint;
}

void ClapTrap::setEnergyPoints(const unsigned int& energyPoints){
	std::cout << "Energy points setter called" << std::endl;
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(const unsigned int& attackDamage){
	std::cout << "Attack damage setter called" << std::endl;
	_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to perform this action" << std::endl;
	}
	else if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no hit points left and can\'t act!" << std::endl;
	}
	else {
		setEnergyPoints(_energyPoints - 1);
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already destroyed and can't take more damage!" << std::endl;
	}
	else if (_hitPoints <= amount) {
		setHitPoints(0);
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and is destroyed!" << std::endl;
	}
	else {
		setHitPoints(_hitPoints - amount);
		std::cout << "ClapTrap" << _name << " takes " << amount << " points of damage but is still standing with " << _hitPoints << " hit points left!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to perform this action" << std::endl;
	}
	else if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is destroyed and can't repair itself!" << std::endl;
	}
	else {
		setEnergyPoints(_energyPoints - 1);
		setHitPoints(_hitPoints + amount);
		std::cout << "ClapTrap " << _name << " repairs itself, restoring " << amount << " hit points! Current hit points: " << _hitPoints << "." << std::endl;
	}
}