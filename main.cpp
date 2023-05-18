#include <iostream>
#include <map>
#include <functional>
using namespace std;

void ejemplo_map() {
    map<int, string> m1 = { {2, "Dos"},  {9, "Nueve"},  {1, "Uno"},  {7, "Siete"}};

    for (const auto& item: m1) {
        cout << item.first << " " << item.second << endl;
    }

    map<int, string, greater<>> m2(greater<>{});
    m2.insert({2, "Dos"});
    m2.insert({9, "Nueve"});
    m2.insert({1, "Uno"});
    m2.insert({7, "Siete"});

    cout << "-----------" << endl;
    for (const auto& item: m2) {
        cout << item.first << " " << item.second << endl;
    }

    auto mayor = [](auto a, auto b) { return a > b; };
    map<int, string, function<bool(int, int)>> m3(mayor);
    m3.insert({2, "Dos"});
    m3.insert({9, "Nueve"});
    m3.insert({1, "Uno"});
    m3.insert({7, "Siete"});

    cout << "-----------" << endl;
    for (const auto& item: m3) {
        cout << item.first << " " << item.second << endl;
    }

    auto menor = [](auto a, auto b) { return a < b; };
    map<int, string, decltype(menor)> m4(menor);
    m4.insert({2, "Dos"});
    m4.insert({9, "Nueve"});
    m4.insert({1, "Uno"});
    m4.insert({7, "Siete"});

    cout << "-----------" << endl;
    for (const auto& item: m4) {
        cout << item.first << " " << item.second << endl;
    }
}

class Persona {
    string nombre;
public:
    explicit Persona(string nombre): nombre(std::move(nombre)) {}
    friend ostream& operator<<(ostream& out, const Persona& p) {
        out << p.nombre;
        return out;
    }
    friend bool nombre_mayor(const Persona& a, const Persona& b);
    string get_nombre() { return nombre; }
};

bool nombre_mayor(const Persona& a, const Persona& b) {
    return a.nombre > b.nombre;
}
void ejemplo_map_objectos() {
    map<Persona, string, function<bool(const Persona&, const Persona&)>>
    m1({  {Persona{"Jose"}, "Jose"},
            {Persona{"Juan"}, "Juan"},
            {Persona{"Mateo"}, "Mateo"},
            {Persona{"Abraham"},"Abraham"} }, nombre_mayor);

    for (const auto& item: m1) {
        cout << item.first << " " << item.second << endl;
    }

    auto comparar_nayor = [](auto a, auto b) {
        return a.get_nombre() > b.get_nombre(); };
    map<Persona, string, decltype(comparar_nayor)>
            m2({  {Persona{"Jose"}, "Jose"},
                  {Persona{"Juan"}, "Juan"},
                  {Persona{"Mateo"}, "Mateo"},
                  {Persona{"Abraham"},"Abraham"} }, comparar_nayor);
    for (const auto& item: m2) {
        cout << item.first << " " << item.second << endl;
    }

}

int main() {
//    ejemplo_map();
    ejemplo_map_objectos();
    return 0;
}
