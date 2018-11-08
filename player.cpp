//
// Created by Ryed Ahmed on 11/6/2018.
//

#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "card.h"
#include "deck.h"

Player::Player(){
}


void Player::addCard(Card c){
	myHand.push_back(c);
}
//Pushes both cards
void Player::bookCards(Card c1, Card c2){
	myBook.push_back(c1);
	myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2){
	int size = myHand.size();
	bool pair = false;
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j++){
			if(myHand[i].getRank() == myHand[j].getRank() && i != j && pair == false){
				pair = true;
				c1 = myHand[i];
				c2 = myHand[j];
			}
		}
	}
	return pair;
}

bool Player::cardInHand(Card c) const{
	int size = myHand.size();
	for(int i = 0; i < size; i++){
		if(myHand[i].sameSuitAs(c) == true && myHand[i].getRank() == c.getRank()){
			return true;
		}
	}
	return false;
}

Card Player::removeCardFromHand(Card c){
	int size = myHand.size();
	int eraser = 0;
	for(int i = 0; i < size; i++){
		if(myHand[i].sameSuitAs(c) == true && myHand[i].getRank() == c.getRank()){
			eraser = i;
		}
	}
	
	myHand.erase(myHand.begin() + eraser);
	return c;
}


string Player::showHand() const{
	int size = myHand.size();
	for(int i = 0; i < size; i++){
		cout << myHand[i].toString() << "\n";
	}
}

string Player::showBooks() const{
	int size = myBook.size();
	for(int i = 0; i < size; i++){
		cout << myBook[i].toString() << "\n";
	}
}

int Player::getHandSize() const{
	return myHand.size();
}
int Player::getBookSize() const{
	return myBook.size();
}

bool Player::sameRankInHand(Card c) const{
	int size = myHand.size();
	for(int i = 0; i < size; i++){
		if(myHand[i].getRank() == c.getRank()){
			return true;
		}
	}
	return false;
}



