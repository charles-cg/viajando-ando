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
        first_class, active = false;
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
    void createBooking(User& user, string username, Flights& flight, int price, string flight_name, int day, int month);
};
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

inline void Booking::createBooking(User &user, string username, Flights &flight, int price, string flight_name, int day, int month) {
    user.getName();
}









#endif //RESERVA_H
