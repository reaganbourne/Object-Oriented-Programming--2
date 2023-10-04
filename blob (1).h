using namespace std;
#include <iostream>

class Blob {

    friend std::ostream& operator<<(std::ostream&, Blob);
    private: 
    int health; 
    int power;
    char color; 
    int xCoord; 
    int yCoord; 
    char status; 

    public: 
    Blob(); 
    Blob(int,int); 
    Blob(int, int, int, int, char); 
    Blob(int, int, int, int); 
    friend Blob operator+(Blob&, Blob&); 
    bool move(char, Blob []);
    void attack(Blob&); 
    int getXCoord(); 
    int getYCoord(); 
    void setXCoord(int x); 
    void setYCoord(int y); 
    void setColor(char);
    char getColor();  
    int getHealth(); 
    int getPower(); 
    void randomValues(); 
    char getStatus();
    void setStatus(char);
}; 

