
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

std::vector<int> num = { 10, 20, 100, 1000, 2000, 5000, 10000, 10000, 1000000, 10000000 };


double monte_carlo(double x1, double x2, int num_points) {
    int inside_points = 0;

    double y1 = -x2; 
    double y2 = x2;  

    for (int i = 0; i < num_points; ++i) {
        double x = x1 + ((double)rand() / RAND_MAX) * (x2 - x1);
        double y = y1 + ((double)rand() / RAND_MAX) * (y2 - y1);

        if (y >= -x && y <= x) {
            inside_points++;
        }
    }

    double rect_area = (x2 - x1) * (y2 - y1);

    double trapez_area = (inside_points / (double)num_points) * rect_area;

    return trapez_area;
}

int main() {

    setlocale(LC_ALL, "RU");

    srand(time(0)); // Инициализация генератора случайных чисел

    double x1 = 3;
    double x2 = 6;
    for (int i : num) {

        double  result = monte_carlo(x1, x2, i);

        std::cout << "Численное значение интеграла: " << result << std::endl;
    }


    return 0;

}
