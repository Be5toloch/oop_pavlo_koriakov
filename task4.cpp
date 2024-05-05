#include <iostream>

using namespace std;

class Ipv4Address{
    int len=4;

public:
    char *arr;

    Ipv4Address():
    arr(new char [len])

    }

    void setter1(char _val1){
        arr[0]=_val1;
    }

    void setter2(char _val2){
        arr[1]=_val2;
    }

    void setter3(char _val3){
        arr[2]=_val3;
    }

    void setter4(char _val4){
        arr[3]=_val4;
    }

    char getter1(){
        return arr[0];
    }
    char getter2(){
        return arr[1];
    }
    char getter3(){
        return arr[2];
    }
    char getter4(){
        return arr[3];
    }

};


class Request : public Ipv4Address{
    Ipv4Address origin;

    char a = arr[0];
    char b = arr[1];
    char c = arr[2];
    char d = arr[3];

public:
    Request():
    Ipv4Address()
    {
        
    }



    void log(){
        cout<<"Request of unknown type from "<<a<<"."<<b<<"."<<c<<"."<<d;
    }
};


int main(){

char val1, val2, val3, val4;

cout<<"Enter the value for a: "<<endl;
cin>>val1;
cout<<"Enter the value for b: "<<endl;
cin>>val2;
cout<<"Enter the value for c: "<<endl;
cin>>val3;
cout<<"Enter the value for d: "<<endl;
cin>>val4;

Request ad;

ad.setter1(val1);
ad.setter2(val2);
ad.setter3(val3);
ad.setter4(val4);
/*cout<<ad.getter1()<<endl;
cout<<ad.getter2()<<endl;
cout<<ad.getter3()<<endl;
cout<<ad.getter4()<<endl;*/
ad.log();


return 0;
}