#include <iostream>
#include <vector>
#include "Card.cpp"
int main()
{
    std::cout << "Hello World" << std::endl;
    Card newCard = Card(1,1);
    std::cout << newCard.value << std::endl;
}

float Rank(std::vector<Card> *hand, const Card& trump)
{
    //find out if you have any jacks

    std::vector<Card> jacks;
    for(Card c : hand) 
        std::cout << c.value << std::endl;


    //Your implementation here

    //divide value by 32 to have a number between 0 and 1, the highest trump should be 32, don't think this is right actually..
}