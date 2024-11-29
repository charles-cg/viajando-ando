#include <iostream>
#include <string>

using namespace std;

class Flights {

private:
    string flight_name;
    float price;
    int duration_hrs;
    int day, month;
    float distance;

public:
    Flights(string _flight_name, float _price, int _duration_hrs,int _day, int _month, int _distance){
        flight_name = _flight_name;
        price = _price;
        duration_hrs = _duration_hrs;
        day = _day;
        month = _month;
        distance = _distance;
    };
    void show_info();
    string get_flight_name();
    int get_day();
    int get_month();
    float get_price();
    //bool get_first_class();
    int get_duration_hrs();
    int get_distance();

};



string Flights::get_flight_name(){
    return flight_name;
}
float Flights::get_price(){
    return price;
}
//bool Flights::get_first_class(){
//return first_class;
//}

int Flights::get_duration_hrs(){
    return duration_hrs;
}

int Flights::get_day(){
    return day;
}
int Flights::get_month(){
    return month;
}

int Flights::get_distance(){
    return distance;
}

void Flights::show_info(){
    cout<<"Detalles de vuelo:"<<endl;
    cout<<"nombre del vuelo: "<<get_flight_name()<<endl;
    cout<<"Precio: "<<" $"<< get_price()<<endl;
    //cout <<"First Class: " << (get_first_class() ? "Yes" : "No") << endl;
    cout<<"Duracion en horas: "<<get_duration_hrs()<<endl;
    cout<<"Fecha: "<<get_day()<< "/" << get_month()<< endl;
}


