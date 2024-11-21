#include <cstring>
#include <ostream>
#include <string>
#include <iostream>


using namespace std;

class Autobuz {
private:
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:
    //constructor fara parametri 
    Autobuz() : idAutobuz(nrAutobuze++), capacitate(0), nrPersoaneImbarcate(0), producator(nullptr) {}

    //constr cu parametri
    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(nrAutobuze++) {
        if (capacitate > 0) {
            this->capacitate = capacitate;
        }
        else {
            this->capacitate = 0;
        }
        if (nrPersoaneImbarcate >= 0 && nrPersoaneImbarcate <= capacitate) {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
        else {
            this->nrPersoaneImbarcate = 0;
        }
        if (producator != nullptr) {
            this->producator = new char[strlen(producator) + 1];
            strcpy_s(this->producator, strlen(producator) + 1, producator);
        }
        else {
            this->producator = nullptr;
        }
    }

    //Destructor 
    ~Autobuz() {
        if (producator) {
            delete[] producator;
        }
    }
            
        
    Autobuz(const Autobuz& a) : idAutobuz(nrAutobuze++) {
       capacitate = a.capacitate;
       nrPersoaneImbarcate = a.nrPersoaneImbarcate;
       producator = new char[strlen(a.producator) + 1];
       strcpy_s(producator, strlen(a.producator) + 1, a.producator);
		}
    Autobuz& operator=(const Autobuz& a) {
        if (this != &a) {
            this->capacitate = a.capacitate;
            this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
            if (this->producator) {
                delete[] this->producator;
            }
            if (a.producator != nullptr) {

                this->producator = new char[strlen(a.producator) + 1];
                strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
            }
            else {
                this->producator = nullptr;
            }
        }
        return *this;

}

    // Operator << pentru afiasre
    friend ostream& operator<<(ostream& out, const Autobuz& a) {
        out << "Id autobuz: " << a.idAutobuz << "; Capacitate: " << a.capacitate << "; Nr persoane imbarcate: " << a.nrPersoaneImbarcate << "; Producator: " << a.producator;
        return out;
    }

    //Metode accesor
    int getCapacitate() const {
        return capacitate;
    }

    void setCapacitate(int capacitate) {
        if (capacitate > 0) {
            this->capacitate = capacitate;
        }
    }

    int getNrPersoaneImbarcate() const {
        return nrPersoaneImbarcate;
    }

    void setNrPersoaneImbarcate(int nrPersoaneImbarcate) {
        if (nrPersoaneImbarcate >= 0 && nrPersoaneImbarcate <= capacitate) {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
    }

    // Metoda get numar de locuri libere
    int getNumarLocuriLibere() const {
        return capacitate - nrPersoaneImbarcate;
    }

    //Metoda de cast la int 
    operator int() const {
        return nrPersoaneImbarcate;
    }

    //Operator pentru comparare
    bool operator>(const Autobuz& a) const {
        return this->capacitate > a.capacitate;
    }
};

int Autobuz::nrAutobuze = 0;

int main() {
    Autobuz a1;
    Autobuz a2(30, 25, "Ford");
    Autobuz a3 = a2;

    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;

    a1 = a2;
    cout << a1 << endl;

    cout << "Numarul de locuri libere in autobuzul a2: " << a2.getNumarLocuriLibere() << endl;
    cout << "Nr persoane imbarcate in autobuzul a2: " << (int)a2 << endl;

    if (a2 > a1) {
        cout << "Autobuzul a2 are o capacitate mai mare decat autobuzul a1" << endl;
    } else {
        cout << "Autobuzul a1 are o capacitate mai mare decat autobuzul a2" << endl;
    }

    return 0;
}
