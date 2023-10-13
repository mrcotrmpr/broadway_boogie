#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "domain/museum.hpp"
#include "domain/artist.hpp"
#include "memory"

class SDLFacade;

class Game : public std::enable_shared_from_this<Game> {
public:
	void start();
	void displayMenu() const;
	void processChoice(int choice);
	void printArtists() const;
	void printMuseum() const;
	void startPresentation();
	std::vector<std::shared_ptr<Artist>> artists;
	std::shared_ptr<Museum> museum;
	std::shared_ptr<SDLFacade> sdl;
};

#endif // GAME_HPP
