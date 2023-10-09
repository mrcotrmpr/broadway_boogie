#ifndef CONSOLE_UI_HPP
#define CONSOLE_UI_HPP

#include <iostream>
#include "domain/museum.hpp"
#include "domain/artist.hpp"

class ConsoleUI {
public:
	void start();
private:
	void displayMenu() const;
	void processChoice(int choice);
	void printArtists(std::vector<std::shared_ptr<Artist>> artists) const;
	void printMuseum(std::shared_ptr<Museum> museum) const;
	void startPresentation();
	std::vector<std::shared_ptr<Artist>> artists;
	std::shared_ptr<Museum> museum;
};

#endif // CONSOLE_UI_HPP
