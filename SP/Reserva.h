#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
#include "usuario.h"
#include "vuelos.h"

using namespace std;

class Booking {
private:
    int num_booking, day, month;
    string username, flight_name;
    bool first_class, active;
    float price;
public:
    Booking() {
        num_booking = 0;
        username = "";
        first_class = false;
        active = true;
        price = 0;
        day, month = 1;
        flight_name = "";
    }
    void setNumBooking(int nb);
    void setUsername(string un);
    void setFlightName(string fn);
    void setFirstClass(bool fc);
    void setPrice(float p);
    void setDay(int d);
    void setMonth(int m);
    void createBooking(User& user, string username, Flights& flight, float price, string flight_name, int day, int month,
        int num_booking, bool first_class);
    void showDetails();
};

//set methods
inline void Booking::setNumBooking(int nb) {
    num_booking = nb;
}
inline void Booking::setUsername(string un) {
    username = un;
}
inline void Booking::setFlightName(string fn) {
    flight_name = fn;
}
inline void Booking::setFirstClass(bool fc) {
    first_class = fc;
}
inline void Booking::setPrice(float p) {
    price = p;
}
inline void Booking::setDay(int d) {
    day = d;
}
inline void Booking::setMonth(int m) {
    month = m;
}

inline void Booking::createBooking(User &user, string username, Flights &flight, float price, string flight_name, int day,
    int month, int num_booking, bool first_class) {
    //
    username = user.getName();
    setUsername(username);

    //
    flight_name = flight.get_flight_name();
    setFlightName(flight_name);

    //
    price = flight.get_price();
    setPrice(price);

    //
    day = flight.get_day();
    setDay(day);

    //
    month = flight.get_month();
    setMonth(month);

    //
    setNumBooking(num_booking);

    //
    setFirstClass(first_class);
}

inline void Booking::showDetails() {
    cout << "Numero de reserva: " << num_booking << endl;
    cout << "Usuario enlazado a la reserva: " << username << endl;
}










#endif //RESERVA_H
