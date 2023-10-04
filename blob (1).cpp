#include "blob.h"
#include <iostream>
#include <string>
using namespace std; 

    Blob::Blob() { 
    health= 100;  
    power=10; 
    xCoord=0; 
    yCoord=0; 
    status= 'A';
    }

    Blob::Blob(int x, int y) {
        xCoord=x; 
        yCoord=y;
        status='A';
        health=100; 
        power=10; 
    }

    Blob::Blob(int x, int y, int _health, int _power) {
        xCoord=x;
        yCoord=y;
        status= 'A'; 
        health=_health; 
        power=_power; 
    }

    Blob::Blob(int x, int y, int _health, int _power, char _color) {
        xCoord=x;
        yCoord=y;
        status= 'A'; 
        health=_health; 
        power=_power; 
        color = _color;
    }

    char Blob::getStatus(){
        return status;
    }

    void Blob::setStatus(char s){
        status = s;
    }
    int Blob::getXCoord() {
        return xCoord; 
    }
    void Blob::setXCoord(int x) {
        xCoord=x;
    } 

    int Blob::getYCoord() {
        return yCoord; 
    }
    void Blob::setYCoord(int y) {
       yCoord=y; 
   }

    char Blob::getColor() {
        return color; 
    }

    int Blob::getHealth() {
        return health; 
    }

    int Blob::getPower() {
        return power; 
    }

    Blob operator+(Blob& other, Blob& target1) { //blobs merge
        int maxPower=target1.power; 
        if (other.power>maxPower) {
            maxPower=other.power; 
            target1.status= 'X'; 
        } //set other to X
        return Blob (other.getXCoord(), other.getYCoord(), target1.health + other.health, maxPower +2); 

    }

    void Blob::attack(Blob& target) { 
        
        if (target.getXCoord()== (xCoord+1) && target.getYCoord()==(yCoord)
        || target.getYCoord()==(yCoord+1) && target.getXCoord()==(xCoord)
        || target.getXCoord()==(xCoord-1) && target.getYCoord()==(yCoord)
        || target.getYCoord()==(yCoord-1) && target.getXCoord()==(xCoord))
        
         {
            target.health -= power; 
            if(target.health <= 0) {
                status= 'X';
                cout<<"target's is now dead"<<endl;
            }
        }
        else {
            cout<< " You can not attack there"; 
        }
    }

    bool Blob::move(char d, Blob array1[]) {
        if (d !='n'&&d !='N'
        && d!= 'e' && d!= 'E'
        && d!= 's' && d!= 'S'
        && d!= 'w' && d!= 'W') {
            return false; 
        }

        if(d=='n' || d=='N')
            {
                if (yCoord==9){
                    return false; 
                }
                for(int i=0; i<8; i++)
                {
                    if (array1[i].xCoord== xCoord && array1[i].yCoord==yCoord+1 && 
                     array1[i].color != color)
                    return false;    

                }
                yCoord++;
                return true;
            }
        else if(d=='e' || d=='E')
            {
                if(xCoord==9)
                    return false; 
                for(int i=0; i<8; i++)
                {
                    if(array1[i].xCoord== xCoord+1 && array1[i].yCoord==yCoord 
                     && array1[i].color != color)
                    return false; 
                }
            xCoord++;
            return true; 
            }

        else if(d=='s' || d=='S')
        {
            if (yCoord==0)
                return false; 
            for(int i=0; i<8; i++) {
                if (array1[i].yCoord==yCoord-1 && array1[i].xCoord==xCoord 
                 && array1[i].color != color)
                return false; 
            }
            yCoord--;
            return true; 
         }
        
        else if(d=='w' || d=='W')
        {
            if (xCoord==0)
                return false; 
            for(int i=0; i<8;i++) {
                if (array1[i].xCoord==xCoord-1 && array1[i].yCoord==yCoord 
                 && array1[i].color != color)
                    return false; 
            }
            xCoord--; 
            return true; 
        }
        else 
            return false; 
    }
    
    void Blob::randomValues()
    {
        xCoord =rand() %10; 
        yCoord =rand() %10; 
    }

    ostream& operator<<(ostream& s, Blob b){
       s << "(" << b.xCoord <<"," << b.yCoord << ")" <<endl; 
       s<< "Health: "<<b.health <<endl; 
       s<< "Power: "<<b.power <<endl;  
       return s;
    }
   

