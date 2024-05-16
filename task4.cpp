#include <iostream>

using namespace std;

const int COUNT_OF_VALUES = 4;

class Ipv4Address{
    int len = COUNT_OF_VALUES;

public:
    char *arr;

    Ipv4Address():
    arr(new char [len])
    {

    }

    void setterValueToArray(char _val, int indexOfArray) {
        arr[indexOfArray] = _val;
    }

    char getterValueFromArray(int indexOfArray) {
        return arr[indexOfArray];
    }

};


class Request : public Ipv4Address{

public:
    Request():
    Ipv4Address()
    {
        
    }

    void log(){
        cout<<"Request of unknown type from "<<static_cast<int>(arr[0])<<"."<<static_cast<int>(arr[1])<<"."<<static_cast<int>(arr[2])<<"."<<static_cast<int>(arr[3])<<endl;
    }
};


class HttpRequest : public Request{
    string url;
public:

    HttpRequest(){

    }


    void SetterStringForUrl(string _url){
        this->url = _url;
    }

    void printLog(){
        cout<<"Http Request of from "<<static_cast<int>(arr[0])<<"."<<static_cast<int>(arr[1])<<"."<<static_cast<int>(arr[2])<<"."<<static_cast<int>(arr[3]) <<" to url: "<<url<<endl;
    }
};

int main(){


char values[COUNT_OF_VALUES];

const char* labels[COUNT_OF_VALUES] = {"a", "b", "c", "d"};


for (int i = 0; i < COUNT_OF_VALUES; i++)
{
    cout<<"Enter the value for "<<labels[i]<<": "<<endl;
    cin>>values[i];
}

Request request;

for (int i = 0; i < COUNT_OF_VALUES; i++)
{
    request.setterValueToArray(values[i], i);
}

request.log();

HttpRequest http;

for (int i = 0; i < COUNT_OF_VALUES; i++) {
    http.setterValueToArray(request.getterValueFromArray(i), i);
}

http.SetterStringForUrl("Hello");
http.printLog();

return 0;
}