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
	void removeArtist(std::shared_ptr<Artist> artist);
	std::shared_ptr<Node> getNode(float x, float y, float scaleX, float scaleY);
	std::shared_ptr<Artist> getArtist(float x, float y, float scaleX, float scaleY);
	std::vector<std::shared_ptr<Artist>> artists;
	std::vector<std::shared_ptr<Artist>> newArtists;
	std::shared_ptr<Museum> museum;
	std::shared_ptr<SDLFacade> sdl;
	bool artistsMoving = false;
	bool menuVisible = false;
	int windowWidth = 800;
	int windowHeight = 800;
	float scaleX = static_cast<float>(windowWidth) / 53.0f;
	float scaleY = static_cast<float>(windowHeight) / 53.0f;
};

#endif // GAME_HPP
