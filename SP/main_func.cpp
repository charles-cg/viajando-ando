#include "Reserva.h"
#include <vector>
#include <iostream>

using namespace std;


void showMenu() {

    cout << "\n|| Bienvenido al sistema de reservas Viajando Ando!! ||\n";
    cout << "Escoga la opcion que desee (escriba el numero correspondiente) \n";
    cout << "1. Registrar nuevo usuario\n";
    cout << "2. Mostrar todos los vuelos\n";
    cout << "3. Reservar\n";
    cout << "4. Cancelar Reserva\n";
    cout << "5. Salir\n";
}


int main() {
    int option;

    int idcount = 1;

    int num_book = 1;

    vector<User> users;

    vector<Flights> flight_list;

    vector<Booking> bookings;

    // Add flights to the list
    flight_list.push_back(Flights("Ciudad de Mexico-Japon", 850.00,  14, 22, 10, 10944));
    flight_list.push_back(Flights("Espana-Francia", 150.00,  2, 10, 10, 800));
    flight_list.push_back(Flights("Australia-Ciudad de Mexico", 1300.00,  15, 10, 10, 12875));
    flight_list.push_back(Flights("Hungria-Republica Checa", 150.00,  1, 13, 11, 480));
    flight_list.push_back(Flights("Estados Unidos-Mexico", 400.00,  5, 15, 12, 2414));

    do {
        showMenu();

        cout<<"Escoga la opcion que desee (teclee el numero correspondiente):"<<endl;

        cin>>option;

        switch (option){
            case 1: {

                User new_user;
                new_user.registerUser();
                new_user.setID(idcount);

                users.push_back(new_user);

                cout << "Usuario registrado con exito!\n";
                cout << "Se la ha asignado el id de " << idcount << "\n\n";

                idcount++;

                break;
            }

            case 2: {
                // Loop through the list and show only the flight name
                for (int i = 0; i < flight_list.size(); i++) {
                    cout << i+1 << ". Vuelo " << flight_list[i].get_flight_name() << " ";
                    cout << "fecha: " << flight_list.at(i).get_day() << "/" << flight_list.at(i).get_month() << " ";
                    cout << "precio: $" << flight_list.at(i).get_price() << " " << endl;
                }
                break;
            }
            case 3: {
                //Reservar
                int id = 0;
                string pass_input = "";

                cout << "Ingrese ID del usuario: " << endl; cin >> id;
                string username = users.at(id-1).getName();
                cout << "username: " << username << endl;
                string pass_user = users.at(id-1).getPassword();
                cout << "Contrasena: \n"; cin >> pass_input;

                if (pass_input == pass_user) {
                    int opt_book = 0;
                    int opt_seats = 0;
                    int first_class = false;

                    cout << "Seleccione uno de los vuelos mostrados anteriormente: \n"; cin >> opt_book;

                    cout << "Detalles del vuelo seleccionado:\n";
                    flight_list.at(opt_book - 1).show_info();

                    cout << "Desea asiento de primera clase?\nEl precio es 10 veces mayor a la clase turista. 1. si 2. no\n";
                    cin >> opt_seats;

                    if (opt_seats == 1) {
                        first_class = true;

                        Booking new_booking;
                        new_booking.createBooking(users.at(id-1), users.at(id-1).getName(), flight_list.at(opt_book-1),
                        (flight_list.at(opt_book-1).get_price()*10), flight_list.at(opt_book-1).get_flight_name(),
                        flight_list.at(opt_book - 1).get_day(), flight_list.at(opt_book - 1).get_month(), num_book,
                        first_class);
                        bookings.push_back(new_booking);

                        cout << "La reserva se ha realizado con exito!\n";
                        cout << "El numero de reserva asignado fue el: " << num_book << endl;

                        num_book++;
                        break;
                    } if (opt_seats == 2) {
                        first_class = false;

                        Booking new_booking;
                        new_booking.createBooking(users.at(id-1), users.at(id-1).getName(), flight_list.at(opt_book-1),
                        flight_list.at(opt_book-1).get_price(), flight_list.at(opt_book-1).get_flight_name(),
                        flight_list.at(opt_book - 1).get_day(), flight_list.at(opt_book - 1).get_month(), num_book,
                        first_class);
                        bookings.push_back(new_booking);

                        cout << "La reserva se ha realizado con exito!\n";
                        cout << "El numero de reserva asignado fue el: " << num_book << endl;

                        num_book++;
                        break;
                    } else {
                        cout << "Vuelo invalido\n";
                        break;
                    }

                } else {
                    cout << "Contrasena incorrecta!!\n";
                    break;
                }
            }
            case 4: {
                // Cancelar Reserva
                int id = 0;
                string pass_input = "";

                cout << "Ingrese ID del usuario: " << endl; cin >> id;
                string username = users.at(id-1).getName();
                cout << "username: " << username << endl;
                string pass_user = users.at(id-1).getPassword();
                cout << "Contrasena: \n"; cin >> pass_input;

                if(pass_input == pass_user){
                    int num_reserva;
                    cout << "Ingrese el numero de reserva que desea cancelar: ";
                    cin >> num_reserva;

                    bool found = false;
                    for (int i = 0; i < bookings.size(); i++) {
                        if (bookings[i].getNumBooking() == num_reserva and users[id-1].getName() == bookings[i].getUsername()
                            and bookings[i].isActive() == true) {
                            bookings[i].cancelBooking();
                            cout << "Reserva cancelada con exito.\n";
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "No se encontro una reserva con ese numero dentro de la cuenta.\n";
                }
                    break;
                }else {
                    cout << "Contrasena incorrecta.\n";
                }
            }
            case 5: {
                // Salir
                cout << "Hasta pronto" << endl;
            }
        }
    } while (option != 5);

    return 0;
}