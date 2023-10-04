#include <iostream>
#include "blob.h"
#include <cstdlib> 
#include <ctime>
using namespace std; 

int main() {
    int moveThisBlob; 
    int randomX, randomY;
    bool gameOver=false; 
    int playerCount=0; 
    int chosenBlob, targetBlob; 
    int turnValid=1; 
    int i; 
    char d;
    int killCount=0;

    
    srand(time(NULL)); 
    Blob chars[8]; 
    for (int i=0; i<8; i++) {
        int match=0;
        do {
            int x=rand() %10;
            int y=rand() %10;

            for (int j=0; j<i; j++) {
                if(x==chars[j].getXCoord() && y==chars[j].getYCoord()) 
                {
                    match=1;
                    break;
                }
            }
            if (match==0) {
                chars[i]= Blob (x,y); 
            }
        }
        while(match==1); 
    }
    cout<<"Welcome to the blob game!"<<endl; 
 
    while (gameOver == false) {
        cout<<"The positions of the players are: "<<endl; 
    
        cout<< "Pink Team:"<<endl; 
        for(int i=0; i<4; i++) {
            if(chars[i].getStatus() == 'A')
                cout<< "Blob " << i << ": " << chars[i] <<endl;
        }
        
        cout<< "Blue Team:"<<endl; 
        for(int i=4; i<8; i++) {
            if(chars[i].getStatus() == 'A')
                cout<< "Blob " << i << ": " << chars[i]<< endl; 
        }

        cout<< "it is player " <<playerCount<< "'s turn"<<endl;
        cout<< "which blob would you like to play?"<<endl; 
        cin>> chosenBlob; 

        if((playerCount==0 && chosenBlob<4 && chosenBlob>=0) || (playerCount==1 && chosenBlob >=4 && chosenBlob <8))
        {
            cout << "Player selected blob " << chosenBlob <<endl; 
        }
        else 
        {
            cout<< "Invalid blob selection! Try again!" <<endl; 
            turnValid=0; 
        }
        int choice;
        cout<< "You can either \n1. move or \n2. attack!"<<endl; 
        cin>>choice; 

        if (choice == 1)
        {
            cout<< "Would you like to move N E S or W"<<endl; 
            cin>>d;
            while(chars[chosenBlob].move(d, chars) == false){
                cout<<"Invalid Choice. Choose again: "<<endl;
                cin>>d;
            }
            for (int i=0; i<8; i++)
            {
                if (chars[chosenBlob].getXCoord()==chars[i].getXCoord() && chars[chosenBlob].getYCoord()==chars[i].getYCoord() &&
                chars[chosenBlob].getColor()==chars[i].getColor() && chosenBlob!=i)
                {
                    chars[chosenBlob]= chars[i]+ chars[chosenBlob]; 
                    chars[i].setXCoord(100);
                    chars[i].setStatus('X');
                }

            }
        }
                    

        else if(choice == 2)
        {
            if((playerCount==0 && chosenBlob<4 && chosenBlob>=0) || (playerCount==1 && chosenBlob >=4 && chosenBlob <8))
            {
                cout << "Player selected blob " << chosenBlob <<endl; 
                cout<< "What blob would you like to attack?"<<endl; 
                cin>>targetBlob; 
                chars[chosenBlob].attack(chars[targetBlob]);
            }
            else 
            {
                cout<< "Invalid blob selection! Try again!" <<endl; 
                turnValid=0; 
            }
             
        
            while(chars[chosenBlob].move(d, chars) == false){

                    cout<<"Invalid Choice. Choose again: "<<endl;
                    cin>>d; 
            }
        }
        
        if ((chars[0].getStatus()=='X' && chars[1].getStatus()=='X' && chars[2].getStatus()=='X' && chars[3].getStatus()=='X' ))
            cout<< "Blue team won"<<endl; 
            gameOver=false; 

        if ((chars[4].getStatus()=='X' && chars[5].getStatus()=='X' && chars[6].getStatus()=='X' && chars[7].getStatus()=='X' ))
            cout<< "Pink team won"<<endl; 
            gameOver=false; 

        if((chars[0].getStatus() == 'X' && chars[1].getStatus() == 'X' && chars[2].getStatus() == 'X' && chars[3].getStatus() == 'X') || (chars[4].getStatus() == 'X' && chars[5].getStatus() == 'X' && chars[6].getStatus() == 'X' && chars[7].getStatus() == 'X') )
            gameOver = false;

        if (turnValid == 1) {
            playerCount =(playerCount+1) %2; 
            cout<<"PlayerCount: "<<playerCount<<endl;
        }
    }
}


