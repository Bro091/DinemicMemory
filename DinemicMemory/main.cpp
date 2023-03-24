
#include <iostream>
#include <cstdlib>
#include <ctime>

void arr_add(int*& arr, int length, int num) {    // � �� ����� ������ ��������� �������, � �� ������ int // ��������� �������� ������ ������ (������ �� ��������� �� int)
	if (num <= 0)
		return;
	int* tmp = new int[length + num]{};
	for (int i = 0; i < length; i++)  // length ������ ��� �������� ����� ������������ �������, ��� �������� � ���������
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}  



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// ������������ ������ (��)
	/*int* pointer = new int; // ����������� ��������� �� ������������ ������� ������������ ������ �������� � 4 ����� (�.�. int)
	*pointer = 15; // ������ � �� ����� 15
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;


	delete pointer; // ������������ (�������) ������� �� �� ������� ��������� ���������. ���������� �� ��������� ������ ������

	pointer = new int; // ��������� ������ ������� ��
	std::cout << "pointer = " << pointer << std::endl;
	*pointer = 7;
	std::cout << "*pointer = " << *pointer << std::endl;

	delete pointer;  // � ����� ������ ����������, �� �������� "�������� ����" ����� ������ delete */

	// ������������ �������
	/*std::cout << "������� ������ ������� -> ";
	int size;
	std::cin >> size;

	int* d_arr = new int[size]; //��������� �������� �� ��� �-������� �������
	
	std::cout << "���� �������:\n";
	for (int i = 0; i < size; i++) {
		std::cout << "������� " << i + 1 << "-� ������� -> ";
		std::cin >> d_arr[i];
	}

	std::cout << "�������� ������:\n";
	for (int i = 0; i < size; i++)
		std::cout << d_arr[i] << ' ';
	std::cout << std::endl;

	delete[] d_arr; // ��� ���� ��� �� delete ������ ��� �������� ������� � ��������� delete ��������� []*/

	// ��������� ������������ ������
	/*int rows, cols;
	std::cout << "������� ������� ���������� ������� -> ";
	std::cin >> rows >> cols;
	// int* mx = new int[rows][cols]; // �� ��������

	int** mx = new int* [rows];       // ��������
	for (int i = 0; i < rows; i++)    // ���������� �������������
		mx[i] = new[cols];            // �������   


	// ������������� ������� ����� ����� ��, ��� � � ������������


	//������������ ������
	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[] mx;*/

	// ������ 1. ���������� �������
	std::cout << "������ 1.\n������� ������ ������� -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	srand(time(NULL));
	std::cout << "����������� ������:\n[";
	for (int i = 0; i < size1; i++) {
		arr1[i] = rand() % (11) + 10; // [10...20]
		std::cout << arr1[i] << ", ";
	}
	std::cout << "\b\b]\n << ������� ���������� ����� ��������� -> ";
	std::cin >> n;

	arr_add(arr1, size1, n);
	size1 += n;

	std::cout << "�������� ������:\n";
	for (int i = 0; i < size1; i++)
		std::cout << arr1[i] << ", ";
	std::cout << "\b\b]\n";




	return 0;

}