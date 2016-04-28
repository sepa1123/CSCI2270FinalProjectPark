// Seungjeong Park
// CSCI 2270 Hoegniman
// Final Project

#include <iostream>
#include "ItemTree.h"
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    ItemTree Item;

    ifstream infile;
    infile.open(argv[1]);
    string line;
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            int commaPos1 = line.find(',');
            string item = line.substr(0, commaPos1);

            int price = stoi(line.substr(commaPos1+1));

            Item.addItemNode(item, price);
        }

        infile.close();
    }

    int input;
    while (input != 9)
    {
        cout << "-----MENU-----" << endl
			 << "1. Add an item" << endl
			 << "2. Delete an item" << endl
			 << "3. Search an item" << endl
			 << "4. Show # of Un-sold items in list" << endl
			 << "5. Display unsold items (In-order)" << endl
			 << "6. Display unsold items (Pre-order)" << endl
			 << "7. Display unsold items (Post-order)" << endl
			 << "8. Display list of sold items" << endl
			 << "9. Quit" << endl;
        cin >> input;
        cin.ignore(10000,'\n');

        if (input == 1)
        {
            string item;
            cout << "What item are you trying to sell:" << endl;
            getline(cin, item);

            int price;
            cout << "For what price are you expecting?:" << endl;
            cin >> price;

            Item.addItemNode(item, price);
        }

        else if (input == 2)
        {
            string itemDelete;
            cout << "What's item that is sold already?:" << endl;
            getline(cin, itemDelete);

            Item.deleteItemNode(itemDelete);
        }

        else if (input == 3)
        {
            string itemFind;
            cout << "What item are you trying to search?:" << endl;
            getline(cin, itemFind);

            Item.findItem(itemFind);
        }

        else if (input == 4)
        {
            cout << Item.countItemNodes() << " items remain unsold" << endl;
        }

        else if (input == 5)
        {
            Item.printInOrder();
        }

        else if (input == 6)
        {
            Item.printPreOrder();
        }

        else if (input == 7)
        {
            Item.printPostOrder();
        }

        else if (input == 8)
        {
            Item.printSold();
        }
    }

    cout << "Quit" << endl;
}
