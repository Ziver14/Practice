#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>

void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

void fill_arr(int arr[], const int length, int left, int right) {
	if (left > right)
		std::swap(left, right);
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (right - left) + left;
	}
}
template<typename T>

void clear_arr(T arr[], const int length, T key) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == key)
			arr[i] = 0;
	}

}

int index_sum(int arr[], int arr_1[], const int length, const int length1, int key) {
	if (key >= length || key >= length1||key<0){
		std::cout << "ERROR"<<'\n';
		return 0;
	}
	return arr[key] + arr_1[key];
}
int compare_pare(int arr[], const int length, int num1, int num2) {
	for (int i = 0; i < length-1; i++) {
		if (arr[i] == num1 && arr[i + 1] == num2)
			return i;
	}
	return -1;

}

void prime_range(int num1, int num2) {
	for (int j = num1; j <= num2; j++) {
		int counter = 1;
		for (int i = 1; i <= j / 2; i++)
			if (j % i == 0)
				counter++;
		if (counter == 2)
			std::cout << j << '\n';
	}
}
void prime_range(int num1) {
	for (int j = 1; j <= num1; j++) {
		int counter = 1;
		for (int i = 1; i <= j / 2; i++)
			if (j % i == 0)
				counter++;
		if (counter == 2)
			std::cout << j << '\n';

	}
}


template<typename T>
void permute_arr(T arr[], const int length) {
	if(length%2!=0)
		for (int i = 0; i < length / 2; i++)
			std::swap(arr[i], arr[i + length/2+1]);
	else
		for (int i = 0; i < length / 2; i++)
			std::swap(arr[i], arr[i + length / 2]);

}



int main() {
	setlocale(LC_ALL, "ru");
	int n, m;
	const int size = 10;
	int arr[size]{};
	const int size_1 = 12;
	int arr_1[size_1]{};
	std::cout << "Изначальный массив->\n";
	fill_arr(arr, size, 5, 30);
	print_arr(arr, size);
	//Задача 1.
	std::cout << "Введите число-> ";
	std::cin >> n;
	clear_arr(arr, size, n);
	std::cout << "Измененный массив->";
	print_arr(arr, size);
	std::cout << "\n\n";
	//Задача 2.
	std::cout << "Первый массив\n";
	fill_arr(arr, size, 5, 30);
	print_arr(arr, size);
	std::cout << "Второй массив\n";
	fill_arr(arr_1, size_1, 9, 15);
	print_arr(arr_1, size_1);
	std::cout << " Введите индекс->";
	std::cin >> n;
	std::cout << index_sum(arr,arr_1,size,size_1,n);
	std::cout << "\n\n";
	//Задача 3.
	std::cout << "Изначальный массив->\n";
	fill_arr(arr, size, 5, 30);
	print_arr(arr, size);
	std::cout << "Введите числа-> ";
	std::cin >> n >> m;
	std::cout << compare_pare(arr,size,n,m);
	std::cout << "\n\n";
	
	//Задача 4.
	
	prime_range(10,30);
	std::cout << "\n\n";
	
	//Задача 5.
	const int size3 = 7;
	int arr3[size]{ 1,2,3,4,5,6,7 };
	print_arr(arr3, size3);
	permute_arr(arr3, size3);
	print_arr(arr3, size3);

	





	return 0;
}

