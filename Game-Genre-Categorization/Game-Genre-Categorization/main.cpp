#include <iostream>
#include "game.h"

std::string input, input1;
Genre genre;
Game game;
std::vector<Game> gameList;
std::vector<Genre> genreList;

// Outputs just the titles in the list
template <typename T>
void printTitles(std::vector<T>& items) {
	for (unsigned int i = 0; i < items.size(); i++) {
		std::cout << items[i].title << std::endl;
	}
}

// Searches the list for a match to an input value and calls the polymorphed function to print the description.
template <typename T>
void searchList(std::vector<T>& items) {
	std::getline(std::cin, input1);
	for (unsigned int i = 0; i < items.size(); i++) {
		if (input1 == items[i].title) {
			items[i].description(items[i]);;
		}
	}
}

// Exception handling for strings that are not convertable to integers
bool validate_input(std::string input) {

	try {
		return std::stoi(input);
	}
	catch (...) {
		std::cout << "Invalid input. Please try again\n";
		return false;
	}
	return true;
}

int main() {

	// Populate a few games
	Game game1, game2, game3;
	game1.title = "Chasm";
	game1.desc = "Explore the depths below a remote mountain town in this procedurally-generated Adventure Platformer. Taking inspiration from hack 'n slash dungeon crawlers and Metroidvania-style platformers, Chasm will immerse you in a fantasy world full of exciting treasure, deadly enemies, and abundant secrets.";
	gameList.push_back(game1);

	game2.title = "Stardew Valley";
	game2.desc = "You've inherited your grandfather's old farm plot in Stardew Valley. Armed with hand-me-down tools and a few coins, you set out to begin your new life. Can you learn to live off the land and turn these overgrown fields into a thriving home?";
	gameList.push_back(game2);

	game3.title = "Wizard of Legend";
	game3.desc = "Wizard of Legend is a no-nonsense, action-packed take on wizardry that emphasizes precise movements and smart comboing of spells in a rogue-like dungeon crawler that features over a hundred unique spells and relics!";
	gameList.push_back(game3);


	// Populate a few genres
	Genre genre1, genre2;
	genre1.title = "Action";
	genre1.desc = "Games where the player is in control of and at the center of the action, which is mainly comprised of physical challenges players must overcome.";
	genre1.exampleGames.push_back("Super Mario Bros.");
	genre1.exampleGames.push_back("Halo");
	genre1.exampleGames.push_back("Metroid");
	genreList.push_back(genre1);

	genre2.title = "Adventure";
	genre2.desc = "Players usually interact with their environment and other characters to solve puzzles with clues to progress the story or gameplay.";
	genre2.exampleGames.push_back("The Legend of Zelda");
	genre2.exampleGames.push_back("Metroid");
	genre2.exampleGames.push_back("CrossCode");
	genreList.push_back(genre2);


	// Main program loop
	while (true) {

		// Menu
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl
			<< "~~VIDEO GAME CATEGORIZATION MENU~~" << std::endl
			<< "1: View all games" << std::endl
			<< "2: View all genres" << std::endl
			<< "3: Learn about a game" << std::endl
			<< "4: Learn about a genre" << std::endl
			<< "5: Add a new game" << std::endl
			<< "6: Add a new genre" << std::endl
			<< "Other: Exit program\n" << std::endl
			<< "Input number of menu item" << std::endl;

		// Recieve menu selection
		(std::cin >> input).ignore();


		if (!validate_input(input)) {
			continue;
		}

		// Switch statement to handle chosen features
		switch (std::stoi(input)) {
		case 1:		// Output the titles and description of each object in the gameList
			game.printFullList(gameList);
			break;

		case 2:		// Output the titles and descriptions of each object in the genreList
			genre.printFullList(genreList);
			break;

		case 3:		// Select a game and see its description
			std::cout << "Select a GAME from the list:(CASE SENSITIVE)" << std::endl;
			printTitles(gameList);
			searchList(gameList);
			break;

		case 4:		// Select a genre and see its description and applicable games
			std::cout << "Select a GENRE from the list: (CASE SENSITIVE)" << std::endl;
			printTitles(genreList);
			searchList(genreList);
			break;

		case 5:		// Add a new game to the list
			std::cout << "New Game" << std::endl;
			game.addItem(gameList);
			break;

		case 6:		// Add a new genre to the list
			std::cout << "New Genre" << std::endl;
			genre.addItem(genreList);
			break;

		default:	// Exits the program
			return 0;
		}
	}
}