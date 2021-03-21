#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <errno.h>
using namespace std;

struct Student
{
    string imie;
    string nazwisko;
    string plec; // m, f
    string nr_pesel;
    int nr_indeksu;
    double srednia;
};

struct BazaStudentow
{
    vector <Student> Baza1;
};

void display_student (const Student & student)
{
    cout << "Imie: " << student.imie << endl;
    cout << "Nazwisko: " << student.nazwisko << endl;
    cout << "Plec: " << student.plec << endl;
    cout << "Numer pesel: " << student.nr_pesel << endl;
    cout << "Numer indeksu: " << student.nr_indeksu << endl;
    cout << "Srednia z poprzedniego semestru: " << student.srednia;
}

void display_all_students (const vector <Student> & vec)
{
    for( size_t i = 0; i < vec.size(); i++)
    {
        display_student(vec[i]);
        cout << endl << endl;
    }
}

void sort_students (vector <Student> & vec)
{
    for(size_t i = 0; i < vec.size()-1; i++)
    {
        for(size_t j = 0; j < vec.size()-1-i; j++)
        {
            if(vec[j].srednia < vec[j+1].srednia)
                swap( vec[j], vec[j+1] ); //#include <algorithm>
        }
    }
}

BazaStudentow add_student (BazaStudentow Baza, const Student & osoba)
{
    Baza.Baza1.push_back(osoba);
    return Baza;
}

void display_database (const BazaStudentow & Baza)
{
    display_all_students(Baza.Baza1);
}

void find_student ( BazaStudentow & Baza, const int indeks)
{
  int miejsce = -1;
  Student tmp;

  for(size_t i = 0; i < Baza.Baza1.size(); i ++)
  {
    tmp = Baza.Baza1[i];
    if(tmp.nr_indeksu == indeks)
    {
      miejsce = i;
      break;
    }
  }

  if(miejsce != -1)
    cout << "Student znajduje sie na " << miejsce << " pozycji.";
  else
    cout << "Studenta nie ma w bazie: " << miejsce;
}

BazaStudentow remove_student(BazaStudentow & Baza, int indeks)
{
  Student tmp;

  for(size_t i = 0; i < Baza.Baza1.size(); i++)
  {
    tmp = Baza.Baza1[i];
    if(tmp.nr_indeksu == indeks)
    {
      Baza.Baza1.erase(Baza.Baza1.begin()+i);
    }
  }

  return Baza;
}

Student load_student()
{
  Student osoba;

  ifstream dane ("dane_odczyt.txt");

  if ( ! dane )
  {
    cerr << "Blad otwarcia pliku: " << strerror(errno) << endl;
    exit(1);
  }

  dane >> osoba.imie;
  dane >> osoba.nazwisko;
  dane >> osoba.plec;
  dane >> osoba.nr_pesel;
  dane >> osoba.nr_indeksu;
  dane >> osoba.srednia;

  return osoba;
}

void save_student(const Student & osoba)
{
  ofstream dane ("dane_zapis.txt");

  if ( ! dane )
  {
    cerr << "Blad otwarcia pliku: " << strerror(errno) << endl;
    exit(1);
  }

  dane << osoba.imie << endl;
  dane << osoba.nazwisko << endl;
  dane << osoba.plec << endl;
  dane << osoba.nr_pesel << endl;
  dane << osoba.nr_indeksu << endl;
  dane << osoba.srednia;
  dane.close();
}

int main()
{
    Student osoba_0;

    /*cout << "Podaj imie studenta: ";
    getline(cin, osoba_0.imie);
    cout << "Podaj nazwisko studenta: ";
    getline(cin, osoba_0.nazwisko);
    cout << "Podaj plec studenta: ";
    getline(cin, osoba_0.plec);
    cout << "Podaj numer pesel studenta: ";
    getline(cin, osoba_0.nr_pesel);
    cout << "Podaj numer indeksu studenta: ";
    cin >> osoba_0.nr_indeksu;
    cout << "Podaj srednia z ostatniego semestru studenta: ";
    cin >> osoba_0.srednia;
    cout << endl;*/

    osoba_0.imie = "Maria";
    osoba_0.nazwisko = "Mza";
    osoba_0.plec = "f";
    osoba_0.nr_pesel = "00281523384";
    osoba_0.nr_indeksu = 245928;
    osoba_0.srednia = 4.8;

    //display_student(osoba_0);

    Student osoba_1;
    Student osoba_2;
    Student osoba_3;
    Student osoba_4;

    osoba_1.imie = "Anna";
    osoba_1.nazwisko = "Ma";
    osoba_1.plec = "f";
    osoba_1.nr_pesel = "00282693316";
    osoba_1.nr_indeksu = 243918;
    osoba_1.srednia = 4.6;

    osoba_2.imie = "Bartek";
    osoba_2.nazwisko = "Bez";
    osoba_2.plec = "m";
    osoba_2.nr_pesel = "00281539916";
    osoba_2.nr_indeksu = 341826;
    osoba_2.srednia = 3.9;

    osoba_3.imie = "Yui";
    osoba_3.nazwisko = "Higashikata";
    osoba_3.plec =  "f";
    osoba_3.nr_pesel = "00271139962";
    osoba_3.nr_indeksu = 536291;
    osoba_3.srednia = 4.4;

    osoba_4.imie ="Mike";
    osoba_4.nazwisko = "Wazowski";
    osoba_4.plec = "m";
    osoba_4.nr_pesel = "00261392213";
    osoba_4.nr_indeksu = 235172;
    osoba_4.srednia = 3.65;

    vector <Student> Studenci;
    Studenci.push_back(osoba_0);
    Studenci.push_back(osoba_1);
    Studenci.push_back(osoba_2);
    Studenci.push_back(osoba_3);
    Studenci.push_back(osoba_4);

    //sort_students(Studenci);

    //display_all_students(Studenci);

    BazaStudentow Baza;

    Baza = add_student(Baza, osoba_0);
    Baza = add_student(Baza, osoba_1);
    Baza = add_student(Baza, osoba_2);

    //display_database(Baza);

    //find_student(Baza, 243918);

    //Baza = remove_student(Baza, 243918);

    //display_database(Baza);

    save_student(osoba_0);
    Student osoba_5 = load_student();

    display_student(osoba_5);
}
