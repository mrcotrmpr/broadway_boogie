#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "domain/museum.hpp"
#include "domain/artist.hpp"
#include "domain/node.hpp"
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
	std::shared_ptr<Node> getNode(float x, float y, float scaleX, float scaleY);
	std::shared_ptr<Artist> getArtist(float x, float y, float scaleX, float scaleY);
	std::vector<std::shared_ptr<Artist>> artists;
	std::shared_ptr<Museum> museum;
	std::shared_ptr<SDLFacade> sdl;
};

#endif // GAME_HPP
