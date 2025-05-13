# linalg

## Сборка
```bash
cmake -B build
cmake --build build --config Release  
```

## Собранные файлы
- `build/Release/linalg.dll` - динамическая библиотека
- `build/Release/linalg.lib` - статическая библиотека

## Пример использования
```cpp
#include <linalg.hpp>
#include <iostream>
#include <iomanip>

int main() {
    linalg::SLEGenerator sleg;
    auto [A, b] = sleg.random(5, /* size */ {-100, 100} /* matrix A values distribution */, {-50, 50} /* vector b values distribution */);


    std::cout << "Matrix A (" << A.rows() << "x" << A.cols() << "):" << std::endl;
    for (int i = 0; i < A.rows(); ++i) {
        for (int j = 0; j < A.cols(); ++j) {
            std::cout << std::setw(10) <<  A(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    

    std::cout << "Vector b (" << b.size() << " elements):" << std::endl;
    for (int i = 0; i < b.size(); ++i) {
        std::cout << std::setw(10) <<  b(i) << " ";
    }
    std::cout << std::endl << std::endl;


    linalg::Gauss gauss;
    linalg::Vector x = gauss.solve(A, b);


    std::cout << "Solution vector x (" << x.size() << " elements):" << std::endl;
    for (int i = 0; i < x.size(); ++i) {
        std::cout << std::setw(10) <<  x(i) << " ";
    }
    std::cout << std::endl;


    return 0;
}
```

```
Matrix A (5x5):
   4.32328   -81.8329    3.01636   -50.1378     33.087
   86.8877   -26.3121    45.5409    -81.406    8.12648
  -30.1907    26.8914   -45.1581   -18.0672   -74.3081
  -57.3565   -36.7017   -13.5705    55.1417    93.6392
  -92.1574   -41.8557    3.86749    66.2953   -95.2173

Vector b (5 elements):
  -44.4653   -43.6858   -17.3658    27.5284    36.1888

Solution vector x (5 elements):
 -0.380344   0.369889    0.57754   0.342979  0.0877179
```