// projektC++.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// Projekt_Laby.cpp : Ten plik zawiera funkcjÄ™ â€žmainâ€ť. W nim rozpoczyna siÄ™ i koĹ„czy wykonywanie programu.
//
//deklaracja potrzebnych bibliotek
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
//tworzenie funkcji szukającej powtarzającego się elementu
int pow(vector<int> tablica) {
	int x=0;
	for (int i = 0; i <= tablica.size(); i++) { //funkcje szukające powtarzającego się elemetu
		
		for (int j = 0; j <= tablica.size(); j++) {
			x++;
			if (i == j) { break; } 
			if (tablica[i] == tablica[j]) { //jesli znalezlismy powtarzajacy element to go zwracamy
				return x;

			}
		}
	}
}
vector<int> pobranie_danych(string nazwa) {// funkcja pobierajaca dane z pliku do wektora
	ifstream indata(nazwa); //otwarcie pliku
	if (!indata.is_open()) {
		cout << "Blad otwarcia pliku " << nazwa <<endl; // w razie bledu otwarcia pliki
		return {};
	}
	int tmp;
	vector<int> data;
	while (!indata.fail() && !indata.eof()) // do konca danych 
	{
		indata >> tmp;
		data.push_back(tmp);
	}
	indata.close(); //zamkniecie pliku
	return data;
}
void zapisanie_danych(string nazwa, long int elementy, long int ins) { // funkcja zapisujaca dane z wektora do pliku
	ofstream do_pliku(nazwa);
	do_pliku << elementy;
	do_pliku << ins;
}


int main()
{
	
	vector<int> dane = pobranie_danych("dane.txt");
	auto start = chrono::high_resolution_clock::now(); // start pomiaru czasu
	for (long int i = 0; i <= 1000000; i++) {
		dane.push_back(i);
		dane.push_back(i);
		int ins = pow(dane);
		zapisanie_danych("zlozonosc.txt", i, ins);
		dane.erase(dane.begin() + i);
	}
	//dane.push_back(max)
	
	//cout << "Powtarzajacy element to " << pow(dane) << endl;
	//auto koniec = chrono::high_resolution_clock::now(); //koniec pomiaru czasu
	//auto miara_czasu = chrono::duration_cast<chrono::nanoseconds>(koniec - start);
	//double czas = miara_czasu.count() * 1e-9;
	//zapisanie_danych("zapis.txt", pow(dane), czas);

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
