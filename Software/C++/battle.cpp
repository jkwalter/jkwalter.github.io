/*
Compiling and Running in UNIX:

 - Open a terminal
 - Navigate to the same directory as battle.cpp
      cd ~/Programs/jkwalter.github.io/Software/C++
 - Type the following to complie battle.cpp
      g++ battle.cpp
 - Type the following to run battle.cpp
      ./a.out
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class character
{
 private:
   int health;
   int attack;
   int heal;
 public:
   character(void);
   void setAttack(int d1, int d2);
   int getAttack(void);
   void damageValue(int damage);
   int getHealth(void);
   void healValue(int d1, int d2);
   int getHeal(void);
};

class opponent
{
 private:
   int health;
   int attack;
   int heal;
 public:
   opponent(void);
   void setAttack(int d1, int d2);
   int getAttack(void);
   void damageValue(int damage);
   int getHealth(void);
   void healValue(int d1, int d2);
   int getHeal(void);
};

character::character(void)
{
 health = 50;
}
void character::setAttack(int d1, int d2)
{
 if (d1 + d2 == 2 || d1 + d2 == 12)
  {
   attack = 20;
  }
 if (d1 + d2 == 3 || d1 + d2 == 11)
  {
   attack = 14;
  }
 if (d1 + d2 == 4 || d1 + d2 == 10)
  {
   attack = 10;
  }
 if (d1 + d2 == 5 || d1 + d2 == 9)
  {
   attack = 6;
  }
 if (d1 + d2 == 6 || d1 + d2 == 8)
  {
   attack = 6;
  }
 if (d1 + d2 == 7)
  {
   attack = 10;
  }
}
int character::getAttack(void)
{
 return attack;
}
void character::damageValue(int damage)
{
 if (health - damage < 0)
  {
   health = 0;
  }
 else
  {
   health = health - damage;
  }
}
int character::getHealth(void)
{
 return health;
}
void character::healValue(int d1, int d2)
{
 if (d1 + d2 == 2 || d1 + d2 == 12)
  {
   heal = 20;
  }
 if (d1 + d2 == 3 || d1 + d2 == 11)
  {
   heal = 14;
  }
 if (d1 + d2 == 4 || d1 + d2 == 10)
  {
   heal = 10;
  }
 if (d1 + d2 == 5 || d1 + d2 == 9)
  {
   heal = 6;
  }
 if (d1 + d2 == 6 || d1 + d2 == 8)
  {
   heal = 6;
  }
 if (d1 + d2 == 7)
  {
   heal = 10;
  }

 if (health + heal > 50)
  {
   health = 50;
  }
 else
  {
   health = health + heal;
  }
}
int character::getHeal(void)
{
 return heal;
}

opponent::opponent(void)
{
 health = 50;
}
void opponent::setAttack(int d1, int d2)
{
 if (d1 + d2 == 2 || d1 + d2 == 12)
  {
   attack = 20;
  }
 if (d1 + d2 == 3 || d1 + d2 == 11)
  {
   attack = 14;
  }
 if (d1 + d2 == 4 || d1 + d2 == 10)
  {
   attack = 10;
  }
 if (d1 + d2 == 5 || d1 + d2 == 9)
  {
   attack = 6;
  }
 if (d1 + d2 == 6 || d1 + d2 == 8)
  {
   attack = 6;
  }
 if (d1 + d2 == 7)
  {
   attack = 10;
  }
}
int opponent::getAttack(void)
{
 return attack;
}
void opponent::damageValue(int damage)
{
 if (health - damage < 0)
  {
   health = 0;
  }
 else
  {
   health = health - damage;
  }
}
int opponent::getHealth(void)
{
 return health;
}
void opponent::healValue(int d1, int d2)
{
 if (d1 + d2 == 2 || d1 + d2 == 12)
  {
   heal = 20;
  }
 if (d1 + d2 == 3 || d1 + d2 == 11)
  {
   heal = 14;
  }
 if (d1 + d2 == 4 || d1 + d2 == 10)
  {
   heal = 10;
  }
 if (d1 + d2 == 5 || d1 + d2 == 9)
  {
   heal = 6;
  }
 if (d1 + d2 == 6 || d1 + d2 == 8)
  {
   heal = 6;
  }
 if (d1 + d2 == 7)
  {
   heal = 10;
  }

 if (health + heal > 50)
  {
   health = 50;
  }
 else
  {
   health = health + heal;
  }
}
int opponent::getHeal(void)
{
 return heal;
}

int main(void)
{
 character hero;
 opponent villain;
 int option;
 char key;
 int d1;
 int d2;

 srand(time(NULL));

 do
  {
   system("clear");
   cout << "          YOUR HEALTH: " << hero.getHealth() << endl;
   cout << "   OPPONTENT'S HEALTH: " << villain.getHealth() << endl;
   do
    {
     cout << endl;
     cout << "1: Attack" << endl;
     cout << "2: Heal" << endl;
     cout << endl;
     cout << "Enter an option here (1-2): ";
     cin >> option;
    } while (option != 1 && option != 2);
   system("clear");
   switch (option)
    {
     case 1:
            d1 = rand() % 6 + 1;
            d2 = rand() % 6 + 1;
            hero.setAttack(d1, d2);
            villain.damageValue(hero.getAttack());
            cout << "Opponent takes " << hero.getAttack() << " damage." << endl;
            break;
     case 2:
            d1 = rand() % 6 + 1;
            d2 = rand() % 6 + 1;
            hero.healValue(d1, d2);
            cout << "You restored "<< hero.getHeal() << " health." << endl;
            break;
    }
   cout << endl;
   cout << "Enter any key to continue: ";
   cin >> key;
   if (villain.getHealth() != 0)
    {
     system("clear");
     if (villain.getHealth() < 25)
      {
       option = rand() % 10 + 1;
       if (option > 4)
        {
         option = 2;
        }
       else
        {
         option = 1;
        }
      }
     else
      {
       option = rand() % 10 + 1;
       if (option > 3)
        {
         option = 1;
        }
       else
        {
         option = 2;
        }
      }
     switch (option)
      {
       case 1:
              d1 = rand() % 6 + 1;
              d2 = rand() % 6 + 1;
              villain.setAttack(d1, d2);
              hero.damageValue(villain.getAttack());
              cout << "You take " << villain.getAttack() << " damage." << endl;
              break;
       case 2:
              d1 = rand() % 6 + 1;
              d2 = rand() % 6 + 1;
              villain.healValue(d1, d2);
              cout << "Opponent restored " << villain.getHeal() << " health." <<endl;
              break;
      }
     cout << endl;
     cout << "Enter any key to continue: ";
     cin >> key;
    }
   option = 0;
  } while (hero.getHealth() != 0 && villain.getHealth() != 0);

 system("clear");

 if (hero.getHealth() != 0)
  {
   cout << "VICTORY!" << endl;
  }
 else
  {
   cout << "DEFEAT!" << endl;
  }

 cout << endl;
 cout << "          YOUR HEALTH: " << hero.getHealth() << endl;
 cout << "   OPPONTENT'S HEALTH: " << villain.getHealth() << endl;

 return 0;
}
