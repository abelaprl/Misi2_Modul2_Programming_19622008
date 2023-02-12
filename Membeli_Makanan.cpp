
#include <cstdlib>  // ini biar bisa pakai system("CLS") di dalam wait()
#include <iomanip>  // ini biar bisa format tulisan supaya rapi. Yang setw(x)
#include <iostream> // ini standard library c++
#include <limits>   // ini untuk fungsi wait()
#include <string>   // ini biar bisa pakai string
#include <vector>   // ini untuk biar bisa pakai vector

using namespace std;

class Shop {
private:
  vector<string> daftar_menu = {"mie",    "gado-gado",      "beras",
                                "roti",   "susu",           "kopi",
                                "permen", "kentang goreng", "air mineral",
                                "bakso",  "keripik pisang", "teh hijau"};
  vector<float> daftar_harga = {7000, 12000, 13500, 2500,  5500, 1500,
                                1000, 6700,  3000,  10500, 7500, 2500};
  vector<bool> daftar_jenis = {1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0};
  vector<pair<string, pair<string, pair<float, int>>>> pesanan;
  // (nama_orang, (nama_makanan, (harga, quantity)))

  char buka;
  string nama_pelanggan;
  int pilihan_opsi;

  float revenue = 0;   // total penjualan (Total pendapatan)
  float item_sold = 0; // banyak item terjual

public:
  void wait() {
    cout << "Press Enter to Continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("clear"); // system("cls")
  }

  Shop() {

    cout << "SELAMAT DATANG" << endl;
    wait();

    bool isRun = 1;
    while (isRun) {
      isRun = buka_toko();
    }
    show_history();
  }

  bool buka_toko() {
    cout << "Mau buka toko? y/n" << endl;

    cin >> buka;

    if (buka == 'n') {
      cout << "BYE BYE" << endl;
      wait();
      return false;
    } else if (buka == 'y') {
      wait();
      terima_pelanggan();
      return true;
    } else {
      cout << "Invalid Input! Please input y or n only!" << endl;
      wait();
      buka_toko();
    }
  }

  void terima_pelanggan() {
    cout << "TOKO SUDAH DIBUKA!\n";

    cout << "Masukkan nama pelanggan: ";
    cin >> nama_pelanggan;

    wait();
    show_option();
  }

  void show_option() {
    int pilihan;
    cout << "Silahkan pilih opsi yang ada" << endl;
    cout << "1. Lihat Seluruh menu" << endl;
    cout << "2. Beli makanan/minuman" << endl;
    cout << "3. keluar" << endl;
    cin >> pilihan;

    if (pilihan == 1) {
      wait();
      show_menu();
      wait();
      show_option();
    } else if (pilihan == 2) {
      // sesuatu
      wait();
      bikin_pesanan();
      wait();
      show_option();
    } else if (pilihan == 3) {
      show_history();
    }
  }

  void show_menu() {
    cout << setw(2) << "NO" << setw(20) << "NAMA" << setw(10) << "JENIS"
         << setw(20) << "HARGA" << endl;
    for (int i = 0; i < daftar_menu.size(); i++) {
      string s = "makanan";
      if (daftar_jenis[i]) {
        s = "makanan";
      } else {
        s = "minuman";
      }

      cout << setw(2) << i << setw(20) << daftar_menu[i] << setw(10) << s
           << setw(20) << daftar_harga[i] << endl;
    }
  }

  void bikin_pesanan() {
    show_menu();
    int id;
    int jumlah;

    cout << "Silahkan masukkan ID menu : ";
    cin >> id;
    cout << "Masukkan Jumlah : ";
    cin >> jumlah;

    // untuk masukkan data
    pesanan.push_back(make_pair(
        nama_pelanggan,
        make_pair(daftar_menu[id], make_pair(daftar_harga[id], jumlah))));

    cout << "Anda memesan " << daftar_menu[id] << " dengan jumlah " << jumlah
         << " x " << daftar_harga[id] << " = " << jumlah * daftar_harga[id]
         << endl;
  }
  // (x, (y, z))
  // .first | x
  // .second | (y, z)
  // .second.first | y
  // .second.second | z

  void show_history() {
    if (pesanan.empty()) {
      cout << "TIDAK ADA PENJUALAN" << endl;
    } else {
      cout << setw(2) << "ID" << setw(10) << "NAMA" << setw(20) << "PESANAN"
           << setw(10) << "HARGA" << setw(10) << "QUANTITY" << setw(20)
           << "TOTAL HARGA" << endl;

      for (int i = 0; i < pesanan.size(); i++) {
        revenue +=
            pesanan[i].second.second.first * pesanan[i].second.second.second;
        item_sold += pesanan[i].second.second.second;
        cout << setw(2) << i << setw(10) << pesanan[i].first << setw(20)
             << pesanan[i].second.first << setw(10)
             << pesanan[i].second.second.first << setw(10)
             << pesanan[i].second.second.second << setw(20)
             << pesanan[i].second.second.first * pesanan[i].second.second.second
             << endl;
      }
      cout << "Total Pendapatan: " << revenue << endl;
      cout << "Total item terjual: " << item_sold << " item" << endl;
    }

    exit(0);
  }
};

int main() {
  Shop s1;

  return 0;
}
