//#include <iostream>
//double simpson_rule(double (*f)(double), double a, double b, int n) {
//	if (n % 2 == 1) n++; // Делаем n четным
//	double h = (b - a) / n;
//	double sum = f(a) + f(b);
//	for (int i = 1; i < n; i += 2)
//		sum += 4 * f(a + i * h);
//	for (int i = 2; i < n - 1; i += 2)
//		sum += 2 * f(a + i * h);
//	return (h / 3) * sum;
//}
//double function(double x) {
//	return 2*x; // Интегрируемая функция
//}
//int main() {
//	setlocale(LC_ALL, "RU");
//	double result = simpson_rule(function, 3, 6, 1);
//	std::cout << "Приближенное значение интеграла: " << result << std::endl;
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//double monte_carlo_circle_area(double radius, int num_points = 10000) {
//	int inside_points = 0;
//	for (int i = 0; i < num_points; ++i) {
//		double x = ((double)rand() / RAND_MAX) * 2 * radius - radius;
//		double y = ((double)rand() / RAND_MAX) * 2 * radius - radius;
//		if (x * x + y * y <= radius * radius) {
//			inside_points++;
//		}
//	}
//	// Площадь квадрата, в который вписан круг = (2*radius)^2
//	double square_area = (2 * radius) * (2 * radius);
//	double circle_area = (inside_points / (double)num_points) * square_area;
//	return circle_area;
//}
//int main() {
//	srand(time(0)); // Инициализация генератора случайных чисел
//	double radius = 5;
//	double estimated_area = monte_carlo_circle_area(radius);
//	std::cout << "Оцененная площадь круга с радиусом " << radius << ": " <<
//		estimated_area << std::endl;
//	return 0;
//}
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