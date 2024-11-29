#include <iostream>
#include <string>

using namespace std;

class Flights {

  private:
    string flight_name;
    float price;
    bool first_class;
    int duration_hrs;
    string date;
    int distance;

  public:
    Flights(string _flight_name, float _price, bool _first_class, int _duration_hrs,string _date,int _distance){
      flight_name = _flight_name;
      price = _price;
      duration_hrs = _duration_hrs;
      first_class = _first_class;
      date = _date;
      distance = _distance;
    };
    void show_info();
    string get_flight_name();
    string get_date();
    float get_price();
    bool get_first_class();
    int get_duration_hrs();
    int get_distance();

};



  string Flights::get_flight_name(){
    return flight_name;
  }
  float Flights::get_price(){
    return price;
  }
  bool Flights::get_first_class(){
    return first_class;
  }

  int Flights::get_duration_hrs(){
    return duration_hrs;
  }

  string Flights::get_date(){
    return date;
  }

  int Flights::get_distance(){
    return distance;
  }

  void Flights::show_info(){
    cout<<"Flights:"<<endl;
    cout<<"Flight Name: "<<get_flight_name()<<endl;
    cout<<"Price: "<<get_price()<<endl;
    cout <<"First Class: " << (get_first_class() ? "Yes" : "No") << endl;
    cout<<"Duration HRS: "<<get_duration_hrs()<<endl;
    cout<<"Date: "<<get_date()<<endl;
  }



