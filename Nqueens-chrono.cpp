#include <iostream>
#include <vector>

using namespace std;

#include <chrono>

using namespace std::chrono;

int main() {
    int N;
    cout << "Ingresar valor de N:";
    cin >> N;
    if (N < 4) {
        return 0;
    }
    auto comenzar = high_resolution_clock::now();
    vector<int> pares;
    vector<int> impares;

    for (int i = 2; i <= N; i = i + 2) {
        pares.push_back(i);
        impares.push_back(i - 1);
    }
    if (N % 2 == 1) {
        impares.push_back(N);
    }

    int r = N % 6;

    if (r != 2 && r != 3) {
        for (int par : pares) {
            cout << par << " ";
        }
        for (int impar : impares) {
            cout << impar << " ";
        }
    }

    if (r == 2) {
        swap(impares[0], impares[1]); //permutamos el 1 y el 3
        for (int i = 2; i < impares.size() - 1; i++) {
            swap(impares[i], impares[i + 1]);
        } //el impares[2] = 5, avanza al ritmo de i

        for (int par : pares) {
            cout << par << " ";
        }
        for (int impar : impares) {
            cout << impar << " ";
        }
    }

    if (r == 3) {
        pares.push_back(2);
        pares.erase(pares.begin());
        for (int par : pares) {
            cout << par << " ";
        }
        impares.push_back(1);
        impares.erase(impares.begin());
        impares.push_back(3);
        impares.erase(impares.begin());
        for (int impar : impares) {
            cout << impar << " ";
        }
    }

    auto detener = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(detener - comenzar);
    cout << endl << duration.count() << " microsegundos" << endl;

    return 0;
}
