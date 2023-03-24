
#include <iostream>
#include <cstdlib>
#include <ctime>

void arr_add(int*& arr, int length, int num) {    // в ДЗ лучше делать шаблонные функции, а не просто int // перемнная читается справа налево (ссылка на указатель на int)
	if (num <= 0)
		return;
	int* tmp = new int[length + num]{};
	for (int i = 0; i < length; i++)  // length потому что береться длина изначального массива, чьи элементы м ыкопируем
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}  



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Динамическая память (ДП)
	/*int* pointer = new int; // направление указателя на произвольный участок динамической памати размером в 4 байта (т.к. int)
	*pointer = 15; // запись в ДП числа 15
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;


	delete pointer; // освобождение (очистка) области ДП на которую направлен указатель. Необходимо во избежание утечки памяти

	pointer = new int; // выделение нового участка ДП
	std::cout << "pointer = " << pointer << std::endl;
	*pointer = 7;
	std::cout << "*pointer = " << *pointer << std::endl;

	delete pointer;  // в конце работы указателей, по правилам "хорошего тона" нужно писать delete */

	// Динамические массивы
	/*std::cout << "Введите размер массива -> ";
	int size;
	std::cin >> size;

	int* d_arr = new int[size]; //синтаксис создания ДП для х-ранения массива
	
	std::cout << "Ввод массива:\n";
	for (int i = 0; i < size; i++) {
		std::cout << "Введите " << i + 1 << "-й элемент -> ";
		std::cin >> d_arr[i];
	}

	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < size; i++)
		std::cout << d_arr[i] << ' ';
	std::cout << std::endl;

	delete[] d_arr; // для того что бы delete удалил все элементы массива к оператору delete добавляем []*/

	// Двумерный динамический массив
	/*int rows, cols;
	std::cout << "Введите размеры двумерного массива -> ";
	std::cin >> rows >> cols;
	// int* mx = new int[rows][cols]; // не работает

	int** mx = new int* [rows];       // создание
	for (int i = 0; i < rows; i++)    // двумерного динамического
		mx[i] = new[cols];            // массива   


	// использование массива точно такое же, как и у статического


	//Освобождение памати
	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[] mx;*/

	// Задача 1. Увеличение массива
	std::cout << "Задача 1.\nВведите размер массива -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	srand(time(NULL));
	std::cout << "Изначальный массив:\n[";
	for (int i = 0; i < size1; i++) {
		arr1[i] = rand() % (11) + 10; // [10...20]
		std::cout << arr1[i] << ", ";
	}
	std::cout << "\b\b]\n << Введите количество новых элементов -> ";
	std::cin >> n;

	arr_add(arr1, size1, n);
	size1 += n;

	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < size1; i++)
		std::cout << arr1[i] << ", ";
	std::cout << "\b\b]\n";




	return 0;

}