#include <iostream>

using namespace std;


class Hui{
    int piska;
public:
    Hui(int manda):
    piska(manda)
    {
        cout<<"misha loh "<<piska;
    }

    Hui (){
        cout<<"misha ne loh";
    }

};

int main(){
    Hui debil(5);
}