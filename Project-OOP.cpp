#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <windows.h>

using namespace std;

void hienthi(){
	
	string s={'B','A','N','K',' ','M','A','N','A','G','E','M','E','N','T',' ','S','Y','S','T','E','M'};
	cout<<"\n\n\n\n\n\n\t\t\t";
	for(int i=0;i<25;i++)
	{
		cout<<s[i];
		Sleep(100);
		
	}
	system("CLS");
	
}

class Nguoi {
private:
    int ID;
    string Hoten;
    string Ngaysinh;
    string SDT;
    string Email;
    string TenTK;
    string MK;

public:
	
	//Khoi tao lop nguoi
	Nguoi(int ID, string Hoten, string Ngaysinh, string SDT, string Email, string TenTK, string MK)
        : ID(ID), Hoten(Hoten), Ngaysinh(Ngaysinh), SDT(SDT), Email(Email), TenTK(TenTK), MK(MK) {}
    
    //Getter
	string getHoten(string Hoten){
        return Hoten;
    }

    string getTenTK(){
        return TenTK;
    }
    int getID(){
    	return ID;
	}
	string getHoten(){
		return Hoten;
	}
    string getNgaysinh(){
    	return Ngaysinh;
	}
    string getSDT(){
    	return SDT;
	}
    string getEmail(){
    	return Email;
	}
    string getMK(){
    	return MK;
	}
};

class KhachHang : public Nguoi {
private:
    int Tien;
public:
	
	//Khoi tao lop khach hang
	KhachHang(int ID, string Hoten, string Ngaysinh, string SDT, string Email, string TenTK, string MK, int Tien)
        : Nguoi(ID, Hoten, Ngaysinh, SDT, Email, TenTK, MK), Tien(Tien) {}
    
	//Getter
	int getTien(){
    	return Tien;
	}
	
	//Setter
	void setTien(int Tien){
    	this->Tien = Tien;
	}
};

class NhanVien : public Nguoi {
private:
    string Vitri;
    double Luong;
public:
	
	//Khoi tao lop nhan vien
	NhanVien(int ID, string Hoten, string Ngaysinh, string SDT, string Email, string TenTK, string MK, string Vitri, double Luong)
	: Nguoi(ID, Hoten, Ngaysinh, SDT, Email, TenTK, MK), Vitri(Vitri), Luong(Luong) {}
	
	//Getter
	string getVitri() {
        return Vitri;
    }
    double getLuong() {
        return Luong;
    }
};

class Bank {
private:
    vector<KhachHang> KH;
    vector<NhanVien> NV;

public:
    void quanliKH() {
        int choice;
        do {
            cout << setfill('-') << setw(120) << "" << setfill(' ') << endl;
            cout << "\n\t\t************ Quan Li Khach Hang ************\n" << endl;
            cout << "1. Tao tai khoan moi" <<"\t\t"<<"2. Kiem tra chi tiet tai khoan hien co" << endl;
            cout << "3. Xoa tai khoan" <<"\t\t"<<"4. Xem danh sach khach hang" << endl;
            cout << "5. Giao dich" <<"\t\t\t"<<"6. Thoat" << endl;
            cout << "\nNhap lua chon cua ban: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    TaoTKKH();
                    break;
                case 2:
                    KiemtraTKKH();
                    break;
                case 3:
                    XoaTKKH();
                    break;
                case 4:
                    XemdsKH();
                    break;
                case 5:
                	Giaodich();
                    break;
                case 6:
                	break;
                default:
                    cout << "Khong hop le" << endl;
            }
        } while (choice != 6);
    }

    void quanliNV() {
        int choice;
        do {
        	cout << setfill('-') << setw(120) << "" << setfill(' ') << endl;
            cout << "\n\t\t************ Quan Li Nhan Vien ************\n" << endl;
            cout << "1. Tao tai khoan moi" <<"\t\t  "<<"2. Kiem tra chi tiet tai khoan hien co" << endl;
            cout << "3. Xoa tai khoan" <<"\t\t  "<<"4. Xem danh sach nhan vien" << endl;
            cout << "\t\t\t5. Thoat" << endl;
            cout << "\nNhap lua chon cua ban: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    TaoTKNV();
                    break;
                case 2:
                    KiemtraTKNV();
                    break;
                case 3:
                    XoaTKNV();
                    break;
                case 4:
                    XemdsNV();
                    break;
                case 5:
                    break;
                default:
                    cout << "Khong hop le" << endl;
            }
        } while (choice != 5);
    }
//Khach hang
    void TaoTKKH() {
        int ID, Tien;
        string Hoten, Ngaysinh, SDT, Email, TenTK, MK;
        cout << "Nhap ID: ";
        cin >> ID;
        cout << "Nhap Ho ten: ";
        cin.ignore();
        getline(cin, Hoten);
        cout << "Nhap Ngay sinh: ";
        getline(cin, Ngaysinh);
        cout << "Nhap SDT: ";
        getline(cin, SDT);
        cout << "Nhap Email: ";
        getline(cin, Email);
        cout << "Nhap Ten tai khoan: ";
        getline(cin, TenTK);
        cout << "Nhap Mat khau: ";
        getline(cin, MK);
        cout << "Nhap so tien: ";
    	cin >> Tien;

        KhachHang kh(ID, Hoten, Ngaysinh, SDT, Email, TenTK, MK, Tien);
        KH.push_back(kh);
        cout << "Tao tai khoan khach hang thanh cong." << endl;
    }

void KiemtraTKKH() {
    int ID;
    cout << "Nhap ID tai khoan can kiem tra: ";
    cin >> ID;

    bool found = false;
    for (size_t i = 0; i < KH.size(); ++i) {
        if (KH[i].getID() == ID) {
            found = true;
            cout << "Thong tin tai khoan:" << endl;
            cout << "Ho ten: " << KH[i].getHoten() << endl;
            cout << "Ngay sinh: " << KH[i].getNgaysinh() << endl;
            cout << "SDT: " << KH[i].getSDT() << endl;
            cout << "Email: " << KH[i].getEmail() << endl;
            cout << "Ten tai khoan: " << KH[i].getTenTK() << endl;
            cout << "So tien: " << KH[i].getTien() << endl;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay tai khoan co ID " << ID << endl;
    }
}

    void XoaTKKH() {
    int ID;
    cout << "Nhap ID tai khoan can xoa: ";
    cin >> ID;

    bool found = false;
    for (size_t i = 0; i < KH.size(); ++i) {
        if (KH[i].getID() == ID) {
            found = true;
            KH.erase(KH.begin() + i);
            cout << "Xoa tai khoan thanh cong." << endl;
            break; 
        }
    }

    if (!found) {
        cout << "Khong tim thay tai khoan co ID " << ID << endl;
    }
}

    void XemdsKH() {
    	cout << "Danh sach thong tin khach hang:" << endl;
    	cout << setw(5) << "ID" << setw(20) << "Ho ten" << setw(15) << "Ngay sinh" 
			 << setw(15) << "SDT" << setw(25) << "Email" << setw(20) << "Ten tai khoan" 
			 << setw(20) << "So tien" << endl;
    	cout << setfill('-') << setw(120) << "" << setfill(' ') << endl;

    	for (size_t i = 0; i < KH.size(); ++i) {
        	cout << setw(5) << KH[i].getID() << setw(20) << KH[i].getHoten() << setw(15) << KH[i].getNgaysinh() 
				 << setw(15) << KH[i].getSDT() << setw(25) << KH[i].getEmail() << setw(20) << KH[i].getTenTK() 
				 << setw(20) << KH[i].getTien() << endl;
    	}
	}

    void Giaodich() {
        int choice;
        cout << setfill('-') << setw(120) << "" << setfill(' ') << endl;
        cout << "\n\t\t************ Giao Dich ************\n" << endl;
        cout << "1. Chuyen tien" <<"\t\t  "<<"2. Rut tien" << endl;
        cout << "3. Nap tien" <<"\t\t  "<<"4. Thoat" << endl;
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Chuyentien();
                break;
            case 2:
                Ruttien();
                break;
            case 3:
                Naptien();
                break;
            case 4:
                break;
            default:
                cout << "Khong hop le" << endl;
        }
    }

	void Chuyentien() {
    	int nguoiChuyen, nguoiNhan;
    	int soTien;
    	cout << "Nhap ID nguoi chuyen: ";
    	cin >> nguoiChuyen;
    	cout << "Nhap ID nguoi nhan: ";
    	cin >> nguoiNhan;
    	cout << "Nhap so tien: ";
		cin >> soTien;

    	int indexNguoiChuyen = -1;
    	for (int i = 0; i < KH.size(); ++i) {
        	if (KH[i].getID() == nguoiChuyen) {
            	indexNguoiChuyen = i;
            	break;
        	}
    	}

    	int indexNguoiNhan = -1;
    	for (int i = 0; i < KH.size(); ++i) {
        	if (KH[i].getID() == nguoiNhan) {
            	indexNguoiNhan = i;
            	break;
        	}
    	}

    	if (indexNguoiChuyen != -1 && indexNguoiNhan != -1) {
        	if (KH[indexNguoiChuyen].getTien() >= soTien) {
            	KH[indexNguoiChuyen].setTien(KH[indexNguoiChuyen].getTien() - soTien);
            	KH[indexNguoiNhan].setTien(KH[indexNguoiNhan].getTien() + soTien);
            	cout << "Giao dich thanh cong." << endl;
        	} else {
            	cout << "Khong du tien trong tai khoan." << endl;
        	}
    	} else {
        	cout << "Khong tim thay tai khoan." << endl;
    	}
		}

void Ruttien() {
    int nguoiRut;
    int soTien;

    cout << "Nhap ID nguoi rut: ";
    cin >> nguoiRut;
    cout << "Nhap so tien can rut: ";
    cin >> soTien;

    int indexNguoiRut = -1;
    for (int i = 0; i < KH.size(); ++i) {
        if (KH[i].getID() == nguoiRut) {
            indexNguoiRut = i;
            break;
        }
    }

    if (indexNguoiRut != -1) {
        if (KH[indexNguoiRut].getTien() >= soTien) {
           KH[indexNguoiRut].setTien(KH[indexNguoiRut].getTien() - soTien);
            cout << "Rut tien thanh cong." << endl;
        } else {
            cout << "Khong du tien trong tai khoan." << endl;
        }
    } else {
        cout << "Khong tim thay tai khoan." << endl;
    }
}

void Naptien() {
    int nguoiNap;
    int soTien;

    cout << "Nhap ID nguoi nap: ";
    cin >> nguoiNap;
    cout << "Nhap so tien can nap: ";
    cin >> soTien;

    int indexNguoiNap = -1;
    for (int i = 0; i < KH.size(); ++i) {
        if (KH[i].getID() == nguoiNap) {
            indexNguoiNap = i;
            break;
        }
    }

    if (indexNguoiNap != -1) {
        KH[indexNguoiNap].setTien(KH[indexNguoiNap].getTien() + soTien);
        cout << "Nap tien thanh cong." << endl;
    } else {
        cout << "Khong tim thay tai khoan." << endl;
    }
}

//Nhan vien
    void TaoTKNV() {
        int ID;
        string Hoten, Ngaysinh, SDT, Email, TenTK, MK, Vitri;
        double Luong;
        cout << "Nhap ID: ";
        cin >> ID;
        cout << "Nhap Ho ten: ";
        cin.ignore();
        getline(cin, Hoten);
        cout << "Nhap Ngay sinh: ";
        getline(cin, Ngaysinh);
        cout << "Nhap SDT: ";
        getline(cin, SDT);
        cout << "Nhap Email: ";
        getline(cin, Email);
        cout << "Nhap Ten tai khoan: ";
        getline(cin, TenTK);
        cout << "Nhap Mat khau: ";
        getline(cin, MK);
        cout << "Nhap Vi tri: ";
        getline(cin, Vitri);
        cout << "Nhap Luong: ";
        cin >> Luong;

        NhanVien newNV(ID, Hoten, Ngaysinh, SDT, Email, TenTK, MK, Vitri, Luong);
        NV.push_back(newNV);
        cout << "Tao tai khoan khach hang thanh cong." << endl;
    }

    void KiemtraTKNV() {
        int ID;
        cout << "Nhap ID tai khoan can kiem tra: ";
    	cin >> ID;

    	bool found = false;
    	for (size_t i = 0; i < NV.size(); ++i) {
        	if (NV[i].getID() == ID) {
            	found = true;
            	cout << "Thong tin tai khoan:" << endl;
            	cout << "Ho ten: " << NV[i].getHoten() << endl;
            	cout << "Ngay sinh: " << NV[i].getNgaysinh() << endl;
            	cout << "SDT: " << NV[i].getSDT() << endl;
            	cout << "Email: " << NV[i].getEmail() << endl;
            	cout << "Ten tai khoan: " << NV[i].getTenTK() << endl;
            	cout << "Vi tri: " << NV[i].getVitri() << endl;
            	cout << "So tien: " << NV[i].getLuong() << endl;
            	break;
        }
    }

    if (!found) {
        cout << "Khong tim thay tai khoan co ID " << ID << endl;
    }
    }

    void XoaTKNV() {
        int ID;
    	cout << "Nhap ID tai khoan can xoa: ";
    	cin >> ID;

    	bool found = false;
    	for (size_t i = 0; i < NV.size(); ++i) {
        	if (NV[i].getID() == ID) {
            	found = true;
            	NV.erase(NV.begin() + i);
            	cout << "Xoa tai khoan thanh cong." << endl;
            	break; 
        	}
    	}

    	if (!found) {
        	cout << "Khong tim thay tai khoan co ID " << ID << endl;
    	}
    }

    void XemdsNV() {
        cout << "Danh sach nhan vien:" << endl;
		cout << setw(5) << "ID" << setw(20) << "Ho ten" << setw(15) << "Ngay sinh" << setw(15) << "SDT"
     		 << setw(20) << "Email" << setw(15) << "Ten tai khoan" << setw(10) << "Vi tri" << setw(10) << "Luong" << endl;
		cout << setfill('-') << setw(115) << "" << setfill(' ') << endl;

		for (size_t i = 0; i < NV.size(); ++i) {
    		cout << setw(5) << NV[i].getID() << setw(20) << NV[i].getHoten() << setw(15) << NV[i].getNgaysinh()
         	 	 << setw(15) << NV[i].getSDT() << setw(20) << NV[i].getEmail() << setw(15) << NV[i].getTenTK()
         	 	 << setw(10) << NV[i].getVitri() << setw(10) << NV[i].getLuong() << endl;
		}
};
};

int main() {
    Bank bank;
	hienthi();
    int choice;
    do {
        cout << "\t\t************ BANK MANAGEMENT SYSTEM ************"<<endl;
		cout <<"\n1 - KHACH HANG" << "\t\t  " << " 2 - NHAN VIEN" <<endl;
		cout <<"\t\t3 - THOAT" <<endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.quanliKH();
                break;
            case 2:
                bank.quanliNV();
                break;
            case 3:
                cout << "\n\n\t\t************ Thank You..!! ************" << endl;
                break;
            default:
                cout << "Khong hop le" << endl;
        }
    } while (choice != 3);

    return 0;
}
