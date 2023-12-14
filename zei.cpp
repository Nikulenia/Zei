//метод Зейделя, без ввода своих значений.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int n = 5;
    const float eps = 0.0001;
    int iter = 0;

    vector<vector<double>> matrix = {
    {36, 5, 5, 1, 5, 68},
    {5, 22, 3, 3, 1, 65},
    {3, 3, 44, 3, 3, 150},
    {5, 4, 5, 39, 3, 109},
    {3, 2, 5, 3, 48, 76}
    };
    vector<double> x_old{ 0,0,0,0,0 };
    vector<double> x_new{ 0,0,0,0,0 };

    bool flag = true;
    while (true) {
        flag = true;
        iter++;
        for (int k = 0; k < n; k++) {
            x_new[k] = matrix[k][5];
            for (int j = 0; j < n; j++)
                if (j != k)
                    x_new[k] = x_new[k] - matrix[k][j] * x_new[j];
            x_new[k] = x_new[k] / matrix[k][k];
            if (abs(x_new[k] - x_old[k]) < eps)
                flag = false;

        }
        cout << "Iteracia: " << iter << ";    ";
        for (int i = 0; i < n; i++)
            cout << x_new[i] << "   ";
        cout << "\n";
        for (int i = 0; i < n; i++)
            x_old[i] = x_new[i];
        if (flag == false)
            break;
    }
}
