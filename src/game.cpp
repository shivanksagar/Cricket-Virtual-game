# include "game.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Game:: Game() {

	playersPerTeam = 4;
	maxBalls=6;
	totalPlayers=11;
	firstInningsRuns=0;
	secondInningsRuns=0;


	players[0]="virat";
	players[1]="ponting";
	players[2]="sehwag";
	players[3]="sachin";
	players[4]="dravid";
	players[5]="dhoni";
	players[6]="yuvraj";
	players[7]="kumble";
	players[8]="lee";
	players[9]="bell";
	players[10]="ambrose";

	isFirstInnings = false ;
	teamA.name="Team-A";
	teamB.name="Team-B";

}

void Game ::welcome(){
cout<<"\t\t\t\t---------------------------------------\n";
cout<<"\t\t\t\t|================CRIC-IN==============|\n";
cout<<"\t\t\t\t|                                     |\n";
cout<<"\t\t\t\t|   Welcome to virtual cricket game   |\n";
cout<<"\t\t\t\t---------------------------------------\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\t\t\t\t------------------------------------------------------\n";
cout<<"\t\t\t\t|======================Instructions===================|\n";
cout<<"\t\t\t\t-------------------------------------------------------\n";
cout<<"\t\t\t\t|                                                     |\n";
cout<<"\t\t\t\t|1.Create two teams (Team-A and Team-B with 4 players |\n";
cout<<"\t\t\t\t| players each) from a given pool of 11 players.      |\n";
cout<<"\t\t\t\t|2.Lead the toss and decide the choice of play.       |\n";
cout<<"\t\t\t\t|3.Each innings will be of 6 balls.                   |\n";
cout<<"\t\t\t\t-------------------------------------------------------\n";
cout<<"\n";
cout<<"\n";

}

void Game ::wait(){

	 do
	  {
	    cout << '\n' << "\t\t\t\tPress a key to continue...";
	  } while (cin.get() != '\n');

}
void Game :: showAllPlayers(){
	cout<<"\n";
	cout<<"\n";
    cout<<"\t\t\t\t--------------------------------------\n";
    cout<<"\t\t\t\t||/////////// Pool of Players \\\\\\\\\\||\n";
    cout<<"\t\t\t\t--------------------------------------\n";
    cout<<"\n";
    cout<<"\n";

for(int i=0 ; i < 11; i++){
   cout <<"\t\t\t\t["<<i<<"]"<<players[i]<<"\n"; }
}

int Game ::takeIntergerInput(){
	int n ;
	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"\t\t\t\tIt is a invalid inoput!Please enter a valid input";

	}
return n ;
}

bool Game::validateSelectedPlayer(int index){

	int n ;
	vector <Player> players;
	players=teamA.players ;
    n=players.size();
    for (int i=0;i < n; i++){

    	if(players[i].id == index){
    		return  false;
               }
    	}

    players=teamB.players ;
        n=players.size();
        for (int i=0;i < n; i++){

        	if(players[i].id == index){
        		return  false;
                   }
        }
    return true ;

}

void Game ::selectPlayers(){

cout<<"\t\t\t\t---------------------------------------------------\n";
cout<<"\t\t\t\t||     Select players for Team-A and Team-B      ||\n";
cout<<"\t\t\t\t---------------------------------------------------\n";

for (int i =0;i < playersPerTeam ;i++ ){

 teamASelection:
	 cout<<"\t\t\t\tselect player "<<i+1<<" for Team-A -  ";
	 int playerIdForTeamA =  takeIntergerInput();
	 if (playerIdForTeamA < 0 || playerIdForTeamA > 10 ){
		 cout<<"\t\t\t\t Please enter a valid no from the pool\n";
		 goto teamASelection;
	 }
	 else if(!validateSelectedPlayer(playerIdForTeamA)){
	 	          cout<<"\nSame player selected.Please select some other player from the pool\n";
	 	          goto teamASelection;
	 	 	 }
	 else {
		 Player teamAPlayer;
		 teamAPlayer.id=playerIdForTeamA;
		 teamAPlayer.name=players[playerIdForTeamA];
		 teamA.players.push_back(teamAPlayer);
	 }

 teamBSelection:
 cout<<"\t\t\t\tselect player "<<i+1<<" for Team-B -   ";
  int playerIdForTeamB =  takeIntergerInput();
  if (playerIdForTeamB <0 || playerIdForTeamB >10  ){
	  cout<<"\t\t\t\t Please enter a valid no from the pool\n";
	  goto teamBSelection;
  }
  else if ( !validateSelectedPlayer(playerIdForTeamB) ){
       cout<<"\t\t\t\tSame player selected .Please seclect some other player from the pool\n";
       goto teamBSelection;
	 }
  else{
	  Player teamBPlayer;
	    teamBPlayer.id=playerIdForTeamB;
	    teamBPlayer.name=players[playerIdForTeamB];
	    teamB.players.push_back(teamBPlayer);
  }
}
}

void Game::showPlayers(){

vector<Player> teamAPlayers= teamA.players ;
vector<Player> teamBPlayers= teamB.players ;

cout<<endl<<endl;
cout<<"\t\t\t\t------------------------\t\t--------------------------\n";
cout<<"\t\t\t\t||-------Team-A---------||\t\t||--------Team-B--------||\n";
cout<<"\t\t\t\t-------------------------\t\t -----------------------\n";

for (int i=0;i < playersPerTeam;i++){
cout << "\t\t\t\t\t\t[" << i << "]"<<teamA.players[i].name << "\t";
cout<<"\t\t\t\t\t\t\t\t";
cout <<"\t\t\t\t\t\t\t[" << i <<"]" << teamB.players[i].name << "\t\t \n";

}

cout<<"\t\t\t\t--------------------------------------------------------------\n";
}

void Game::toss(){
cout<<"\t\t\t\t-----------------------------------------------------\n";
cout<<"\t\t\t\t||====================let's Toss===================||\n";
cout<<"\t\t\t\t-----------------------------------------------------\n";

	srand (time(NULL));
	int tossValue = rand() % 2;

	switch (tossValue) {
			case 0:
				cout << "\t\t\t\tTeam-A won the toss" << endl << endl;
				tossChoice(teamA);
				break;
			case 1:
				cout << "\t\t\t\tTeam-B won the toss" << endl << endl;
				tossChoice(teamB);
				break;
	    }
}

void Game::tossChoice(Team tossChoiceWinner){
	cout<<"\n\t\t\t\t Enter 1 for BAT and 2 for bowl .\n";

	int tossValue=takeIntergerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
     switch(tossValue){
    		case 1:
    			cout<<"\n\t\t\t\t"<<tossChoiceWinner.name<<" won the toss and elected to bat first"<<"\n"<<"\n";
    			if(tossChoiceWinner.name.compare("Team-A")==0){
    				battingTeam=&teamA;
    				bowlingTeam=&teamB;
    			}else{
    				battingTeam=&teamB;
    				bowlingTeam=&teamA;
    			}
    			break;
    		case 2:
    			cout<<"\n\t\t\t\t"<<tossChoiceWinner.name<<" won the toss and elected to bowl first"<<"\n"<<"\n";
    			if(tossChoiceWinner.name.compare("Team-A")==0){
    			    bowlingTeam=&teamA;
    			    battingTeam=&teamB;
    			   }else{
    				   bowlingTeam = &teamB;
    				   battingTeam = &teamA;
    			      }
    			break;
    		default:
    			cout<<"Invalid Input please try again";
    			tossChoice(tossChoiceWinner);
    			break;
}
}

void Game::startFirstInnings(){

	cout<<"\n\t\t\t\t |||| FIRST INNINGS BEGINGS||||\n";
	isFirstInnings= true;
	initializePlayer();

}
void Game::initializePlayer(){

	batsmen=&battingTeam->players[0];
	bowler= &bowlingTeam->players[0];

	cout<<"\t\t\t\t"<<battingTeam->name<<" "<<batsmen->name<<" "<<" is batting \n";
	cout<<"\t\t\t\t"<<bowlingTeam->name<<" "<<bowler->name<<" "<<"is bowling\n";

}

void Game::secondInnings(){

	cout<<"\n\t\t\t\t\t\t\t\ |||| SECOND INNINGS BEGINGS||||\n";
     isFirstInnings=false;

     Team * tempTeam = battingTeam;
    	    battingTeam = bowlingTeam;
    	    bowlingTeam = tempTeam;

              initializePlayer();
              playInnings();
 }


void Game ::playInnings(){

for(int i=0;i < maxBalls; i++){
	cout<<"\t\t\t\tPress enter to bowl.\n";
	getchar();
	cout<<"\t\t\t\tBowling.....\n";
	bat();
    if (!validateInningsScore()){
        break;
      }
    }
}

void Game ::bat(){

 srand(time(NULL));
 int runsScored= rand()%7 ;

 // Updating Batsmen Score and Batting team score
	batsmen->runsScored=batsmen->runsScored+runsScored;
	battingTeam->totalRunsScored=battingTeam->totalRunsScored+runsScored;
	batsmen->ballsPlayed=batsmen->ballsPlayed+1;


 // Updating Bowler runs given and bowling team scorecard
   bowler->runsGiven=bowler->runsGiven=runsScored;
   bowlingTeam->totalBowlsBowled=bowlingTeam->totalBowlsBowled+1;
   bowler->ballsBowled=bowler->ballsBowled+1;



   if (runsScored != 0){


	   cout<<endl<<"\t\t\t\t"<<bowler->name<<" to "<<batsmen->name<<" " << runsScored <<" runs!"<<"\n";
	   showScoreCard();
   }else{
	   cout<<endl<<"\t\t\t\t"<<bowler->name<<" to "<<batsmen->name<<" " << runsScored <<" OUT!"<<"\n";

	   battingTeam->Wicketslost=battingTeam->Wicketslost+1;
	   bowler->wicketsTaken=bowler->wicketsTaken+1;
	   showScoreCard();
	   int nextPlayerIndex = battingTeam->Wicketslost;
	   batsmen=&battingTeam->players[nextPlayerIndex];
   }
}

bool Game ::validateInningsScore(){
	if (isFirstInnings) {

			if (battingTeam->Wicketslost == playersPerTeam || bowlingTeam->totalBowlsBowled == maxBalls) {

				cout << "\t\t\t\t\t\t\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

				cout <<"\t\t\t\t" <<battingTeam->name << " " << battingTeam->totalRunsScored << " - "
						<< battingTeam->Wicketslost << " (" << bowlingTeam->totalBowlsBowled
						<< ")" << endl;

				cout <<"\t\t\t\t"<< bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
						<< " runs to win the match" << endl << endl;
				firstInningsRuns=battingTeam->totalRunsScored;

                firstInningTeam=battingTeam;

				return false;
			}
	    } else {
	    	if(secondInningsRuns>firstInningsRuns){
	    		  cout << "\t\t\t\t\t\t\t\t ||| SECOND INNINGS ENDS ||| " << endl << endl;
	    		   cout<<"\t\t\t\t"<<secondInningTeam->name<<" has won the match\n";
	    		   cout<<"\n";
	    		   cout<<"\n";
	    		   cout<<"\n";
	    		   cout<<"\n";
	    		   cout<<"\t\t\t\t=============MATCH ENDS=======================\n";
                   final();
	    		   return false;
	    		             }

	    	else if (battingTeam->Wicketslost == playersPerTeam || bowlingTeam->totalBowlsBowled == maxBalls) {

                cout << "\t\t\t\t\t\t\t\t ||| SECOND INNINGS ENDS ||| " << endl << endl;
                secondInningsRuns=battingTeam->totalRunsScored;
                secondInningTeam=battingTeam;
                decider();
                final();
                return false;
                }

	    }

		return true;
}



void Game::decider(){

	 if(firstInningsRuns>secondInningsRuns){
	   cout<<"\t\t\t\t"<<firstInningTeam->name<<" has won the match\n";
	   cout<<"\n";
	   cout<<"\n";
	   cout<<"\n";
	   cout<<"\n";
	   cout<<"\t\t\t\t=============MATCH ENDS=======================\n";
	             }
	else{
	   cout<<"\t\t\t\t Match has been drawn\n";
	   cout<<"\n";
	   cout<<"\n";
	   cout<<"\n";
	   cout<<"\n";
	   cout<<"\t\t\t\t=============MATCH ENDS=======================\n";
	             }
}
void Game ::showScoreCard(){


	cout<<"\t\t\t\t---------------------------------------------------------------------------------";
	cout<<"\t\t\t\t\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<"-"<<battingTeam->Wicketslost
                       <<"("<<bowlingTeam->totalBowlsBowled<<")"<<"|"<<batsmen->name<<" "<<batsmen->runsScored
					   <<" "<<"("<<batsmen->ballsPlayed<<")"<<"\t\t"<<bowler->name<<" "<<bowlingTeam->totalBowlsBowled
					   <<" "<<bowler->runsGiven <<" "<<battingTeam->Wicketslost<<"  \n";
	cout<<"\t\t\t\t---------------------------------------------------------------------------------";
}
void Game::final(){

cout<<"\n";
cout<<"\n";
cout<<"\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<"("
	<<battingTeam->totalBowlsBowled<<")"<<"\n";
cout<<"\t-----------------------------------------"<<endl;
cout<<"\t|Player \tBatting \t Bowling |\n";

for (int j = 0; j < playersPerTeam; j++) {
    	Player player = battingTeam->players[j];
    	cout << "\t|-------------------------------------|" << endl;
    	cout << "\t| " << "[" << j << "] " << player.name << "  \t "
        	<< player.runsScored << "(" << player.ballsPlayed << ") \t\t "
			<< player.ballsBowled << "-" << player.runsGiven << "-"
			<< player.wicketsTaken << "\t |" << endl;
    }
    cout << "\t==========================================" << endl << endl;

cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\t"<<bowlingTeam->name<<" "<<bowlingTeam->totalRunsScored<<"("
	<<bowlingTeam->totalBowlsBowled<<")"<<"\n";
cout<<"\t-----------------------------------------"<<endl;
cout<<"\t|Player \t Batting \t Bowling |\n";
for (int j = 0; j < playersPerTeam; j++) {
    	Player player = bowlingTeam->players[j];
    	cout << "\t|-------------------------------------|" << endl;
    	cout << "\t| " << "[" << j << "] " << player.name << "  \t "
        	<< player.runsScored << "(" << player.ballsPlayed << ") \t\t "
			<< player.ballsBowled << "-" << player.runsGiven << "-"
			<< player.wicketsTaken << "\t |" << endl;
    }
    cout << "\t==========================================" << endl << endl;


}

