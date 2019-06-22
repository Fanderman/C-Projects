#include "header.h"

using namespace std;

int main() {
    /*
    BST<int> tree(5);
    tree.put(3);
    tree.put(7);
    tree.put(8);
    cout << tree.min() << endl;
    cout << tree.max() << endl;
    cout << tree.find(7) << endl;
    cout << tree.find(11) << endl;
    cout << tree.pop(7) << endl;
    cout << tree.find(7) << endl;
    cout << tree.find(8) << endl;

    BST<double> init{1,2,8,4};
    cout << init.pop(8) << endl;

    BST<int> test = tree;
    cout << test.find(9) << endl;
    */

    BST <int> tree;
    int input = 0;
    while(input != 7) {
            cout << "1. Put a value in \n2. Pop a value \n3. Find a value \n4. Print Max \n5. Print Min \n6. Is empty\n7. Quit\n";
            cin >> input;
            bool out;
            int input2;
            switch(input){
                case 1:
                    cin >> input2;
                    tree.put(input2);
                    cout << "Done.\n";
                    break;

                case 2:
                    cin >> input2;
                    out = tree.pop(input2);
                    if(out)
                        cout << "Done.\n";
                    else
                        cout << "Failed.\n";
                    break;

                case 3:
                    cin >> input2;
                    out = tree.find(input2);
                    if(out)
                        cout << "Found.\n";
                    else
                        cout << "Failed.\n";
                    break;

                case 4:
                    if(tree.empty()){
                        cout << "Nothing to write.\n";
                        break;
                    }
                    cout << "Max: " << tree.max() << endl;
                    break;

                case 5:
                    if(tree.empty()){
                        cout << "Nothing to write.\n";
                        break;
                    }
                    cout << "Min: " << tree.min() << endl;
                    break;

                case 6:
                    if(tree.empty())
                        cout << "True.\n";
                    else
                        cout << "False.\n";
                    break;

                case 7:
                    break;

                default:
                    cout << "incorrect input." << endl;
            }
    }

    return 0;
}