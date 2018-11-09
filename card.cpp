//
// Created by Ryed Ahmed on 11/6/2018.
//

#include "card.h"
#include <string>

Card::Card(){
    myRank = 1;
    mySuit = spades;
};

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{

    string rank;
    string suit;
    string retString;

    if(mySuit == 0){suit = "s";}
    else if(mySuit == 1){suit = "h";}
    else if(mySuit == 2){suit = "d";}
    else {suit = "c";}

    //convert rank into character of card
    if(myRank == 1){rank = 'A';}
    else if(myRank == 2){rank = '2';}
    else if(myRank == 3){rank = '3';}
    else if(myRank == 4){rank = '4';}
    else if(myRank == 5){rank = '5';}
    else if(myRank == 6){rank = '6';}
    else if(myRank == 7){rank = '7';}
    else if(myRank == 8){rank = '8';}
    else if(myRank == 9){rank = '9';}
    else if(myRank == 10){ rank = "10"; }
    else if(myRank == 11){rank = "J";}
    else if(myRank == 12){rank = "Q";}
    else if(myRank == 13){rank = "K";}

    retString = rank + suit;
    return retString;
}

bool Card::sameSuitAs(const Card& c) const{
    int c1 = mySuit;
    int c2 = c.mySuit;

    if(c1 == c2)
        return true;
    else
        return false;
}

int  Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s)const{
    string suit;

    if(s == 0){suit = "s";}
    else if (s == 1){suit = "h";}
    else if (s == 2){suit = "d";}
    else { suit = "c";}

    return suit;
}

string Card::rankString(int r) const {

    string rank;

    if(r == 1){rank = 'A';}
    else if(r == 2){rank = '2';}
    else if(r == 3){rank = '3';}
    else if(r == 4){rank = '4';}
    else if(r == 5){rank = '5';}
    else if(r == 6){rank = '6';}
    else if(r == 7){rank = '7';}
    else if(r == 8){rank = '8';}
    else if(r == 9){rank = '9';}
    else if(r == 10){ rank = "10"; }
    else if(r == 11){rank = "J";}
    else if(r == 12){rank = "Q";}
    else if(r == 13){rank = "K";}

    return rank;
}

bool Card::operator == (const Card& rhs) const{
    if(myRank == rhs.myRank && mySuit == rhs.mySuit){return true;}
    else{return false;}
}

bool Card::operator != (const Card& rhs) const{
    if(myRank == rhs.myRank && mySuit == rhs.mySuit){return false;}
    else{return true;}
}