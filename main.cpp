// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS

#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);



int main( )
{
	srand(time(NULL));
    int numCards = 5;
    int turn = 1;
    
    Card temp;
    
    Card book1;
    Card book2;
    
    Player p1("Gustavo");
    Player p2("Emilia");
    
    
    Deck d;  //create a deck of cards
    //d.printDeck();
    
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    
    cout << p1.getName() <<" has : \n" << endl;
    p1.showHand();
    cout << p2.getName() <<" has : \n" << endl;
    p2.showHand();
    
    //Check for initial books
    while(p1.checkHandForBook(book1, book2) == true){
    	p1.removeCardFromHand(book1);
    	p1.removeCardFromHand(book2);
    	p1.bookCards(book1, book2);
    	cout << p1.getName() << " books " << book1.toString() << " and " << book2.toString() << ".\n";
    }
    while(p2.checkHandForBook(book1, book2) == true){
    	p2.removeCardFromHand(book1);
    	p2.removeCardFromHand(book2);
    	p2.bookCards(book1, book2);
    	cout << p2.getName() << " books " << book1.toString() << " and " << book2.toString() << ".\n";
    }
    
    //Game loop
    while(d.size() > 0 || p1.getHandSize() > 0 || p2.getHandSize() > 0){
    	if(turn == 1){
    		if(p1.getHandSize() > 0){
    			temp = p1.chooseCardFromHand();
    			cout << p1.getName() << " asks - Do you have a " << temp.rankString(temp.getRank()) << "?\n";
    		}
    		if(p1.getHandSize() == 0){
    			temp = d.dealCard();
    			p1.addCard(temp);
    			cout << p1.getName() << " draws " << temp.toString() << ".\n";
    			
    			if(p1.checkHandForBook(book1, book2) == true){
    				p1.removeCardFromHand(book1);
    				p1.removeCardFromHand(book2);
    				p1.bookCards(book1, book2);
    				cout << p1.getName() << " books " << book1.toString() << " and " << book2.toString() << ".\n";
				}
    		}
    		else if(p2.sameRankInHand(temp) == true){
    			cout << p2.getName() << " says - Yes, I have a " << temp.rankString(temp.getRank()) << ".\n";
    			temp = p2.rankRemove(temp);
    			p2.removeCardFromHand(temp);
    			p1.addCard(temp);
    			if(p1.checkHandForBook(book1, book2) == true){
    				p1.removeCardFromHand(book1);
    				p1.removeCardFromHand(book2);
    				p1.bookCards(book1, book2);
    				cout << p1.getName() << " books " << book1.toString() << " and " << book2.toString() << ".\n";
    			}
    			
    			
    		}
    		else if(p2.cardInHand(temp) == false){
    			cout << p2.getName() << " says - Go Fish.\n";
    			temp = d.dealCard();
    			p1.addCard(temp);
    			cout << p1.getName() << " draws " << temp.toString() << ".\n";
    			
    			if(p1.checkHandForBook(book1, book2) == true){
    				p1.removeCardFromHand(book1);
    				p1.removeCardFromHand(book2);
    				p1.bookCards(book1, book2);
    				cout << p1.getName() << " books " << book1.toString() << " and " << book2.toString() << ".\n";
				}
    		}
    		turn = 2;
    	}
    	
    	else if(turn == 2){
    		if(p2.getHandSize() > 0){
    			temp = p2.chooseCardFromHand();
    			cout << p2.getName() << " asks - Do you have a " << temp.rankString(temp.getRank()) << "?\n";
    		}
    		if(p2.getHandSize() == 0){
    			temp = d.dealCard();
    			p2.addCard(temp);
    			cout << p2.getName() << " draws " << temp.toString() << ".\n";
    			
    			if(p2.checkHandForBook(book1, book2) == true){
    				p2.removeCardFromHand(book1);
    				p2.removeCardFromHand(book2);
    				p2.bookCards(book1, book2);
    				cout << p2.getName() << " books " << book1.toString() << " and " << book2.toString() << ".\n";
				}
    		}
    		if(p1.sameRankInHand(temp) == true){
    			cout << p1.getName() << " says - Yes, I have a " << temp.rankString(temp.getRank()) << ".\n";
    			temp = p1.rankRemove(temp);
    			p1.removeCardFromHand(temp);
    			p2.addCard(temp);
    			if(p2.checkHandForBook(book1, book2) == true){
    				p2.removeCardFromHand(book1);
    				p2.removeCardFromHand(book2);
    				p2.bookCards(book1, book2);
    				cout << p2.getName() << " books " << book1.toString() << " and " << book2.toString() << ".\n";
    			}
    			
    			
    		}
    		else if(p1.cardInHand(temp) == false){
    			cout << p1.getName() << " says - Go Fish.\n";
    			temp = d.dealCard();
    			p2.addCard(temp);
    			cout << p2.getName() << " draws " << temp.toString() << ".\n";
    			
    			if(p2.checkHandForBook(book1, book2) == true){
    				p2.removeCardFromHand(book1);
    				p2.removeCardFromHand(book2);
    				p2.bookCards(book1, book2);
    				cout << p2.getName() << " books " << book1.toString() << " and " << book2.toString() << ".\n";
				}
    		}
    		turn = 1;
    	}
    	/*
    	cout << p1.getName() <<" has : \n" << endl;
		p1.showHand();
		cout << p2.getName() <<" has : \n" << endl;
		p2.showHand();
		cout << "Cards in deck: " << d.size() << ".\n";
		*/
    }
    
    cout << "Book 1: " << p1.getBookSize() << ".\n";
    cout << "Book 2: " << p2.getBookSize() << ".\n";
    
    if(p1.getBookSize() > p2.getBookSize()){
    	cout << p1.getName() << " wins!";
    }
    else if(p2.getBookSize() > p1.getBookSize()){
    	cout << p2.getName() << " wins!";
    }
    else if(p1.getBookSize() == p2.getBookSize()){
    	cout << "It's a draw!";
    }
    
   /* 
    if(p2.checkHandForBook(meme1, meme2) == true){
    	cout << "Player 2 has " << meme1.toString() << " and " << meme2.toString() << endl;
    	p2.bookCards(meme1, meme2);
    	p2.removeCardFromHand(meme1);
    	p2.removeCardFromHand(meme2);
    }
    cout << "Player 2 hand: \n";
    p2.showHand();
    cout << "Book: \n";
    p2.showBooks();
   */ 
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
 



