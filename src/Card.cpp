class Card {
    public:
    int value,suit; //0 - Diamonds, 1 clubs, 2 hearts, 3 spades

    Card() {
        value = 0;
        suit = 0;
    }
    Card(int v, int s) {
        value = v;
        suit = s;
    }
};

