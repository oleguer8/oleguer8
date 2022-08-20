#include "codicesar.h"

int cesar() {
	string msg;
	int clau;

	while (1) {
		cout << "Selecciona:\n1 => Encriptar\n2 => Desencriptar";

		char opt;
		do opt = _getch(); while (opt != '1' && opt != '2');
		system("cls");

		cout << "Escriu la clau: ";		
		cin >> clau;

		cout << "Escriu el Missatge:\n";	
		cin >> ws;
		getline(cin, msg);

		if (opt == '1') {
			string nuevo = Sustitucion::Xifrar(msg);
			cout << "\nMissatge encriptat: " << nuevo;
		} else {
			string nuevo = Sustitucion::DesXifrar(msg);
			cout << "\nMissatge desxifrat: " << nuevo;
		}
		_getch();
		system("cls");
	}
	return 0;
}