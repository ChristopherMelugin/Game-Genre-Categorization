#pragma once
#include <string>
#include <vector>


// Declare game class here
class Game {
public:
	std::string title;
	std::string desc;
	virtual void description(Game& item);
	virtual void addItem(std::vector<Game>& items);
	virtual void printFullList(std::vector<Game>& items);

};

// Declare genre class here
class Genre : public Game {
public:
	std::vector<std::string> exampleGames;
	void description(Game& item);
	void addItem(std::vector<Genre>& items);
	void printFullList(std::vector<Genre>& items);

};