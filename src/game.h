#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"

class Game {
	public:
	 Game();
	 void welcome();
	 void showAllPlayers();
	 void wait();
	 int takeIntergerInput();
	 void selectPlayers();
	 bool validateSelectedPlayer(int);
	 void showPlayers();
	 void toss();
	 void tossChoice(Team);
	 void startFirstInnings();
	 void initializePlayer();
	 void playInnings();
	 void bat();
	 bool validateInningsScore();
    void showScoreCard();
    void secondInnings();
    void secondInitialization();
    void secondBat();
    void decider();
    void final();

	 int playersPerTeam;
	 int maxBalls;
	 int totalPlayers;
	 std::string players[11];
     int firstInningsRuns;
     int secondInningsRuns;

	 bool isFirstInnings ;
	 Team teamA,teamB ;
	 Team *battingTeam,*bowlingTeam ;
	 Team *firstInningTeam,*secondInningTeam;
	 Player *batsmen,*bowler;

};
