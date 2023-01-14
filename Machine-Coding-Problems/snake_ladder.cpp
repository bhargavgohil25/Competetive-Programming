#include<bits/stdc++.h>
using namespace std;

class Player {
    string name;
    int position;

public:
    Player() {}
    Player(string name)
    {
        srand(time(0));
        this->name = name;
        this->position = 0;
    }
    string getName()
    {
        return name;
    }
    int getPosition()
    {
        return position;
    }
    void setPosition(int new_position)
    {
        position = new_position;
    }
    int rollDice(int no_of_dice)
    {
        return no_of_dice + (rand() % (no_of_dice * 6 - no_of_dice + 1));
    }
};


class Snake {
    int head;
    int tail;

public:
    Snake() {}
    Snake(int head, int tail)
    {
        this->head = head;
        this->tail = tail;
    }
    int getHead()
    {
        return head;
    }
    int getTail()
    {
        return tail;
    }
};

class Ladder {
    int start;
    int end;

public:
    Ladder() {}
    Ladder(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
    int getStart()
    {
        return start;
    }
    int getEnd()
    {
        return end;
    }
};


class Board {
    int boardSize;
    vector<int> board;
    vector<Snake> snakes;
    vector<Ladder> ladders;
public:
    Board() {}
    Board(int boardSize)
    {
        this->boardSize = boardSize;
        board.resize(boardSize + 1, 0);
    }
    int getBoardSize()
    {
        return boardSize;
    }
    vector<Snake> getSnakes()
    {
        return snakes;
    }
    vector<Ladder> getLadders()
    {
        return ladders;
    }

    // set snakes and ladders on the board
    void setSnakes(vector<Snake> s)
    {
        snakes = s;
    }
    void setLadders(vector<Ladder> l)
    {
        ladders = l;
    }

    void arrangeBoard()
    {
        // set snakes position on the board
        for (Snake s : snakes) {
            board[s.getHead()] = s.getTail();
        }

        // set ladders position on the board
        for (Ladder l : ladders) {
            board[l.getStart()] = l.getEnd();
        }
    }
    int getJumpValue(int position)
    {
        return board[position];
    }

    // display board
    void displayBoard()
    {
        for (int i = 0; i <= boardSize; i++) {
            cout << board[i] << " ";
        }
        cout << "\n";
    }
};



int main()
{
    int boardSize; // dynamic board size
    int num_snakes; // number of snakes
    int num_ladder; // number of ladders
    int num_player; // number of players
    int head; // head position of snake and ladder
    int tail; // tail position of snake and ladder
    int no_of_dice;
    string name;
    vector<Snake> snakes;
    vector<Ladder> ladders;
    queue<Player> players;

    cout << "Enter Board Size\n"; // Optional Req 2
    cin >> boardSize;

    int i = 1;
    cout << "Enter no of snakes\n";
    cin >> num_snakes;

    // get input of number of snakes and its position
    while (i <= num_snakes)
    {
        cout << "Enter head and tail for snake " << i << ": ";
        cin >> head >> tail;
        cout << head << " " << tail << endl;
        Snake snake(head, tail);
        snakes.push_back(snake);
        i++;
    }

    // get input of number of snakes and its position
    i = 1;
    cout << "Enter no of ladders\n";
    cin >> num_ladder;
    int start;
    int end;
    while (i <= num_ladder)
    {
        cout << "Enter head and tail for ladder " << i << ": ";
        cin >> start >> end;
        cout << start << " " << end << endl;
        Ladder ladder(start, end);
        ladders.push_back(ladder);
        i++;
    }

    // get input of number of players and its position
    i = 1;
    cout << "Enter no of players(at least 2):\n";
    cin >> num_player;
    while (i <= num_player)
    {
        cout << "Enter name of player " << i << ": ";
        cin >> name;
        cout << name << ' ' << endl;
        Player player(name);
        players.push(player);
        i++;
    }

    // get the input of number of dice required in game
    cout << "Enter no of dice: ";   //Optional Req 1
    cin >> no_of_dice;
    cout << no_of_dice << endl;

    Board b(boardSize);
    b.setSnakes(snakes);
    b.setLadders(ladders);
    b.arrangeBoard();


    while (players.size() > 1) //Optional Req 3
    {
        // Game begins
        Player p = players.front();
        players.pop();

        // roll dice
        int diceValue = p.rollDice(no_of_dice);
        cout << "Dice Value: " << diceValue << endl;
        int initialPosition = p.getPosition();
        int finalPosition = initialPosition + diceValue;

        // if final position gets out of bound, keep as it is
        if (finalPosition > b.getBoardSize()) {
            finalPosition = initialPosition;
        }
        else {
            // this is for the snake and laader possition and
            // getting step down or step up
            while (b.getJumpValue(finalPosition) != 0)
            {
                finalPosition = b.getJumpValue(finalPosition);
            }
        }
        p.setPosition(finalPosition);

        cout << p.getName() << " rolled a " << diceValue << " and moved from " << initialPosition << " to " << finalPosition << "\n";
        if (finalPosition == b.getBoardSize())
        {
            cout << p.getName() << " has won!!\n\n";
            continue;
        }
        players.push(p);
    }
    return 0;
}



/*
Input:
100
9
62 5
33 6
49 9
88 16
41 20
56 53
98 64
93 73
95 75
8
2 37
27 46
10 32
51 68
61 79
65 84
71 91
81 100
2
Gaurav
Sagar
1
*/