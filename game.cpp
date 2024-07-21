#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void ProgramGreeting();
void Introduction(string playerName);
void combatMenu(char combat);
void gameExit(char key, string playerName);
void characterMenu(char chooseChar);


void roomOne_key(char key, string playerName, int room_id, string move, char combat, int stars);
void roomTwo_key(char key, string playerName, int room_id, string move, char combat, int stars);
void roomThree_key(char key, string playerName, int room_id, string move, char combat, int stars);
void roomFour_key(char key, string playerName, int room_id, string move, char combat, int stars);
void roomFive_key(char key, string playerName, int room_id, string move, char combat, int stars);
void roomSix_key(char key, string playerName, int room_id, string move, char combat, int stars);

void chooseRoom(int room_id, char combat, string playerName, string move, char key, int stars);
void backtoDungeon(int room_id, string move, char key, char combat, string playerName, int stars);
void combatOrRetreat(string move, char combat, int room_id, string playerName, char key, int stars);
int gameOver(int stars);


class MonsterOne{
  public:
   void spawnOne() {
     cout << endl;
      cout << "Oh no! A Yellow Waddle Dee spotted you! They are running towards you with an arrow!\n";
     }
    };

class MonsterTwo{
  public:
   void spawnTwo() {
      cout << endl;
      cout << "Oh no! A Green Waddle Dee spotted you! They are running towards you with a hammer!\n";
     }
    };

class MonsterThree{
  public:
   void spawnThree() {
     cout << endl;
      cout << "Oh no! A Blue Waddle Dee spotted you! They are running towards you with a spear!\n";
     }
    };

class MonsterFour{
  public:
   void spawnFour() {
     cout << endl;
      cout << "Oh no! A Pink Waddle Dee spotted you! They are running towards you with a sword!\n";}
    };
// Specification B1 - Another Monster 
// There is a fifth monster making it a total of five monsters in the game. 
class MonsterFive{
  public:
   void spawnFive() {
     cout << endl;
      cout << "Oh no! A Purple Waddle Dee guard spotted you! They are running towards you with a spear!\n";}
    };

// Specification C1 - Five Rooms
class roomOne{
public:
void fruityForest(){
  cout << "Fruity Forest\n";
}
void roomOne_desc(){
  cout << "There is a colorful forest with trees and a huge variety of fruits...Yummy!\n";
}
void roomOne_id(){
  int roomOne_id = 1;
}
void roomOne_occupied(){
  bool roomOne_occupied = false;
  }
};

class roomTwo{
public:
// Specification C4 – Abbreviated Room Descriptions
void blizzardBridge(){
  cout << "Blizzard Bridge\n";
}
void roomTwo_desc(){
  cout << "Brrrr....its cold here! The atmosphere is really foggy but you manage to see that there is a long bridge ahead covered in snow with snowflakes falling from above.\n";
}
void roomTwo_id(){
  int roomOne_id = 2;
}
void roomTwo_occupied(){
  bool roomTwo_occupied = false;
}
};

class roomThree{
public:
void flowerWoods(){
  cout << "Flower Woods\n";
}
void roomThree_desc(){
  cout << "It is bright with the Sun shining on a grassy hill with a garden of multicolored flowers.\n";
}
void roomThree_id(){
  int roomThree_id = 3;
}
void roomThree_occupied(){
  bool roomThree_occupied = false;
}
};

class roomFour{
public:
void honeyHill(){
  cout << "Honey Hill\n";
}
void roomFour_desc(){
  cout << "There is a grassy hill full of greenery situated near a waterfall and lake of honey and lots of (harmless!) honey bees nearby.\n";
}
void roomFour_id(){
  int roomFour_id = 4;
}
void roomFour_occupied(){
  bool roomFour_occupied = false;
}
};

class roomFive{
public:
void cookieRoad(){
  cout << "Cookie Road.\n";
}
void roomFive_desc(){
  cout << "The ground is made up of delicious cookies of flavors of all types and a rainbow ahead with several green trees surrounding the road.\n";
}
void roomFive_id(){
  int roomFive_id = 5;
}
void roomFive_occupied(){
  bool roomFive_occupied = false;
}
};
// Specification B1 - Another Room
// I added a sixth room called Star Valley making it 6 rooms in total.
class roomSix{
public:
void starValley(){
  cout << "Star Valley.\n";
}
void roomSix_desc(){
  cout << "It is nighttime here, the stars and the Full Moon are shining on a grassy hill and there are floating rocks above the hill.\n";
}
void roomSix_id(){
  int roomSix_id = 6;
}
void roomSix_occupied(){
  bool roomSix_occupied = false;
}
};

int main() {

// Variable Declarations
string playerName;
char key;
char chooseChar;
string move;
char combat;
int room_id;
int stars = 0;

  
ProgramGreeting();
  
Introduction(playerName);
  
characterMenu(chooseChar);
combatMenu(combat);

chooseRoom(room_id, combat, playerName,  move, key, stars);

  }
// Function Definitions
 void ProgramGreeting(){
// Source File Header
  cout << "Shreya Sareen\n";
  cout << "TextAdventure.cpp, CISP 360\n";
  cout << "December 15, 2022\n";
  cout << endl;
  cout << "Welcome! This program is a text adventure game." << endl;
  cout << endl;
}
void Introduction(string playerName){
  cout << "✧･ﾟ: *✧･ﾟ:* WELCOME TO DREAM LAND ✧･ﾟ: *✧･ﾟ:*" << endl;
cout << endl;
  cout << "SITUATION : You were captured and trapped in a dungeon in Castle Dedede located in Dream Land. The castle is home to King Dedede and the Waddle Dee guards. You must escape the castle by collecting 4 stars by going through rooms and making it past the Waddle Dee guards. If you choose to combat the Waddle Dee guards, you will earn a star.\n";
  cout << endl;
cout << "You will be navigating the rooms in Castle Dedede by entering the following keys : " << endl;
cout << "┈➤ E : East\n";
cout << "┈➤ W : West\n";
cout << "┈➤ N : North\n";
cout << "┈➤ S : South\n";
cout << "┈➤ L : look around\n";
cout << "┈➤ X : Exit Game\n";
cout << endl;

// Specification C2 - Player Name
cout << "Please enter your name : ";
cin >> playerName; 
cout << endl;
cout << "Welcome " << playerName << "!" << endl;
  cout << endl;
  }
// Specification B2 - Choose a Character
// The player gets to choose a character they would like to play as in the game, there are 4 characters in total.
void characterMenu(char chooseChar){
  cout << "☆ P : Pink Kirby\n";
  cout << "☆ B : Blue Kirby\n";
  cout << "☆ U : Purple Kirby\n";
  cout << "☆ G : Green Kirby \n";
  cout << endl;
  cout << "Choose your character : ";
  cin >> chooseChar;
  
// input validation
  chooseChar = toupper(chooseChar);
  while (!(chooseChar == 'P' || chooseChar == 'B' || chooseChar == 'U' || chooseChar == 'G')){
    cout << "Please enter a valid character : ";
    cin >> chooseChar;
  }
}
// Specification B3 - Combat Menu
// This menu shows the client the various combat moves and their coressponding commands which are char data types, there are 4 combat moves in the game.
void combatMenu(char combat){
  cout << endl;
  cout << "If you wish to combat the monster to earn a star, then choose a combat move from the menu by entering the corresponding commands :\n";
  cout << endl;
  cout << "COMBAT MOVE     COMMAND\n";
  cout << "-----------     -------\n";
  cout << "Smash Punch     press 'a'\n";
  cout << "Meteor Smash    press 'b'\n";
  cout << "Hammer Hit      press 'c'\n";
  cout << "Fireball        press 'd'\n";
  cout << endl;
    }

void roomOne_key(char key, string playerName, int room_id, string move, char combat, int stars){
  cout << endl;
  cout << "Which way will you go? : ";
  cin >> key;
  cout << endl;
  // Specification C3 - Input Validation
  while(!(key == 'E' || key == 'W' || key == 'N' || key == 'S'|| key == 'X' || key == 'L')){
   cout << "Please enter a valid command : ";
   cin >> key;
   cout << endl;}
    
    switch(key){
    case 'E':
    cout << "There is raccoon sitting on a lychee tree indulging pink lychees.\n";
    break;
    case 'W':
     cout << "Woah! There's a humongous mango tree and lots of monkeys!\n";
      break;
    case 'N':
     cout << "There are some duckies swimming in a large pond.\n";
      break;
    case 'S':
    MonsterOne monster1;
    monster1.spawnOne();
    combatOrRetreat(  move,  combat,  room_id,  playerName, key, stars);
      break;
      
// Specification C5 - Detailed Look
      case 'L':
      cout << endl;
      cout << "You are in ";
      roomOne room1;
      room1.fruityForest();
      room1.roomOne_desc();
      break;
      case 'X':
      gameExit(key, playerName);
      break;
   }
  }

void roomTwo_key(char key, string playerName, int room_id, string move, char combat, int stars){
  cout << endl;
  cout << "Which way will you go? : ";
  cin >> key;
  cout << endl;

   while(!(key == 'E' || key == 'W' || key == 'N' || key == 'S'|| key == 'X' || key == 'L')){
   cout << "Please enter a valid command : ";
   cin >> key;
   cout << endl;}

    switch(key){
    case 'E':
     MonsterTwo monster2;
     monster2.spawnTwo();
    combatOrRetreat(  move,  combat,  room_id,  playerName, key, stars);
    break;
    case 'W':
     cout << "There is a green tree covered in white snow.\n";
      break;
    case 'N':
     cout << "There's some multi-sized snowballs.\n"; 
      break;
    case 'S':
     cout << "There is a fluffy snow rabbit hopping around in the snow.\n";
      break;
      case 'L':
      cout << "You are in ";
      roomTwo room2;
      room2.blizzardBridge();
      room2.roomTwo_desc();
      break;
      case 'X':
      gameExit(key, playerName);
      break;}
    }
void roomThree_key(char key, string playerName, int room_id, string move, char combat, int stars){
  cout << endl;
  cout << "Which way will you go? : ";
  cin >> key;
  cout << endl;

   while(!(key == 'E' || key == 'W' || key == 'N' || key == 'S'|| key == 'X' || key == 'L')){
   cout << "Please enter a valid command : ";
   cin >> key;
   cout << endl;}

    switch(key){
    case 'E':
cout << "There is a garden of pink flowers and some chipmunks running around.\n";
    break;
    case 'W':
     cout << "There is a small and clear blue pond with orange fishes.\n";
      break;
    case 'N':
     MonsterThree monster3;
     monster3.spawnThree();
    combatOrRetreat(  move,  combat,  room_id,  playerName, key, stars);
      break;
    case 'S':
     cout << "There is a large tree with lychees and some birds chirping.\n";
      break;
      case 'L':
      cout << "You are in ";
      roomThree room3;
      room3.flowerWoods();
      room3.roomThree_desc();
      break;
      case 'X':
      gameExit(key, playerName);
      break;}
    }
void roomFour_key(char key, string playerName, int room_id, string move, char combat, int stars){
  cout << endl;
  cout << "Which way will you go? : ";
  cin >> key;
  cout << endl;

   while(!(key == 'E' || key == 'W' || key == 'N' || key == 'S'|| key == 'X' || key == 'L')){
   cout << "Please enter a valid command : ";
   cin >> key;
    cout << endl;}
  
    switch(key){
    case 'E':
     cout << "There is a bird chirping on a tree.\n";
    break;
    case 'W':
      MonsterFour monster4;
     monster4.spawnFour();
    combatOrRetreat(  move,  combat,  room_id,  playerName, key, stars);
      break;
    case 'N':
     cout << "There is a tree with lychees." << endl;
      break;
    case 'S':
      cout << "There is a pond with fishes.\n";
      break;
      case 'L':
      cout << "You are in ";
      roomFour room4;
      room4.honeyHill();
      room4.roomFour_desc();
      break;
      case 'X':
      gameExit(key, playerName);
      break;}
    }
void roomFive_key(char key, string playerName, int room_id, string move, char combat, int stars){
  cout << endl;
  cout << "Which way will you go? : ";
  cin >> key;
  cout << endl;

   while(!(key == 'E' || key == 'W' || key == 'N' || key == 'S'|| key == 'X' || key == 'L')){
   cout << "Please enter a valid command : ";
   cin >> key;
     cout << endl;}
  
    switch(key){
    case 'E':
     cout << "There's a chocolate fountain made from melted chocolate chips.\n";
    break;
    case 'W':
     cout << "There's a giant cinnamon roll to your West...you're currently standing on a Snickerdoodle cookie.\n";
      break;
    case 'N':
     MonsterFive monster5;
     monster5.spawnFive();
     combatOrRetreat(  move,  combat,  room_id,  playerName, key, stars);
      break;
    case 'S':
      cout << "There are some birds pecking on fortune cookies.\n";
      break;
      case 'L':
      cout << "You are in ";
      roomFive room5;
      room5.cookieRoad();
      room5.roomFive_desc();
      break;
      case 'X':
      gameExit(key, playerName);
      break;
      }
    }
void roomSix_key(char key, string playerName, int room_id, string move, char combat, int stars){
  cout << endl;
  cout << "Which way will you go? : ";
  cin >> key;
  cout << endl;

   while(!(key == 'E' || key == 'W' || key == 'N' || key == 'S'|| key == 'X' || key == 'L')){
   cout << "Please enter a valid command : ";
   cin >> key;
    cout << endl;}
  
    switch(key){
    case 'E':
     cout << "You see glowing fireflies.\n";
    break;
    case 'W':
     cout << "There are pink mushrooms with white spots nearby on the grass.\n";
      break;
    case 'N':
     cout << "You see a few floating yellow stars, glowing in the night sky." << endl;
      break;
    case 'S':
     MonsterFour monster4;
     monster4.spawnFour();
     combatOrRetreat(move, combat, room_id, playerName, key, stars);
      break;
      case 'L':
      cout << "You are in ";
      roomSix room6;
      room6.starValley();
      room6.roomSix_desc();
      break;
      case 'X':
      gameExit(key, playerName);
      break;}
    }
// Specification A3 - Choose A Room
// The player gets to input which room they would like to enter, there are 6 rooms in total. The client is asked to enter an integer data type from 1 through 6.
void chooseRoom(int room_id, char combat, string playerName, string move, char key, int stars){

  do{
  cout << endl;
  cout << "Which room would you like to enter (1-6)? : ";
  cin >> room_id;
  cout << endl;

    // input validation
    while (room_id < 1 || room_id > 6){
    cout << "Please enter a valid room option : ";
    cin >> room_id;
      }
    
  switch(room_id){
  case 1:
  roomOne room1;
  room1.fruityForest();
  room1.roomOne_desc();
  roomOne_key(key, playerName, room_id, move, combat, stars);
  backtoDungeon(room_id, move, key, combat, playerName, stars);
  break;
  case 2:
  roomTwo room2;
  room2.blizzardBridge();
  room2.roomTwo_desc();
  roomTwo_key(key, playerName, room_id, move, combat, stars);
  backtoDungeon(room_id, move, key, combat, playerName, stars);
  break;
  case 3:
  roomThree room3;
  room3.flowerWoods();
  room3.roomThree_desc();
  roomThree_key(key, playerName, room_id, move, combat, stars);
  backtoDungeon(room_id, move, key, combat, playerName, stars);
  break;
  case 4:
  roomFour room4;
  room4.honeyHill();
  room4.roomFour_desc();
  roomFour_key(key, playerName, room_id, move, combat, stars);
  backtoDungeon(room_id, move, key, combat, playerName, stars);
  break;
  case 5:
  roomFive room5;
  room5.cookieRoad();
  room5.roomFive_desc();
  roomFive_key(key, playerName, room_id, move, combat, stars);
  backtoDungeon(room_id, move, key, combat, playerName, stars);
  break;
  case 6:
  roomSix room6;
  room6.starValley();
  room6.roomSix_desc();
  roomSix_key(key, playerName, room_id, move, combat, stars);
  backtoDungeon(room_id, move, key, combat, playerName, stars);
  break;

    }
    }while (key != 'X');
    }
  
void backtoDungeon(int room_id, string move, char key, char combat, string playerName, int stars){
  cout << endl;
  cout << "Going back to the dungeon...\n";
  cout << endl;
  chooseRoom(room_id, combat, playerName, move, key, stars);
}
// Specification A2 - Combat
// The player gets to choose whether they wish to combat the monster or retreat and exit the room. There are 4 different combat methods.
void combatOrRetreat(string move, char combat, int room_id, string playerName, char key, int stars){
  cout << endl;
  cout << "Will you choose to combat or retreat? : ";
  cin >> move;
  while (!(move == "combat" || move == "Combat" || move == "retreat" || move == "Retreat")){
    cout << "Please enter a valid option : ";
    cin >> move;
  }
    if(move == "retreat"){
       backtoDungeon(room_id, move, key, combat, playerName, stars);
     } 
  
    else if(move == "combat"){
       cout << "Choose a combat command : ";
       cin >> combat;
       } 
  // input validation
     combat = tolower(combat);
     while (!(combat == 'a' || combat == 'b' || combat == 'c' || combat == 'd')){
       cout << "Please enter a valid combat move : ";
       cin >> combat;
     }
  
    switch(combat){
    case 'a':
    cout << endl;
    cout << "You smash punch the Waddle Dee guard successfully defeating them! Congratulations! You earned a star on the way!\n";
    stars++;
    break;
    case 'b':
    cout << endl;
    cout << "You use a meteor smash to defeat the Waddle Dee guard! Congratulations, you successfully combatted them! You earned a star on the way!\n";
    stars++;
    break;
    case 'c':
    cout << endl;
    cout << "You use a hammer hit to fight the Waddle Dee guard. The Waddle Dee guard disappears into thin air. Congratulations, you won the battle and earned a star!\n";
    stars++;
    case 'd':
    cout << endl;
    cout << "You spit mutliple fireballs towards the Waddle Dee guard! Before the guard comes in close proximity to you, they disappear into thin air. Congratulations, you successfully defeated the guard on your way, oh, and you earned a star as well!\n";
    stars++;
    break;
      } 
       }
int gameOver(int stars){
  
stars = gameOver(stars);
if (stars == 4 ){	
  cout << endl;
  cout << "Game Over...\n";
  cout << "Congratulations! You successfully escaped Castle Dedede!\n";
		}
  }
void gameExit(char key, string playerName){
  if (key == 'X'){
    cout << endl;
  cout << "Game Over. Thank you for playing, see you again " << playerName << "!" << endl;
    return 0;
    }
  }