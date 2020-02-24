#include <iostream>
#include "tree.h"
#include "node.h"
using namespace std;

int main()
{
    Tree t;
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        t.insert(n);
    }

    t.print(t.root);
    return 0;
}
