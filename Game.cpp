#include <iostream>
#include <ctime>
#include <stdio.h>
#include <conio.h>
using namespace std;
class point
{
private:
    int X, Y;
public:
    // defualt constructor
    point()
    {
        X = 0;
        Y = 0;
    }
    // setter function
    point(int a, int b)
    {
        X = a;
        Y = b;
    }
    // getter functions
    int getX(void)
    {
        return X;
    }
    int getY(void)
    {
        return Y;
    }
};
class champion
{
private:
    point location;
    int health = 100;
    int score = 0;
public:
    champion()
    {
        cout << "Constructor champion() is called" << endl;
    }
    champion(point location, int health, int score)
    {
        this->location = location;
        this->health = health;
        this->score = score;
    }
    void print_champ_info()
    {
        cout << "Location: X:" << location.getX()<<" ";
        cout << "Y:" << location.getY()<<" ";
        cout << "Champion's Health: " << health << ", ";
        cout << "Champion's Score: " << score << endl;
    }
    point getLocation()
    {
        return location;
    }
    void setLocation(point location)
    {
        this->location = location;
    }
    int getScore()
    {
        return score;
    }
    int getHealth()
    {
        return health;
    }
    void setHealth(int health)
    {
        this->health = health;
    }
     void setScore(int score)
    {
        this->score = score;
    }
};

class map
{
private:
    char **array;
    int gems;
    int obstacles;
    champion champ;
    int gemsCounter;
public:
    map()
    {
    int x;
    int y;
    gemsCounter = 0;
    array = new char *[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = new char[10];
    }
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            array[x][y] = '.';
        }
    }
    cout << "Constructor map() is called" << endl;
    }
    void print_map()
    {
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                cout << array[x][y] << ' ';
            }
            cout << endl;
        }
    cout << "print_map() called" << endl;
    }
    int Gems;
    void randomize_map()
    {
    int x;
    int y;
        for (x = 0; x < 10; x++)
        {
            for (y = 0; y < 10; y++)
            {
                array[x][y] = '.';
            }
        }
        int obstacleCounter = 0;
        srand(time(0));
        Gems = (rand() % 10) + 40;
        obstacles = (rand() % 10) + 20;
        cout << Gems << endl;
        cout << obstacles << endl;
        for (x = 0; x < 10; x++)
        {
            for (y = 0; y < 10; y++)
            {
                if (Gems >= 40)
                {
                    int randX = rand() % 10;
                    int randY = rand() % 10;
                    // cout << randX;
                    if (array[randX][randY] == '.')
                    {
                        array[randX][randY] = 'X';
                        gemsCounter++;
                    }
                }
            }
        }
        for (x = 0; x < 10; x++)
        {
            for (y = 0; y < 10; y++)
            {
                if (obstacles > 20)
                {
                    int randX = rand() % 10;
                    int randY = rand() % 10;
                    if (array[randX][randY] == '.' && array[randX][randY] != 'X')
                    {
                        array[randX][randY] = 'O';
                        obstacleCounter++;
                    }
                }
            }
        }
    cout << "randomize_map() called" << endl;
    }
    void update_champ(){
      cout<< "Health:"  <<champ.getHealth()<< " ";
       cout<< "Score:"  <<  champ.getScore()<< "/" << Gems<< " ";
       cout<< "Location X:"  <<  champ.getLocation().getX()<< " ";
        cout<< "Y:"  << champ.getLocation().getY()<< endl;
    }
    void place_champion()
    {
        point Loc = point(9, 0);
        champ.setLocation(Loc);
        array[9][0] = 'C';
    }
    char input = ' ';
    void move()
    {
    int x;
    int y;
    int oldX = champ.getLocation().getX();
    int oldY = champ.getLocation().getY();
    int newX;
    int newY;
    input = _getch();
    cout<< input;
    if (input == '8')
    {
        newX = oldX - 1;
        newY = oldY;
        if(array[newX][newY] == 'X'){
            int s = champ.getScore() +1;
            champ.setScore(s);
                array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
                    point location = point(newX, newY);
        champ.setLocation(location);
        }
        else if(array[newX][newY] == '.'){
                array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
                    point location = point(newX, newY);
        champ.setLocation(location);
        }
        else if(array[newX][newY] == 'O'){
            int health = champ.getHealth() - 40;
        champ.setHealth(health);
            array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
            point location = point(newX, newY);
        champ.setLocation(location);
        }
        point location = point(newX, newY);
        champ.setLocation(location);
    }
    else if (input == '5')
    {
        newX = oldX + 1;
        newY = oldY;
        if(array[newX][newY] == 'X'){
            int s = champ.getScore() +1;
            champ.setScore(s);
                array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
                    point location = point(newX, newY);
        champ.setLocation(location);
        }
        else if(array[newX][newY] == '.'){
                array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
                    point location = point(newX, newY);
        champ.setLocation(location);
        }
        else if(array[newX][newY] == 'O'){
            int health = champ.getHealth() - 40;
        champ.setHealth(health);
            array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
            point location = point(newX, newY);
        champ.setLocation(location);
        }
        point location = point(newX, newY);
        champ.setLocation(location);
    }
    else if (input == '6')
    {
        newX = oldX;
        newY = oldY + 1;
        if(array[newX][newY] == 'X'){
            int s = champ.getScore() +1;
            champ.setScore(s);
                array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
                    point location = point(newX, newY);
        champ.setLocation(location);
        }
        else if(array[newX][newY] == '.'){
                array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
                    point location = point(newX, newY);
        champ.setLocation(location);
        }
        else if(array[newX][newY] == 'O'){
            int health = champ.getHealth() - 40;
        champ.setHealth(health);
            array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
            point location = point(newX, newY);
        champ.setLocation(location);
        }
        point location = point(newX, newY);
        champ.setLocation(location);
    }
    else if (input == '4')
    {
        newX = oldX;
        newY = oldY - 1;
        if(array[newX][newY] == 'X'){
            int s = champ.getScore() +1;
            champ.setScore(s);
                array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
                    point location = point(newX, newY);
        champ.setLocation(location);
        }
        else if(array[newX][newY] == '.'){
                array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
                    point location = point(newX, newY);
        champ.setLocation(location);
        }
        else if(array[newX][newY] == 'O'){
            int health = champ.getHealth() - 40;
        champ.setHealth(health);
            array[newX][newY] = 'C';
        array[oldX][oldY] = '.';
            point location = point(newX, newY);
        champ.setLocation(location);
        }
        point location = point(newX, newY);
        champ.setLocation(location);
    }
}
void check_GameOver(){
    if(champ.getHealth() <1 || gemsCounter==Gems){
        system("cls");
        cout<<"Game Over!"<<endl;
    }
}
};

int main()
{
map m1;
champion c1;
c1.print_champ_info();
char num = ' ';
m1.randomize_map();
m1.place_champion();
m1.print_map();
do
{
    cout << "enter 2 to randomize, 1 to start the game" << endl;
    num = _getch();
    cout<<"Starting.... " <<num<<endl;
    if(num =='2')  {
            system(" cls ");
        m1.randomize_map();
        m1.place_champion();
        m1.print_map();
    }
} while (num == '2');

if(num =='1'){
        cout << "move up = 8, down = 5, right = 6, left = 4" << endl;
do
{
    m1.move();
    system(" cls ");
    m1.update_champ();
    m1.print_map();
    m1.check_GameOver();

} while (true);
}
return 0;
}

