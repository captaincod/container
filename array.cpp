#include <iostream>
#include "array.h"
using namespace std;

class Array
{
	// Указатель на массив в динамич. памяти
	int* ptr;
	// Текущий размер
	int size;
	// Вместимость
	int capacity;
	bool isFail;

public:
	bool fail();
	//Конструктор
	explicit Array(int startCapacity = DEFAULT_CAPACITY);
	//Деструктор
	~Array();

	//Конструктор копирования
	Array(const Array& arr);	//Оператор присваивания	Array& operator =(const Array& arr);
	int& operator [](int index);

	//Функция вставки элемента
	void insert(int index, int elem);
	//Вставка элемента в конец массива
	void insert(int elem);
	//Увеличение предельного размера
	void increaseCapacity(int newCapacity);
	// Удаление элемента
	void remove(int index);
	// Получение размера
	int getSize() const;
	// Вывод массива в поток
	friend ostream& operator <<(ostream& out,
		const Array& arr);
};

//КонструкторArray::Array(int startCapacity)
{
	if (startCapacity <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = startCapacity;
	ptr = new int[capacity];
	size = 0;
}

//Деструктор
Array::~Array()
{
	delete[] ptr;
}

//Конструктор копирования
Array::Array(const Array& arr)
{
	ptr = new int[arr.capacity];
	size = arr.size;
	capacity = arr.capacity;
	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
}

//Оператор присваивания
Array& Array::operator =(const Array& arr)
{
	if (this == &arr)
		return *this;
	if (capacity != arr.capacity)
	{
		delete[] ptr;
		ptr = new int[arr.capacity];
		capacity = arr.capacity;
	}
	size = arr.size;
	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
	return *this;
}//Реализация оператора индексацииint& Array::operator [](int index)
{
	// Индекс должен быть в пределах 0…size-1
	// При таком подходе нельзя обратиться к элементу, который еще не был создан операцией вставки
	if (index >= size || index < 0)
		// ???
		;
	else
		return ptr[index];
}//Исключенияint& Array::operator [](int index)
{
	if (index >= size || index < 0)
		throw ArrayException();
	else
		return ptr[index];
}//Функция вставки элементаvoid Array::insert(int elem, int index)
{
	if (index < 0 || index > size)
		throw ArrayException();
	if (size == capacity)
		// Закрытая функция, увеличивающая предельный размер
		increaseCapacity(size + 1);
	// Если index==size, этот цикл не выполнится ни разу
	for (int j = size - 1; j >= index; j--)
		ptr[j + 1] = ptr[j];
	size++;
	ptr[index] = elem;
}

//Вставка элемента в конец массива
void Array::insert(int elem)
{
	insert(elem, size);
}//Увеличение предельного размераvoid Array::increaseCapacity(int newCapacity) {
	capacity = newCapacity < capacity * 2 ?
		capacity * 2 : newCapacity;
	int* newPtr = new int[capacity];
	for (int i = 0; i < size; i++)
		newPtr[i] = ptr[i];
	delete[] ptr;
	ptr = newPtr;
}// Удаление элементаvoid Array::remove(int index)
{
	if (index < 0 || index >= size)
		throw ArrayException();
	for (int j = index; j < size - 1; j++)
		ptr[j] = ptr[j + 1];
	ptr[size - 1] = 0;
	size--;
}// Получение размераint Array::getSize() const
{
	return size;
}

// Вывод массива в поток
ostream& operator <<(ostream& out,
	const Array& arr)
{
	out << "Total size: " << arr.size << endl;
	for (int i = 0; i < arr.size; i++)
		out << arr.ptr[i] << endl;
	return out;
}bool Array::fail()
{
	return false;
}
