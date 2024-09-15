#include "ClapTrap.hpp"

int main() {
	ClapTrap a("ct");

	a.attack("enemy");
	std::cout << a.getEnergyPoints() << std::endl;
	a.setEnergyPoints(0);
	std::cout << a.getEnergyPoints() << std::endl;
	a.attack("enemy");

	a.setEnergyPoints(5);
	a.beRepaired(10);

	a.takeDamage(23);
	a.attack("enemy");
	a.beRepaired(10);

	a.setHitPoints(-1);
	std::cout << a.getHitPoints() << std::endl;
	return (0);
}