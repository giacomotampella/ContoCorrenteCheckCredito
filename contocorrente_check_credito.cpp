#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>

using namespace std;

const int NMAX = 100;

// struttura movimento 
struct Movimento {
	char data[11]; // gg/mm/aaaa e il \0
	float importo; // importo del movimento: numero reale positivo
	char segno; // '+' o '-' per indicare i movimenti in entrata e quelli in uscita
};

struct ContoCorrente {
	Movimento mov[NMAX]; // array con i movimenti di tipo Movimento in modo tale da avere per ogni dato: data / importo / segno
	int n_mov; // numero di movimenti compiuti
	float saldo_i; // saldo iniziale
	char cc[32]; // numero di conto corrente
};

Movimento carica_movimento () {
	Movimento m;
	cin.ignore();
	cout << "Data: ";
	cin.getline(m.data, 11);
	cout << "Importo: ";
	cin >> m.importo; 
	cout << "Segno (+ o -): ";
	cin >> m.segno;
	return m;
}

Movimento stampa_mov (Movimento m) {
	cout << "!! Hai superato la soglia limite con il seguente movimento: " << m.data << "  " << m.importo << " " << m.segno << " !!";
	cout << endl << endl;
}

float check_credito (ContoCorrente cnt, float c) {
	cout << "Numero movimenti: ";
	do {
		cin >> cnt.n_mov;
	} while (cnt.n_mov <= 0 || cnt.n_mov >= NMAX);
	cout << endl;
	float conto = cnt.saldo_i;
	for (int i = 0; i < cnt.n_mov; i++) {
		cnt.mov[i] = carica_movimento();
		cout << endl;
		if (cnt.mov[i].segno == '+') {
			conto += cnt.mov[i].importo;
		} else {
			conto -= cnt.mov[i].importo;
		}
		if (conto <= c) {
			stampa_mov(cnt.mov[i]);
		}
	}
	return conto;
}

float credito_tot (ContoCorrente cnt) {
	float totale = cnt.saldo_i;
	for (int i = 0; i < cnt.n_mov; i++) {
		if (cnt.mov[i].segno == '+') {
			totale += cnt.mov[i].importo;
		} else {
			totale -= cnt.mov[i].importo;
		}
	}
	cout << totale;
}

int main() {
	ContoCorrente conto;
	float c;
	cout << "Numero conto corrente: ";
	cin.getline(conto.cc, 32);
	cout << endl;
	do {
		cout << "Saldo iniziale (>0): ";
		cin >> conto.saldo_i;
	} while (conto.saldo_i <= 0);
	cout << endl;	
	do {
		cout << "Limite di credito (c < 0): ";
		cin >> c;
	} while (c > 0);
	cout << endl;
	check_credito(conto, c);
	cout << endl << endl << "Saldo finale: " << credito_tot(conto);
}
