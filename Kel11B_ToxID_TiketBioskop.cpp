#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

class Pengguna {
public:
    string namaPengguna;
    string kataSandi;

    Pengguna() {}  
    Pengguna(string nama, string sandi) : namaPengguna(nama), kataSandi(sandi) {}
};


class Film {
public:
    string judul;
    string waktu;

    Film(string j, string w) : judul(j), waktu(w) {}
};


class Bioskop {
public:
    string nama;
    vector<Film> filmList;
    vector<vector<char>> kursi;

    Bioskop(string n, int baris, int kolom) : nama(n), kursi(baris, vector<char>(kolom, 'O')) {}

    void tambahFilm(string judul, string waktu) {
        filmList.push_back(Film(judul, waktu));
    }

    void tampilkanFilm() {
        for (size_t i = 0; i < filmList.size(); ++i) {
            cout << i + 1 << ". " << filmList[i].judul << " pada " << filmList[i].waktu << endl;
        }
    }

    void tampilkanKursi() {
        for (size_t i = 0; i < kursi.size(); ++i) {
            for (size_t j = 0; j < kursi[i].size(); ++j) {
                cout << kursi[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool pesanKursi(int baris, int kolom) {
        if (baris < 0 || baris >= kursi.size() || kolom < 0 || kolom >= kursi[0].size() || kursi[baris][kolom] == 'X') {
            return false;
        }
        kursi[baris][kolom] = 'X';
        return true;
    }
};

class SistemPemesananTiket {
private:
    unordered_map<string, Pengguna> pengguna;
    vector<Bioskop> bioskopList;
    Pengguna* penggunaLogin = nullptr;

