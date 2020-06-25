
#include "game.h"
#include <conio.h>
using namespace std;

int main() {

 Game game;
 game.welcome();
 game.wait();
 game.showAllPlayers();
 game.wait();
 game.selectPlayers();
 game.wait();
 game.showPlayers();
 cout<<"\n\t\t\t\t Press enter for toss\n";
 getchar();
 game.toss();

 game.startFirstInnings();

 game.playInnings();
 game.wait();
 game.secondInnings();

    getch();
	return 0;
}
