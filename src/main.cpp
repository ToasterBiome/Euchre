#include <iostream>
#include <vector>
#include "Card.cpp"


float Rank(std::vector<Card> *hand, const Card& trump)
{
    //find out if you have any jacks

    int bestvalue = 0;

    std::vector<Card> jacks;
    for(size_t i = 0; i < hand->size(); ++i){ 
        //std::cout << hand->at(i).value << std::endl;

        int currentValue = hand->at(i).value; 
        int currentSuit = hand->at(i).suit;

        if(currentValue == 11) { // got a jack
            if(currentSuit == trump.suit) {
                bestvalue = 15;
            } else if ((currentSuit % 2) == (trump.suit % 2)) { //if it is the opposite suit
                if(bestvalue < 13) {
                    bestvalue = 13;
                }
            } 
        } else {
            if(bestvalue < 4) { //other jack, worth only 4
                bestvalue = 4;
            }
        }
        if(currentSuit != trump.suit) {
            if(currentValue > 11) {
                if(bestvalue < (currentValue - 6)) {
                    bestvalue = currentValue - 6;
                }
            } else {
                if(bestvalue < (currentValue - 5)) {
                bestvalue = currentValue - 5;
                }
            }
            
        } else {
            if(bestvalue < currentValue) {
                bestvalue = currentValue;
            }   
        }
     }

     //clamp it 
     return ((float)bestvalue / 15.0);

}

int main()
{
    std::cout << "Hello World" << std::endl;
    Card newCard = Card(1,1);
    std::cout << newCard.value << std::endl;

    //make a hand
    std::vector<Card> mainHand;

    mainHand.push_back(Card(11,0)); //jack of diamonds
    mainHand.push_back(Card(14,1)); //ace of clubs
    mainHand.push_back(Card(10,0)); //10 of diamonds
    mainHand.push_back(Card(11,3)); //jack of spades
    mainHand.push_back(Card(12,2)); //queen of hearts

    Card trump = Card(9,0); //9 of diamonds

    float chance = Rank(&mainHand,trump);

    std::cout << "Your chances of winning with this hand are: " << chance << "." << std::endl;
}