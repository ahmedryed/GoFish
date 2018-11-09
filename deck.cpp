//
// Created by Ryed Ahmed on 11/6/2018.
//

#include "deck.h"
#include "card.h"
#include <ctime>
#include <cstdlib>



Deck::Deck(){
    int count = 0;


    for(int i = 1; i <= 13; i++){
        myCards[count] = Card(i, Card::spades);
        count++;
    }
    for(int i = 1; i <= 13; i++){
        myCards[count] = Card(i, Card::hearts);
        count++;
    }
    for(int i = 1; i <= 13; i++){
        myCards[count] = Card(i, Card::diamonds);
        count++;
    }
    for(int i = 1; i <= 13; i++){
        myCards[count] = Card(i, Card::clubs);
        count++;
    }
}

void Deck::shuffle(){
   // srand(time(NULL));

    int targ1;
    int targ2;
    Card temp;

    for(int i = 0; i < size() * 2; i++)
    {
        targ1 = rand() % size();
        targ2 = rand() % size();
        temp = myCards[targ1];
        myCards[targ1] = myCards[targ2];
        myCards[targ2] = temp;
    }
}

Card Deck::dealCard(){
    Card ret = myCards[size() - 1];
    myCards[size() - 1] = Card(0, Card::spades);
    return ret;
}

int Deck::size() const {
    int check = 1;
    int count = 0;
    while(check != 0){
        check = myCards[count].getRank();
        count++;
    }
    count--;
    if(count > 52){
        count = 52;
    }
    return count;
}

void Deck::printDeck() {
    for(int i = 0; i < size(); i++){
        cout << myCards[i].toString() << "\n";
    }
}
