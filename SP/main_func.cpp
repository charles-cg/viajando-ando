#include "usuario.h"
#include "Flights.h"
#include "Reserva.h"
#include <vector>
#include <iostream>
using namespace std;


void showMenu() {

    cout << "|| Bienvenido al sistema Viajando Ando!! ||\n";
    cout << "Escoga la opción que desee (escriba el número correspondiente) \n";
    cout << "1. Registrar nuevo usuario\n";
    cout << "2. Mostrar todos los vuelos\n";
    cout << "3. Reservar vuelo\n";
    cout << "4. Cancelar Reserva\n";
    cout << "5. Salir\n";
}


int main() {
    int option;

    int idcount = 1;

    vector<User> users;

    vector<Flights> flight_list;

    // Add flights to the list
    flight_list.push_back(Flights("Ciudad de México-Japon", 850.00,  14, "22-10", 10944));
    flight_list.push_back(Flights("España-Francia", 150.00,  2, "10-10", 800));
    flight_list.push_back(Flights("Australia-Ciudad de México", 1300.00,  15, "10-10", 12875));
    flight_list.push_back(Flights("Hungría-República Checa", 150.00,  1, "13-11", 480));
    flight_list.push_back(Flights("Estados Unidos-México", 400.00,  5, "15-12", 2414));

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
                cout << "Se la ha asignado el id de " << idcount << endl;

                idcount++;

                break;
            }

            case 2: {
                // Loop through the list and show only the flight name
                for (int i = 0; i < flight_list.size(); i++) {
                    cout << flight_list[i].get_flight_name() << endl;
                }
                break;
            }

            case 3: {
                // Implement option 3: Buscar vuelos en una fecha específica
                int id = 0;
                string pass_input = "";

                cout << "Ingrese id: " << endl; cin >> id;
                string username = users.at(id-1).getName();
                cout << "username: " << username << endl;
                string pass_user = users.at(id-1).getPassword();
                cout << "Contrasena: \n"; cin >> pass_input;

                if (pass_input == pass_user) {
                    cout << "Falta funcion\n";
                } else {
                    break;
                }
            }

            case 4: {
                // Implement option 4: cancelar
                cout << "Cancelar vuelo." << endl;
                break;
            }
            case 5: {
                // Salir
                cout << "Hasta pronto" << endl;
            }
        }
    } while (option != 8);

    return 0;
}
