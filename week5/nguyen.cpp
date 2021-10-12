#include <iostream>
using namespace std;

class thoigian {
private:
    int ngay;
    int gio;
public:
    thoigian() {
        ngay = 0;
        gio = 0;
    }

    thoigian(int ngay, int gio) {
        this->ngay = ngay;
        this->gio = gio;
        this->rutgon();
    }

    void nhapbp() {
        int ngay, gio;
        cin >> ngay >> gio;
        this->ngay = ngay;
        this->gio = gio;    
        this->rutgon();
    }

    void xemmh() {
        cout << ngay << " ngay, " << gio << " gio";
    }

    void rutgon() {
        while (gio >= 24) {
            ngay++;
            gio -= 24;
        }
    }

    friend thoigian operator +(thoigian a, thoigian b) {
        thoigian c;
        c.ngay = a.ngay + b.ngay;
        c.gio = a.gio + b.gio;
        c.rutgon();
        return c;
    }   

    friend thoigian operator -(thoigian a, thoigian b) {
        thoigian c;
        c.ngay = a.ngay - b.ngay;
        c.gio = a.gio - b.gio;
        c.rutgon();
        return c;
    }

    thoigian operator *(int a) {
        thoigian c;
        c.ngay = ngay * a;
        c.gio = gio * a;
        c.rutgon();
        return c;
    }

    thoigian operator /(int a) {
        thoigian c;
        c.ngay = ngay / a;
        c.gio = gio / a;
        c.rutgon();
        return c;
    }

    thoigian(const char *c) {
        int ngay = 0;
        int gio = 0;
        int i = 0;
        while (c[i] != ' ') {
            if (c[i] >= '0' && c[i] <= '9') {
                ngay = ngay * 10 + c[i] - '0';
            }
            i++;
        }
        i++;
        while (c[i] != ' ') {
            if (c[i] >= '0' && c[i] <= '9') {
                gio = gio * 10 + c[i] - '0';
            }
            i++;
        }
        this->ngay = ngay;
        this->gio = gio;
        this->rutgon();
    }
    
};

int main() {
    thoigian a;
    a = thoigian("2ngay 40gio");
    thoigian b(2, 40);
    thoigian c = a + b;
    a.xemmh();
    cout << endl;
    b.xemmh();
    cout << endl;
    c.xemmh();

    return 0;
}