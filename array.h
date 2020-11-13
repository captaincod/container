const int DEFAULT_CAPACITY = 10;
class Array
{
	//Конструктор
	explicit Array(int startCapacity = DEFAULT_CAPACITY);
	//Деструктор
	~Array();

	//Конструктор копирования
	Array(const Array& arr);
	//Оператор присваивания
	Array& operator =(const Array& arr);
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
	// Вывод массива в поток
	int getSize() const;
	friend ostream& operator <<(ostream& out,
		const Array& arr);
};

class ArrayException {};