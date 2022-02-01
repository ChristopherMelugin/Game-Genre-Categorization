#include "game.h"
#include <iostream>

// Outputs the description of a game item from within the gameList
void Game::description(Game& item) {
	std::cout << "The description of your chosen game is:\n\n" << item.desc << std::endl;
}

// Adds an item to the gameList vector
void Game::addItem(std::vector<Game>& items) {
	Game newItem;
	std::cout << "Enter name of new game\n";
	std::getline(std::cin, newItem.title);
	std::cout << "Enter short description of the game" << std::endl;
	std::getline(std::cin, newItem.desc);
	items.push_back(newItem);
}

// Print all titles and descriptions from within the gameList
void Game::printFullList(std::vector<Game>& items) {
	for (unsigned int i = 0; i < items.size(); i++) {
		std::cout << items[i].title << std::endl << items[i].desc << std::endl << std::endl;
	}
}


// ~~~~~~~~ GENRE CLASS SPECIFIC FUNCTIONS ~~~~~~~~

// Outputs the description of a genre item from within the genreList
void Genre::description(Game& item) {
	std::cout << "The description of your chosen genre is:\n\n" << item.desc << std::endl;
}

// Adds an item to the genreList vector
void Genre::addItem(std::vector<Genre>& items) {
	Genre newItem;
	std::string game;
	std::cout << "Enter name of new genre\n";
	std::getline(std::cin, newItem.title);
	std::cout << "Enter short description of the genre" << std::endl;
	std::getline(std::cin, newItem.desc);
	std::cout << "Which games fall under this genre? (Add 3)" << std::endl;
	std::getline(std::cin, game);
	newItem.exampleGames.push_back(game);
	std::getline(std::cin, game);
	newItem.exampleGames.push_back(game);
	std::getline(std::cin, game);
	newItem.exampleGames.push_back(game);
	items.push_back(newItem);
}

// Print all titles, descriptions and example games from within the genreList
void Genre::printFullList(std::vector<Genre>& items) {
	for (unsigned int i = 0; i < items.size(); i++) {
		std::cout << std::endl << items[i].title << std::endl << items[i].desc << std::endl;
		std::cout << "Example games are:\n";
		for (unsigned int j = 0; j < items[i].exampleGames.size(); j++) {
			std::cout << items[i].exampleGames[j] << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

