//centralwidget.cpp
#include "centralwidget.h"
#include "mainwindow.h"

CentralWidget::CentralWidget(Player* players[], GUIPlayer* guiplayers[], MainWindow *m): QWidget() {
  currentPlayer = 0;
  mw = m;
  for (int i = 0; i < 4; i++) {
    centralplayers[i] = players[i];
  }

  //show the board image
  boardLabel = new QLabel( this );
  boardLabel->setPixmap( QPixmap("images/900monopoly.jpg") );

  test = new QPixmap ("images/pieces/sun.png");
  //create player holders
  for (int i = 0; i < 4; i++) {
    p[i] = new QPushButton(this);
    p[i] -> hide();
    //connect (p[i], SIGNAL(clicked()), this, SLOT(nextTurn()) );
  }

  //Create the two card images
  chanceFaceDown = new QPixmap( "images/chancefacedown.jpg" );
  communityFaceDown = new QPixmap ( "images/communityfacedown.jpg");

  //Create the button for the chance deck
  chanceDeckButton = new QPushButton( this );
  chanceDeckButton->setIcon( *chanceFaceDown );
  chanceDeckButton->setIconSize( QSize(171, 121) );
  chanceDeckButton->setGeometry( 523, 552, 171, 121);
  //Connect the button to drawCard
  connect( chanceDeckButton, SIGNAL(clicked()), this, SLOT(chance()) );

  //Create the button for the community deck
  communityDeckButton = new QPushButton ( this );
  communityDeckButton -> setIcon (*communityFaceDown);
  communityDeckButton -> setIconSize( QSize(175, 123) );
  communityDeckButton -> setGeometry(201, 225, 175, 123);
  //Connect the button to drawCard
  connect (communityDeckButton, SIGNAL(clicked()), this, SLOT(community()) );


  //create the 2 dice buttons
  faceOne = new QPixmap ("images/die/dice.jpg");
  faceTwo = new QPixmap ("images/die/dice2.jpg");
  faceThree = new QPixmap ("images/die/dice3.jpg");
  faceFour = new QPixmap ("images/die/dice4.jpg");
  faceFive = new QPixmap ("images/die/dice5.jpg");
  faceSix = new QPixmap ("images/die/dice6.jpg");

  diceButton = new QPushButton (this);
  diceButton ->setIcon(*faceOne);
  diceButton ->setIconSize ( QSize(50, 50));
  diceButton -> setGeometry(608, 148, 50, 50);
  //connect the button to rollDie
  connect (diceButton, SIGNAL(clicked()), this, SLOT(rollDie()) );

  diceButton2 = new QPushButton (this);
  diceButton2 ->setIcon(*faceOne);
  diceButton2 ->setIconSize ( QSize(50, 50));
  diceButton2 -> setGeometry(683, 148, 50, 50);
  //connect the button to rollDie
  connect (diceButton2, SIGNAL(clicked()), this, SLOT(rollDie()) );

  //create the buy button
  buy = new QPixmap ( "images/buy.png");
  buyButton = new QPushButton (this);
  buyButton -> setIcon (*buy);
  buyButton -> setIconSize ( QSize(50, 50));
  buyButton -> setGeometry(608, 223, 50, 50);
  connect (buyButton, SIGNAL(clicked()), this, SLOT(buySpace()) );

  //create the upgrade button
  upgrade = new QPixmap ( "images/levelup.png");
  upgradeButton = new QPushButton (this);
  upgradeButton -> setIcon (*upgrade);
  upgradeButton -> setIconSize ( QSize(50, 50));
  upgradeButton -> setGeometry(683, 223, 50, 50);
  connect (upgradeButton, SIGNAL(clicked()), this, SLOT(upgradeAct()) );

  //create end turn button
  endTurn = new QPixmap("images/end.png");
  endButton = new QPushButton (this);
  endButton -> setIcon (*endTurn);
  endButton -> setIconSize (QSize(50,50));
  endButton -> setGeometry (683, 298, 50, 50);
  connect (endButton, SIGNAL(clicked()), this, SLOT(nextTurn()) );

  //create resign button which ends the game
  fliptable = new QPushButton (tr("Resign"), this);
  fliptable -> setGeometry (683, 400, 50, 50);
  connect( fliptable, SIGNAL(clicked()), this, SLOT(flip()) );
  end = new QPushButton (tr("One of the players flipped the table and the game pieces scatter everywhere. The game has ended."), this);
  end -> setGeometry (0, 0, 1000, 1000);
  connect( end, SIGNAL(clicked()), this, SLOT(quit()) );
  end -> hide();

  //setup the tokens for ownership on the board
  setupSpaceTokens();

  //setup the upgrade stars
  setupUpgradeStars();

  //setup little upgrade buttons for each space
  createUpgradeButtons();

  //setup the spaces on the board
  setupSpaces();

  //create the pieces on the board
  showPieces(players);

  //start game with all board buttons disabled;
  disableButtons();

  //setup cards
  setupCards();
}

void CentralWidget::drawCard() {
  //Show the face up card
  /*
  if ( isFaceDown ) {
    cardDeckButton->setIcon( *cardFaceUp );
    isFaceDown = false;
  } else {
    cardDeckButton->setIcon( *cardFaceDown );
    isFaceDown = true;
  }
  */
}

void CentralWidget::rollDie() {
  //most of the game mechanics are in this slot
  //because momvement is determined here
  int diceone = rand()%5 + 1;
  int dicetwo = rand()%5 + 1;
  //diceone = 1;
  //dicetwo = 0;
  //change the face of the two die to reflect what was rolled.
  determineDieFace(diceButton, diceone);
  determineDieFace(diceButton2, dicetwo);

  //disable die buttons so reroll is impossible
  diceButton -> setEnabled(false);
  diceButton2 -> setEnabled (false);

  //check if player is in jail or not
  bool jail = centralplayers[currentPlayer] -> retrieveJail();
  if (jail) {
    //if player rolled a double, player is freed
    if (diceone == dicetwo) {
      centralplayers[currentPlayer] -> setJail(false);
      centralplayers[currentPlayer] -> setJailCounter(0);
      //allows player to reroll and have a full turn
      diceone = 0;
      dicetwo = 0;
      diceButton -> setEnabled(true);
      diceButton2 -> setEnabled(true);
    }
    //check how many rounds player has been stuck in jail
    else {
      centralplayers[currentPlayer] -> incrementJailCounter();
      //if stuck in jail for three turns, term has been served and player is freed
      if (centralplayers[currentPlayer] -> retrieveJCounter() == 3) {
        centralplayers[currentPlayer] -> setJail(false);
        centralplayers[currentPlayer] -> setJailCounter(0);
        //player cannot reroll
        diceone = 0;
        dicetwo = 0;
      }
    }
  }

  //change player's spot
  bool passGo = centralplayers[currentPlayer] -> setCurrentSpace(diceone + dicetwo);
  //physically move the player
  showPieces(centralplayers);
  //enable end button so that round can end
  endButton -> setEnabled(true);

  if (passGo) {
    centralplayers[currentPlayer] -> getMoney(40000);
    mw->updatePlayerGui(currentPlayer);
  }

  GameFunction();

}//end of roll die

void CentralWidget::determineDieFace(QPushButton* dice, int roll) {
  if (roll == 1) {
    dice -> setIcon(*faceOne);
  }
  else if (roll == 2) {
    dice -> setIcon(*faceTwo);
  }
  else if (roll == 3) {
    dice -> setIcon(*faceThree);
  }
  else if (roll == 4) {
    dice -> setIcon(*faceFour);
  }
  else if (roll == 5) {
    dice -> setIcon(*faceFive);
  }
  else if (roll == 6) {
    dice -> setIcon(*faceSix);
  }
}

void CentralWidget::nextTurn() {
  //disables end round button for next player
  endButton -> setEnabled(false);
  //increments current player to reflect whose turn it currently is
  if (currentPlayer < numPlayers - 1) {
    currentPlayer++;
  }
  //resets to player 1 after all players have gone once
  else if (currentPlayer == numPlayers - 1) {
    currentPlayer = 0;
  }
  //check if bus rent prices need to be updated
  updateBuses();
  //shows movement of piece
  showPieces(centralplayers);
  //enables all buttons that should be enabled for the next round
  disableButtons();
  enableButtons();
  //changes the displayed player's stats
  mw->changePlayerGui(currentPlayer);
  checkUpgrade();
}

void CentralWidget::buySpace() {
  //retrieve amount of money needed to make purchase
  int price = spaces[centralplayers[currentPlayer] -> getCurrentSpace()] -> retrieveBuy();
  //decrements the cost from the player
  centralplayers[currentPlayer] -> payMoney(price);
  //update gui to reflect change in money
  mw->updatePlayerGui(currentPlayer);
  //updates space to reflect change in ownership
  spaces[centralplayers[currentPlayer] -> getCurrentSpace()] -> setOwner(currentPlayer);
  updateMonopoly();
  setSpaceOwnerToken(currentPlayer, centralplayers[currentPlayer] -> getCurrentSpace());
  //disable buy button
  buyButton -> setEnabled(false);
  checkUpgrade();
}

void CentralWidget::chance() {
  chanceDeckButton -> setEnabled(false);
  //chancecards[rand()%16] -> show();
  endButton -> setEnabled(true);
}

void CentralWidget::community() {
  communityDeckButton -> setEnabled(false);
  //communitycards[rand()%16] -> show();
  endButton -> setEnabled(true);
}

void CentralWidget::percentTax() {
  //if player chooses to pay 10% of total assets for income tax
  int tenpercent = 0;
  //calculate 10% of cash on hand
  tenpercent += 0.10*centralplayers[currentPlayer] -> getMoney();
  //calculate 10% of property (based on property buy price) and upgrades
  for (int i = 0; i < 40; i++) {
    //find space that player owns
    if (currentPlayer == spaces[i] -> retrieveOwner()) {
      //10% property buy price
      tenpercent += 0.10* spaces[i] -> retrieveBuy();
      //check to see if property is upgrades
      if (spaces[i] -> retrieveUpgrade() > 0) {
        //10% upgrade price
        tenpercent += 0.10* spaces[i] -> retrieveUpgradePrice() * spaces[i] -> retrieveUpgrade();
      }
    }
  }
  //check to see if player can pay
  if (centralplayers[currentPlayer] -> getMoney() > tenpercent) {
    centralplayers[currentPlayer] -> payMoney(tenpercent);
    mw -> updatePlayerGui(currentPlayer);
  }
  //hide menu and show board
  mw -> hidetaxQuestion();
  showAll();
}

void CentralWidget::straightupTax() {
  //if player chooses to pay $40,000 up front for income tax
    //check if player can pay
  if (centralplayers[currentPlayer] -> getMoney() > 40000) {
    centralplayers[currentPlayer] -> payMoney(40000);
    mw -> updatePlayerGui(currentPlayer);
  }
  //hide menu and show board
  mw -> hidetaxQuestion();
  showAll();
}

void CentralWidget::upgradeAct() {
  int upgradecounter = 0; //counter to check if no spaces are upgradable
  for (int i = 0; i<40; i++) {
    //check ownership
    if (spaces[i] -> retrieveOwner() == currentPlayer) {
      //check bool for monopoly
      if(spaces[i] -> checkMonopoly()) {
        //check if affordable
        if (spaces[i] -> retrieveUpgradePrice() < centralplayers[currentPlayer] -> getMoney()){
          //check if not fully upgraded
          if (spaces[i] -> retrieveUpgrade() != 5){
            showUpgradeButton(i);
            upgradecounter++;
          }
        }
      }
    }
  }
  if (upgradecounter == 0){
    upgradeButton -> setEnabled(false);
  }
}

void CentralWidget::tinyupgrade(int space) {
  //make player pay for the upgrade
  centralplayers[currentPlayer] -> payMoney(spaces[space] -> retrieveUpgradePrice());
  //update stats to reflect loss of money
  mw -> updatePlayerGui(currentPlayer);
  //update space data to reflect upgrade
  spaces[space] -> upgradesingle();
  //show the upgrade
  int numUpgrades = spaces[space] -> retrieveUpgrade();
  for (int i = 0; i < numUpgrades; i++) {
    upgradeStars[space*5+i] -> show();
  }
  if (spaces[space] -> retrieveUpgrade() == 5) {
    //hide button if fully upgraded
    upgradeButtons[space] -> hide();
  }
}


void CentralWidget::GameFunction() {
  //find what type of space it is
  int type = spaces[centralplayers[currentPlayer] -> getCurrentSpace()] -> retrieveType();

  //check if landed space is buyable and if so, check if player can afford to make the purchase
  bool buyable = spaces[centralplayers[currentPlayer] -> getCurrentSpace()] -> checkBuyable();
  int price = spaces[centralplayers[currentPlayer] -> getCurrentSpace()] -> retrieveBuy();
  if (buyable and (centralplayers[currentPlayer] -> getMoney() > price)) {
    //if both criteria are met, buy button is enabled -- the player still has the option to 
    //end the round without buying
    buyButton -> setEnabled(true);
  }

  //check if landed space is owned by someone else and if so, pay the rent
  int owner = spaces[centralplayers[currentPlayer] -> getCurrentSpace()] -> retrieveOwner();
    //check to see if owned by player
  if (!buyable and owner != -1 ) {
      //check to see if owner isn't current player
    if (owner != currentPlayer) {
      int rent = spaces[centralplayers[currentPlayer] -> getCurrentSpace()] -> retrieveRent();
        //check to see if player can pay rent
      if (centralplayers[currentPlayer]->getMoney() > rent) {
        centralplayers[currentPlayer] -> payMoney(rent);
        centralplayers[owner] -> getMoney(rent);
        mw->updatePlayerGui(currentPlayer);
        mw->updatePlayerGui(owner);
      }
    }
  }

  //check if landed space is community chest
  if (type == 3) {
    communityDeckButton -> setEnabled(true);
    endButton -> setEnabled(false);
  }

  //check if landed space is chance
  if (type == 4) {
    chanceDeckButton -> setEnabled(true);
    endButton -> setEnabled(false);
  }

  //check for income tax
  if (type == 5) {
    hideAll();
    mw -> showtaxQuestion();
  }

  //check for luxury tax
  if (type == 6) {
      //check if player can pay $15,000
    if (centralplayers[currentPlayer] -> getMoney() > 15000) {
      centralplayers[currentPlayer] -> payMoney(15000);
      mw -> updatePlayerGui(currentPlayer);
    }
  }

  //check for gotojail
  if (type == 7) {
    centralplayers[currentPlayer] -> movetoSpace(10);
    centralplayers[currentPlayer] -> setJail(true);
    showPieces(centralplayers);
  }

}


void CentralWidget::enableButtons() {
  diceButton -> setEnabled(true);
  diceButton2 -> setEnabled(true);
  //upgradeButton -> setEnabled(true);
  for (int i = 0; i < numPlayers; i++) {
    p[i] -> show();
  }
}

void CentralWidget::disableButtons() {
  chanceDeckButton -> setEnabled(false);
  communityDeckButton -> setEnabled(false);
  diceButton -> setEnabled(false);
  diceButton2 -> setEnabled(false);
  buyButton -> setEnabled(false);
  upgradeButton -> setEnabled(false);
  endButton -> setEnabled(false);
  for (int i = 0; i<40; i++) {
    upgradeButtons[i] -> hide();
  }
}

void CentralWidget::hideAll() {
  boardLabel -> hide();
  chanceDeckButton -> hide();
  communityDeckButton -> hide();
  diceButton -> hide();
  diceButton2 -> hide();
  buyButton -> hide();
  upgradeButton -> hide();
  endButton -> hide();
  fliptable -> hide();
  for (int i = 0; i<40; i++) {
    spaceTokens[i] -> hide();
  }
  for (int i =0; i<numPlayers; i++) {
    p[i] -> hide();
  }
}

void CentralWidget::showAll() {
  boardLabel -> show();
  chanceDeckButton -> show();
  communityDeckButton -> show();
  diceButton -> show();
  diceButton2 -> show();
  buyButton -> show();
  upgradeButton -> show();
  endButton -> show();
  fliptable -> show();
  for (int i = 0; i<40; i++) {
    if (spaces[i] -> retrieveOwner() != -1) {
      spaceTokens[i] -> show();  
    }
  }
  for (int i =0; i<numPlayers; i++) {
    p[i] -> show();
  }
}

void CentralWidget::setupSpaces() {
  //spaces are dynamically allocated memory
  //setX and setY set the coordinates for the player pieces
  //setupinfo sets up further space information if necessary
  //a counter is used to navigate through the array of spaces
  for (int i = 0; i < 40; i++) {
    spaces[i] = new Space();
  }
  int spacecounter = 0;
  spaces[spacecounter] -> setX(813);
  spaces[spacecounter] -> setY(834);
  spaces[spacecounter] -> setType(8);
  spacecounter++;
  
  for (int i = spacecounter; i < 10; i++) {
    spaces[i] -> setY(834);
  }

  spaces[spacecounter] -> setX(716);
  spaces[spacecounter] -> setupinfo (14720, 1472, 1, 15000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(641);
  spaces[spacecounter] -> setType(3);
  spacecounter++;
  spaces[spacecounter] -> setX(568);
  spaces[spacecounter] -> setupinfo (16945,1695,1,15000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(494);
  spaces[spacecounter] -> setType(5);
  spacecounter++;
  spaces[spacecounter] -> setX(420);
  spaces[spacecounter] -> setupinfo (50000,5000,10,0);
  spaces[spacecounter] -> setType(2);
  spacecounter++;
  spaces[spacecounter] -> setX(346);
  spaces[spacecounter] -> setupinfo (18390,1839,2,15000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(272);
  spaces[spacecounter] -> setType(4);
  spacecounter++;
  spaces[spacecounter] -> setX(198);
  spaces[spacecounter] -> setupinfo (19995,2000,2,15000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(124);
  spaces[spacecounter] -> setupinfo (21955,2196,2,15000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;

  spaces[spacecounter] -> setX(6);
  spaces[spacecounter] -> setY(874);
  spaces[spacecounter] -> setType(9);
  spacecounter++;

  for (int i = spacecounter; i < 20; i++) {
    spaces[i] -> setX(62);
  }

  spaces[spacecounter] -> setY(716);
  spaces[spacecounter] -> setupinfo (22425,2243,3,30000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(642);
  spaces[spacecounter] -> setupinfo (25000,2500,9,0);
  spaces[spacecounter] -> setType(1);
  spacecounter++;
  spaces[spacecounter] -> setY(569);
  spaces[spacecounter] -> setupinfo (26200,2620,3,30000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(494);
  spaces[spacecounter] -> setupinfo (26920,2692,3,30000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(420);
  spaces[spacecounter] -> setupinfo (50000,5000,10,0);
  spaces[spacecounter] -> setType(2);
  spacecounter++;
  spaces[spacecounter] -> setY(347);
  spaces[spacecounter] -> setupinfo (29900,2990,4,30000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(273);
  spaces[spacecounter] -> setType(3);
  spacecounter++;
  spaces[spacecounter] -> setY(199);
  spaces[spacecounter] -> setupinfo (35800,3580,4,30000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(125);
  spaces[spacecounter] -> setupinfo (38200,3820,4,30000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;

  spaces[spacecounter] -> setX(30);
  spaces[spacecounter] -> setY(50);
  spaces[spacecounter] -> setType(9);
  spacecounter++;

  for (int i = spacecounter; i < 30; i++) {
    spaces[i] -> setY(50);
  }

  spaces[spacecounter] -> setX(124);
  spaces[spacecounter] -> setupinfo (39000,3900,5,45000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(198);
  spaces[spacecounter] -> setType(4);
  spacecounter++;
  spaces[spacecounter] -> setX(272);
  spaces[spacecounter] -> setupinfo (43100,4310,5,45000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(345);
  spaces[spacecounter] -> setupinfo (48100,4810,5,45000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(419);
  spaces[spacecounter] -> setupinfo (50000,5000,10,0);
  spaces[spacecounter] -> setType(2);
  spacecounter++;
  spaces[spacecounter] -> setX(493);
  spaces[spacecounter] -> setupinfo (55100,5510,6,45000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(567);
  spaces[spacecounter] -> setupinfo (55100,5510,6,45000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setX(641);
  spaces[spacecounter] -> setupinfo (25000,2500,9,0);
  spaces[spacecounter] -> setType(1);
  spacecounter++;
  spaces[spacecounter] -> setX(715);
  spaces[spacecounter] -> setupinfo (60800,6080,6,45000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;

  spaces[spacecounter] -> setX(810);
  spaces[spacecounter] -> setY(50);
  spaces[spacecounter] -> setType(7);
  spacecounter++;

  for (int i = spacecounter; i<40; i++) {
    spaces[i] -> setX(849);
  }

  spaces[spacecounter] -> setY(124);
  spaces[spacecounter] -> setupinfo (62100,6210,7,60000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(199);
  spaces[spacecounter] -> setupinfo (63800,6390,7,60000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(273);
  spaces[spacecounter] -> setType(3);
  spacecounter++;
  spaces[spacecounter] -> setY(347);
  spaces[spacecounter] -> setupinfo (84300,8430,7,60000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(420);
  spaces[spacecounter] -> setupinfo (50000,5000,10,0);
  spaces[spacecounter] -> setType(2);
  spacecounter++;
  spaces[spacecounter] -> setY(494);
  spaces[spacecounter] -> setType(4);
  spacecounter++;
  spaces[spacecounter] -> setY(568);
  spaces[spacecounter] -> setupinfo (102500,10250,8,60000);
  spaces[spacecounter] -> setType(0);
  spacecounter++;
  spaces[spacecounter] -> setY(642);
  spaces[spacecounter] -> setType(6);
  spacecounter++;
  spaces[spacecounter] -> setY(715);
  spaces[spacecounter] -> setupinfo (126500,12650,8,60000);
  spaces[spacecounter] -> setType(0);

}

void CentralWidget::showPieces(Player* players[]) {
  //shwos movement
  for (int i = 0; i < 4; i++) {
    //retrieve current space
    int spot = players[i] -> getCurrentSpace();
    //retrieve the coordinates necessary to place player pieces
    int x = spaces[spot] -> retrieveX();
    int y = spaces[spot] -> retrieveY();
    //calculate exact location of the spot for each player's piece
    //algorithm differentiates between vertical and horizontal spaces 
      //horizontal just changes x coordinate
    if ((spot < 11) or (spot > 19 and spot < 31)) {
      x += 15*i;  
    }
      //vertical just changes y coordinate
    else if ((spot>10 and spot <20) or (spot>30 and spot<40)) {
      y += 15*i;
    }
    //piece is physically moved
    p[i] -> setGeometry( x, y, 15, 15);
  }
}

void CentralWidget::setnumPlayers(int players) {
  numPlayers = players;
}


void CentralWidget::setToken(int player, QPixmap picture) {
  //store player's chosen piece in array
  p[player] -> setIcon(picture);
  playerIcons[player] = picture;
}

void CentralWidget::setSpaceOwnerToken(int player, int space) {
  //when someone purchases the spot, the button will show 
  //their token
  spaceTokens[space] -> setIcon(playerIcons[player]);
  spaceTokens[space] -> setIconSize( QSize(15, 15) );
  spaceTokens[space] -> show();
}

void CentralWidget::setupSpaceTokens () {
  //set the coordinates for the buttons that will tell players
  //who owns the spot on the board
  for (int i = 0; i<40; i++) {
    spaceTokens[i] = new QPushButton(this);
    spaceTokens[i] -> hide();
    spaceTokens[i] -> setEnabled(false);
  }

  spaceTokens[1] -> setGeometry(713,787, 15, 15);
  spaceTokens[3] -> setGeometry(565,787, 15, 15);
  spaceTokens[5] -> setGeometry(417,787, 15, 15);
  spaceTokens[6] -> setGeometry(343,787, 15, 15);
  spaceTokens[8] -> setGeometry(196,787, 15, 15);
  spaceTokens[9] -> setGeometry(121,787, 15, 15);
  spaceTokens[11] -> setGeometry(97,713, 15, 15);
  spaceTokens[12] -> setGeometry(97,638, 15, 15);
  spaceTokens[13] -> setGeometry(97,566, 15, 15);
  spaceTokens[14] -> setGeometry(97,492, 15, 15);
  spaceTokens[15] -> setGeometry(97,417, 15, 15);
  spaceTokens[16] -> setGeometry(97,344, 15, 15);
  spaceTokens[18] -> setGeometry(97,196, 15, 15);
  spaceTokens[19] -> setGeometry(97,121, 15, 15);
  spaceTokens[21] -> setGeometry(171,98, 15, 15);
  spaceTokens[23] -> setGeometry(320,98, 15, 15);
  spaceTokens[24] -> setGeometry(393,98, 15, 15);
  spaceTokens[25] -> setGeometry(467,98, 15, 15);
  spaceTokens[26] -> setGeometry(541,98, 15, 15);
  spaceTokens[27] -> setGeometry(615,98, 15, 15);
  spaceTokens[28] -> setGeometry(689,98, 15, 15);
  spaceTokens[29] -> setGeometry(763,98, 15, 15);
  spaceTokens[31] -> setGeometry(787,172, 15, 15);
  spaceTokens[32] -> setGeometry(787,246, 15, 15);
  spaceTokens[34] -> setGeometry(787,394, 15, 15);
  spaceTokens[35] -> setGeometry(787,468, 15, 15);
  spaceTokens[37] -> setGeometry(787,616, 15, 15);
  spaceTokens[39] -> setGeometry(787,763, 15, 15);

}

void CentralWidget::updateBuses() {
  int owned[4];
  int counter = 5;
  int ownedcounter1 = 0;
  int ownedcounter2 = 0;
  int group1=5;
  int group2=5;
  for (int i = 0; i < 4; i++) {
    owned[i] = spaces[counter]->retrieveOwner();
    counter += 10;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = i+1; j < 4; j++) {
      if (owned[i] == owned[j]) {
        if (group1 == 5){
          if (owned[i] != -1) {
            group1 = owned[i];  
          }
        }

        else if (owned[i] != group1) {
          if (owned[i] != -1){
            group2 = owned[i];
          }
        }
      }
    }
  }

  for (int i = 0; i < 4; i++){
    if (owned[i] == group1) {
      ownedcounter1++;
    }
    else if (owned[i] == group2) {
      ownedcounter2++;
    }
  }

  for (int i = 5; i<40; i+=10) {
    if (spaces[i]->retrieveOwner() == group1) {
      spaces[i]->updateMonopoly(ownedcounter1-1); 
      
    }

    else if (spaces[i]->retrieveOwner() == group2) {
      spaces[i]->updateMonopoly(ownedcounter2-1);
      
    }
  }
}

void CentralWidget::updateMonopoly() {
  int owner[3];
  int group;
  int counter = 0;
  bool monopoly = true;
  for (int i = 0; i < 40; i++) {
    if (spaces[i]->retrieveType() == 0) {
      if (spaces[i]->checkMonopoly() == false) {
        group = spaces[i]->retrieveGroup();
        for (int j = 0; j < 40; j++) {
          if (spaces[j]->retrieveGroup() == group) {
            owner[counter] = spaces[j]->retrieveOwner();
            counter++;
          }
        }
        for (int k = 0; k < counter-1; k++) {
          if (owner[k] != owner[k+1]) {
              monopoly = false; 
          }

          if (owner[k] == -1) {
            monopoly = false;
          }
        }

        if (monopoly == true) {
          for (int a = 0; a < 40; a++) {
            if (spaces[a]->retrieveGroup() == group) {
              spaces[a]->updateMonopoly(1);
              //cout << "Updated monopoly for space " << a << endl;
            }
          }
        }
      }
    }
    counter = 0;
    monopoly = true;  
  }
}

void CentralWidget::checkUpgrade() {
  for (int i = 0; i < 40; i++) {
    if (spaces[i]->retrieveOwner() == currentPlayer) {
      if (spaces[i]->checkMonopoly() and spaces[i]->retrieveType() == 0) {
        if (spaces[i]->retrieveUpgrade() < 5) {
          upgradeButton -> setEnabled(true);
        }
      }
    }
  }
}

void CentralWidget::createUpgradeButtons() {
  signalMapper = new QSignalMapper(this);
  for (int i = 0; i<40; i++) {
    upgradeButtons[i] = new QPushButton (this);
    upgradeButtons[i] -> setIcon (*upgrade);
    upgradeButtons[i] -> setIconSize ( QSize(15, 15));
    upgradeButtons[i] -> hide();
    
    signalMapper -> setMapping(upgradeButtons[i], i);
    connect(upgradeButtons[i], SIGNAL(clicked()), signalMapper, SLOT(map()) );
    

  }
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(tinyupgrade(int)) );

  upgradeButtons[1] -> setGeometry(738, 763, 15, 15);
  upgradeButtons[3] -> setGeometry(591,763, 15, 15);
  upgradeButtons[6] -> setGeometry(370,763, 15, 15);
  upgradeButtons[8] -> setGeometry(221,763, 15, 15);
  upgradeButtons[9] -> setGeometry(148,763, 15, 15);

  upgradeButtons[11] -> setGeometry(119,738, 15, 15);
  upgradeButtons[13] -> setGeometry(119,590, 15, 15);
  upgradeButtons[14] -> setGeometry(119,518, 15, 15);
  upgradeButtons[16] -> setGeometry(119,369, 15, 15);
  upgradeButtons[18] -> setGeometry(119,221, 15, 15);
  upgradeButtons[19] -> setGeometry(119,148, 15, 15);

  upgradeButtons[21] -> setGeometry(147,119, 15, 15);
  upgradeButtons[23] -> setGeometry(294,119, 15, 15);
  upgradeButtons[24] -> setGeometry(368,119, 15, 15);
  upgradeButtons[26] -> setGeometry(515,119, 15, 15);
  upgradeButtons[27] -> setGeometry(588,119, 15, 15);
  upgradeButtons[29] -> setGeometry(738,119, 15, 15);

  upgradeButtons[31] -> setGeometry(763,148, 15, 15);
  upgradeButtons[32] -> setGeometry(763,221, 15, 15);
  upgradeButtons[34] -> setGeometry(763,370, 15, 15);
  upgradeButtons[37] -> setGeometry(763,588, 15, 15);
  upgradeButtons[39] -> setGeometry(763,738, 15, 15);
}

void CentralWidget::showUpgradeButton(int space) {
  upgradeButtons[space] -> show();
}

void CentralWidget::setupUpgradeStars() {

  for (int i = 0; i<200; i++) {
    upgradeStars[i] = new QLabel(this);
    upgradeStars[i] -> setPixmap (QPixmap("images/star.png"));
    upgradeStars[i] -> hide();

  }
  int counter = 0;
  counter+= 5;
  //spaceTokens[1] -> setGeometry(713,787, 15, 15);
  upgradeStars[counter] -> move(728, 787);
  counter++;
  upgradeStars[counter] -> move(738, 787);
  counter++;
  upgradeStars[counter] -> move(748, 787);
  counter++;
  upgradeStars[counter] -> move(758, 787);
  counter++;
  upgradeStars[counter] -> move(768, 787);
  counter++;

  counter+= 5;
  //spaceTokens[3] -> setGeometry(565,787, 15, 15);
  upgradeStars[counter] -> move(580, 787);
  counter++;
  upgradeStars[counter] -> move(590, 787);
  counter++;
  upgradeStars[counter] -> move(600, 787);
  counter++;
  upgradeStars[counter] -> move(610, 787);
  counter++;
  upgradeStars[counter] -> move(620, 787);
  counter++;
  counter+= 5;
  counter+= 5;
  //spaceTokens[6] -> setGeometry(343,787, 15, 15);
  upgradeStars[counter] -> move(358, 787);
  counter++;
  upgradeStars[counter] -> move(368, 787);
  counter++;
  upgradeStars[counter] -> move(378, 787);
  counter++;
  upgradeStars[counter] -> move(388, 787);
  counter++;
  upgradeStars[counter] -> move(398, 787);
  counter++;
  counter+= 5;
  //spaceTokens[8] -> setGeometry(196,787, 15, 15);
  upgradeStars[counter] -> move(211, 787);
  counter++;
  upgradeStars[counter] -> move(221, 787);
  counter++;
  upgradeStars[counter] -> move(231, 787);
  counter++;
  upgradeStars[counter] -> move(241, 787);
  counter++;
  upgradeStars[counter] -> move(251, 787);
  counter++;
  //spaceTokens[9] -> setGeometry(121,787, 15, 15);
  upgradeStars[counter] -> move(136, 787);
  counter++;
  upgradeStars[counter] -> move(146, 787);
  counter++;
  upgradeStars[counter] -> move(156, 787);
  counter++;
  upgradeStars[counter] -> move(166, 787);
  counter++;
  upgradeStars[counter] -> move(176, 787);
  counter++;
  counter+= 5;
  //spaceTokens[11] -> setGeometry(97,713, 15, 15);
  upgradeStars[counter] -> move(97, 728);
  counter++;
  upgradeStars[counter] -> move(97, 738);
  counter++;
  upgradeStars[counter] -> move(97, 748);
  counter++;
  upgradeStars[counter] -> move(97, 758);
  counter++;
  upgradeStars[counter] -> move(97, 768);
  counter++;
  counter+= 5;
  //spaceTokens[13] -> setGeometry(97,566, 15, 15);
  upgradeStars[counter] -> move(97, 581);
  counter++;
  upgradeStars[counter] -> move(97, 591);
  counter++;
  upgradeStars[counter] -> move(97, 601);
  counter++;
  upgradeStars[counter] -> move(97, 611);
  counter++;
  upgradeStars[counter] -> move(97, 621);
  counter++;
  //spaceTokens[14] -> setGeometry(97,492, 15, 15);
  upgradeStars[counter] -> move(97, 507);
  counter++;
  upgradeStars[counter] -> move(97, 517);
  counter++;
  upgradeStars[counter] -> move(97, 527);
  counter++;
  upgradeStars[counter] -> move(97, 537);
  counter++;
  upgradeStars[counter] -> move(97, 547);
  counter++;
  counter+= 5;
  //spaceTokens[16] -> setGeometry(97,344, 15, 15);
  upgradeStars[counter] -> move(97, 359);
  counter++;
  upgradeStars[counter] -> move(97, 369);
  counter++;
  upgradeStars[counter] -> move(97, 379);
  counter++;
  upgradeStars[counter] -> move(97, 389);
  counter++;
  upgradeStars[counter] -> move(97, 399);
  counter++;
  counter+= 5;
  //spaceTokens[18] -> setGeometry(97,196, 15, 15);
  upgradeStars[counter] -> move(97, 211);
  counter++;
  upgradeStars[counter] -> move(97, 221);
  counter++;
  upgradeStars[counter] -> move(97, 231);
  counter++;
  upgradeStars[counter] -> move(97, 241);
  counter++;
  upgradeStars[counter] -> move(97, 251);
  counter++;
  //spaceTokens[19] -> setGeometry(97,121, 15, 15);
  upgradeStars[counter] -> move(97, 136);
  counter++;
  upgradeStars[counter] -> move(97, 146);
  counter++;
  upgradeStars[counter] -> move(97, 156);
  counter++;
  upgradeStars[counter] -> move(97, 166);
  counter++;
  upgradeStars[counter] -> move(97, 176);
  counter++;
  counter+= 5;
  //spaceTokens[21] -> setGeometry(171,98, 15, 15);
  upgradeStars[counter] -> move(161, 98);
  counter++;
  upgradeStars[counter] -> move(151, 98);
  counter++;
  upgradeStars[counter] -> move(141, 98);
  counter++;
  upgradeStars[counter] -> move(131, 98);
  counter++;
  upgradeStars[counter] -> move(121, 98);
  counter++;
  counter+= 5;
  //spaceTokens[23] -> setGeometry(320,98, 15, 15);
  upgradeStars[counter] -> move(310, 98);
  counter++;
  upgradeStars[counter] -> move(300, 98);
  counter++;
  upgradeStars[counter] -> move(290, 98);
  counter++;
  upgradeStars[counter] -> move(280, 98);
  counter++;
  upgradeStars[counter] -> move(270, 98);
  counter++;
  //spaceTokens[24] -> setGeometry(393,98, 15, 15);
  upgradeStars[counter] -> move(383, 98);
  counter++;
  upgradeStars[counter] -> move(373, 98);
  counter++;
  upgradeStars[counter] -> move(363, 98);
  counter++;
  upgradeStars[counter] -> move(353, 98);
  counter++;
  upgradeStars[counter] -> move(343, 98);
  counter++;
  counter+= 5;
  //spaceTokens[26] -> setGeometry(541,98, 15, 15);
  upgradeStars[counter] -> move(531, 98);
  counter++;
  upgradeStars[counter] -> move(521, 98);
  counter++;
  upgradeStars[counter] -> move(511, 98);
  counter++;
  upgradeStars[counter] -> move(501, 98);
  counter++;
  upgradeStars[counter] -> move(491, 98);
  counter++;
  //spaceTokens[27] -> setGeometry(615,98, 15, 15);
  upgradeStars[counter] -> move(605, 98);
  counter++;
  upgradeStars[counter] -> move(595, 98);
  counter++;
  upgradeStars[counter] -> move(585, 98);
  counter++;
  upgradeStars[counter] -> move(575, 98);
  counter++;
  upgradeStars[counter] -> move(565, 98);
  counter++;
  counter+= 5;
  //spaceTokens[29] -> setGeometry(763,98, 15, 15);
  upgradeStars[counter] -> move(753, 98);
  counter++;
  upgradeStars[counter] -> move(743, 98);
  counter++;
  upgradeStars[counter] -> move(733, 98);
  counter++;
  upgradeStars[counter] -> move(723, 98);
  counter++;
  upgradeStars[counter] -> move(713, 98);
  counter++;
  counter+= 5;
  //spaceTokens[31] -> setGeometry(787,172, 15, 15);
  upgradeStars[counter] -> move(787, 162);
  counter++;
  upgradeStars[counter] -> move(787, 152);
  counter++;
  upgradeStars[counter] -> move(787, 142);
  counter++;
  upgradeStars[counter] -> move(787, 132);
  counter++;
  upgradeStars[counter] -> move(787, 122);
  counter++;
  //spaceTokens[32] -> setGeometry(787,246, 15, 15);
  upgradeStars[counter] -> move(787, 236);
  counter++;
  upgradeStars[counter] -> move(787, 226);
  counter++;
  upgradeStars[counter] -> move(787, 216);
  counter++;
  upgradeStars[counter] -> move(787, 206);
  counter++;
  upgradeStars[counter] -> move(787, 196);
  counter++;
  counter+= 5;
  //spaceTokens[34] -> setGeometry(787,394, 15, 15);
  upgradeStars[counter] -> move(787, 384);
  counter++;
  upgradeStars[counter] -> move(787, 374);
  counter++;
  upgradeStars[counter] -> move(787, 364);
  counter++;
  upgradeStars[counter] -> move(787, 354);
  counter++;
  upgradeStars[counter] -> move(787, 344);
  counter++;
  counter+= 5;
  counter+= 5;
  //spaceTokens[37] -> setGeometry(787,616, 15, 15);
  upgradeStars[counter] -> move(787, 606);
  counter++;
  upgradeStars[counter] -> move(787, 596);
  counter++;
  upgradeStars[counter] -> move(787, 586);
  counter++;
  upgradeStars[counter] -> move(787, 576);
  counter++;
  upgradeStars[counter] -> move(787, 566);
  counter++;
  counter+= 5;
  //spaceTokens[39] -> setGeometry(787,763, 15, 15);
  upgradeStars[counter] -> move(787, 753);
  counter++;
  upgradeStars[counter] -> move(787, 743);
  counter++;
  upgradeStars[counter] -> move(787, 733);
  counter++;
  upgradeStars[counter] -> move(787, 723);
  counter++;
  upgradeStars[counter] -> move(787, 713);
  counter++;
}

void CentralWidget::setupCards() {
  for (int i = 0; i<16; i++) {
    communitycards[i] = new QPushButton(this);
    chancecards[i] = new QPushButton(this);
    communitycards[i] -> setIconSize(QSize(500,295));
    chancecards[i] -> setIconSize(QSize(500,295));
    communitycards[i] -> setGeometry (200, 303, 500, 295);
    chancecards[i] -> setGeometry (200, 303, 500, 295);
    communitycards[i] -> hide();
    chancecards[i] -> hide();
  }


  int cardcounter = 0;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/advancego.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/advancebus.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/bankerror.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/advancecamry.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/beauty.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/advancego.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/birthday.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/advancemaserati.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/carshow.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/advancemhbus.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/consultancy.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/advancetaxi.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/doctor.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/audis4.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/hospital.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/back.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/inheritance.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/carloan.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/jail.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/chairman.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/jailfree.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/dividend.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/lifeinsurance.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/jail.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/repairs.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/jailfree.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/schoolfees.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/poortax.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/stocks.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/repairs.jpg"));
  cardcounter++;
  communitycards[cardcounter] -> setIcon(QPixmap("images/cards/community/taxrefund.jpg"));
  chancecards[cardcounter] -> setIcon(QPixmap("images/cards/chance/advancebus.jpg"));
  
  cardcounter = 0;
  signalMapper -> setMapping(communitycards[cardcounter], 0);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(advancetoSpace(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 15000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 2000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 0);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 10000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 5000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 10000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(LoseMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 20000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(LoseMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 20000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 0);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(gotoJail(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 0);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 20000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 1000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 10000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(LoseMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 10000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(communitycards[cardcounter], 4000);
  connect(communitycards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );

  cardcounter = 0;
  signalMapper -> setMapping(chancecards[cardcounter], 0);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 11);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(advancetoSpace(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 0);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(advancetoSpace(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 39);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(advancetoSpace(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 5);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(advancetoSpace(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 0);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 24);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(advancetoSpace(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], -3);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(moveSpaces(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 20000);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 10000);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 10000);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(GainMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 0);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(gotoJail(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 0);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 3000);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(LoseMoney(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 0);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );
  cardcounter++;
  signalMapper -> setMapping(chancecards[cardcounter], 0);
  connect(chancecards[cardcounter], SIGNAL(clicked()), signalMapper, SLOT(map()) );
  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(duud(int)) );

}

void CentralWidget::hideAllCards() {
  for (int i = 0; i< 16; i++) {
    communitycards[i] -> hide();
    chancecards[i] -> hide();
  }
}

//CARD ACTIONS!!!!!
void CentralWidget::advancetoSpace(int space) {
  hideAllCards();
  centralplayers[currentPlayer] -> movetoSpace(space);
  if (space == 0) {
    centralplayers[currentPlayer] -> getMoney(40000);
  }
  showPieces(centralplayers);
  GameFunction();
}

void CentralWidget::moveSpaces(int spaces) {
  hideAllCards();
  centralplayers[currentPlayer] -> setCurrentSpace(spaces);
  showPieces(centralplayers);
  GameFunction();
}

void CentralWidget::GainMoney(int money) {
  hideAllCards();
  centralplayers[currentPlayer] -> getMoney(money);
  mw->updatePlayerGui(currentPlayer);
}

void CentralWidget::LoseMoney(int money) {
  hideAllCards();
  centralplayers[currentPlayer] -> payMoney(money);
  mw->updatePlayerGui(currentPlayer);
}

void CentralWidget::gotoJail(int a) {
  hideAllCards();
  centralplayers[currentPlayer] -> movetoSpace(10);
  centralplayers[currentPlayer] -> setJail(true);
  showPieces(centralplayers);
}

void CentralWidget::duud(int a){
  hideAllCards();
}

void CentralWidget::flip() {
  hideAll();
  end -> show();
}

