#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "card.h"
#include "warplayer.h"

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cout << "Provide number of games to simulate and 1=debug, 0=no debug " << endl;
    return 1;
  }
  srand(time(0));
  int numSims = atoi(argv[1]);
  bool debug = atoi(argv[2]);
  int numBattles = 0;
  int numWars = 0;
  int p1Wins = 0;
  int p2Wins = 0;
  Card* Spoils = new Card[56];



  for(int i=0; i < numSims; i++){

    // Write your single game of War code here (or decompose 
    // the single game into smaller functions that you write)
    // We've started things for you

    // Declare and prepare your deck then print it out to double check
    Deck d;
    d.shuffle();
    d.cut();
    if(debug){
      d.printDeck();
    }

    // Declare the two players and deal the cards to the two players
    WarPlayer Achilles;
    WarPlayer Hector;

    for (int i = 0; i < 26; i ++) {
      Achilles.addCard(d.getTop());
      Hector.addCard(d.getTop());
    }



    // Write a loop that plays one turn at a time, until the game is over
    // Remember each player takes their top card, compares them, and the
    //  player with the greater-valued card gets back both
    // If there is a tie, each player flips one more card (provided they have
    //  one more), with the player with the greater-valued 2nd card getting
    //  all the cards.  If they don't have one more to flip, that player 
    //  immediately loses

    // Be sure to update the statistics variables, numBattles, numWars,
    //  p1Wins, p2Wins, etc.
    Card A1;
    Card H1;

    while (Achilles.SizeBool() && Hector.SizeBool()) {
      int Counter = 0;

      A1 = Achilles.removeTopCard();
      H1 = Hector.removeTopCard();
      numBattles++;
      if (debug){
        cout << A1.toString() << endl;
        cout << H1.toString() << endl;
      }

      int Outcome = A1.compare(H1);
      //p1wins
      if (Outcome == 1) {
        Achilles.addCard(A1);
        Achilles.addCard(H1);
        p1Wins++;
        if (debug){
          cout << "Player 1 Wins ";
          cout << Achilles.SizeValue() << ":" << Hector.SizeValue() << endl;
          cout << "____________________________" << endl;
        }
      }
      //p2wins
      else if (Outcome == -1){
        Hector.addCard(H1);
        Hector.addCard(A1);
        p2Wins++;
        if (debug){
          cout << "Player 2 Wins ";
          cout << Achilles.SizeValue() << ":" << Hector.SizeValue() << endl;
          cout << "____________________________" << endl;
        }
      }
      //war
      else if (Outcome == 0){
        numWars++;
        bool Status = true;
        //add cards to temp array
        Spoils[Counter] = A1;
        Counter++;
        Spoils[Counter] = H1;
        Counter++;

        while (Status){
          //check to see if both have cards to play
          if (Achilles.SizeBool() && Hector.SizeBool()){
            //compare new cards from each deck
            Card A2 = Achilles.removeTopCard();
            Card H2 = Hector.removeTopCard();
            if (debug){
              cout << A2.toString() << endl;
              cout << H2.toString() << endl;
            }
            Outcome = A2.compare(H2);

            Spoils[Counter] = A2;
            Counter++;
            Spoils[Counter] = H2;
            Counter++;
          }

          //p1wins
          if (Outcome == 1 or Hector.SizeBool() == false) {
            for (int i = 0; i < Counter; i++){
              Achilles.addCard(Spoils[i]);
            }
            p1Wins++;
            Status = false;
            if (debug){
              cout << "Player 1 Wins ";
              cout << Achilles.SizeValue() << ":" << Hector.SizeValue() << endl;
              cout << "____________________________" << endl;
            }
          }
          //p2wins
          if (Outcome == -1 or Achilles.SizeBool() == false) {
            for (int i = 0; i < Counter; i++){
              Hector.addCard(Spoils[i]);
            }
            p2Wins++;
            Status = false;
            if (debug){
              cout << "Player 1 Wins ";
              cout << Achilles.SizeValue() << ":" << Hector.SizeValue() << endl;
              cout << "____________________________" << endl;
            }
          }

        }//end of while within war
      }//end of war
    }//end of while
    


  while (Achilles.SizeBool()){
    A1 = Achilles.removeTopCard();
  }
  while (Hector.SizeBool()){
    H1 = Hector.removeTopCard();
  }
  } // end for

  delete [] Spoils;
  
  // Print statistics
  cout << "Total Battles = " << static_cast<double>(numBattles)/numSims << endl;
  cout << "Total Wars = " << static_cast<double>(numWars)/numSims << endl;
  cout << "P1 wins = " << static_cast<double>(p1Wins)/numSims << endl;
  cout << "P2 wins = " << static_cast<double>(p2Wins)/numSims << endl;
  return 0;
}
