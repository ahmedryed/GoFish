// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;
    
    Card meme1;
    Card meme2;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    //d.printDeck();
    cout << d.size() << "\n";
    
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    
    cout << p1.getName() <<" has : \n" << p1.showHand() << endl;
    cout << p2.getName() <<" has : \n" << p2.showHand() << endl;
    
    if(p2.checkHandForBook(meme1, meme2) == true){
    	cout << "Player 2 has " << meme1.toString() << " and " << meme2.toString() << endl;
    	p2.bookCards(meme1, meme2);
    	p2.removeCardFromHand(meme1);
    	p2.removeCardFromHand(meme2);
    	cout << "Player 2 hand: \n" << p2.showHand() << "\n";
    	cout << "Book: \n" << p2.showBooks() << "\n";
    }
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
 



