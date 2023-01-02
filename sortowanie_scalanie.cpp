// sortowanie_scalanie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <time.h>
using namespace std;


// Procedura sortująca
//--------------------

void MergeSort(int i_p, int i_k)
{
    int d[i_k + 1], p[i_k + 1];
    int i_s, i1, i2, i;

    i_s = (i_p + i_k + 1) / 2;
    if (i_s - i_p > 1) MergeSort(i_p, i_s - 1);
    if (i_k - i_s > 0) MergeSort(i_s, i_k);
    i1 = i_p; i2 = i_s;
    for (i = i_p; i <= i_k; i++)
        p[i] = ((i1 == i_s) || ((i2 <= i_k) && (d[i1] > d[i2]))) ? d[i2++] : d[i1++];
    for (i = i_p; i <= i_k; i++) d[i] = p[i];
}

void zapisanie_danych(string nazwa, long int elementy, long int czas) { // funkcja zapisujaca dane z wektora do pliku
    ofstream do_pliku(nazwa);
    do_pliku << elementy;
    do_pliku << czas;
}
// Program główny
//---------------

int main()
{
    for (const int N = 2; N <= 1000; N++) {
        auto start = chrono::high_resolution_clock::now();
        int d[N], p[N];
        int i;

        cout << " Sortowanie przez scalanie\n"
            "---------------------------\n"
            "  (C)2005  Jerzy Walaszek\n\n"
            "Przed sortowaniem:\n\n";

        // Najpierw wypełniamy tablicę d[] liczbami pseudolosowymi
        // a następnie wyświetlamy jej zawartość

        srand((unsigned)time(NULL));

        for (i = 0; i < N; i++) d[i] = rand() % 100;
        for (i = 0; i < N; i++) cout << setw(4) << d[i];
        cout << endl;

        // Sortujemy

        MergeSort(0, N - 1);

        // Wyświetlamy wynik sortowania

        cout << "Po sortowaniu:\n\n";
        for (i = 0; i < N; i++) cout << setw(4) << d[i];
        cout << endl;
        auto koniec = chrono::high_resolution_clock::now(); //koniec pomiaru czasu
        auto miara_czasu = chrono::duration_cast<chrono::nanoseconds>(koniec - start);
        double czas = miara_czasu.count() * 1e-9;
        zapisanie_danych("scalanie_czas.txt", N, czas)

    }
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
