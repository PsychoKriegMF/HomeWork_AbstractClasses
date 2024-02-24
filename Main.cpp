#include <iostream>
#include <string>
#include <vector>

class Harvest {               // создаем класс плода
public:
	Harvest (std::string name, std::string color, double weight) : name_(name), color_(color), weight(weight){}
	// виртуальные мутоды доступа 
	virtual std::string getName() const
	{
		return name_;
	}
	virtual std::string getColor_() const
	{
		return color_;
	}
	virtual double getWeight() const 
	{
		return weight;
	}

private:
	std::string name_;
	std::string color_;
	double weight;
};

class Plants {                 // класс деревьев
public:
	Plants (std::string name, std::string size, std::string color, int maxHarvest) : name_(name), size_(size), color_(color), maxHarvest(maxHarvest){}

	virtual std::string getName() const
	{
		return name_;
	}
	virtual std::string getSize() const 
	{
		return size_;
	}
	virtual std::string getColor() const 
	{
		return color_;
	}
	virtual int getMaxHarvest() const
	{
		return maxHarvest;
	}
	virtual Harvest* getHarvest() = 0;

private:
	std::string name_;
	std::string size_;
	std::string color_;
	int maxHarvest;
};


class AppleTree : public Plants {         // создаем дерево с плодами 
public:
	AppleTree() : Plants("Яблоня","средний", "зеленый", 200){}

	Harvest* getHarvest() override
	{
		return new Harvest("яблоко", "желтое", 0.1);
	}
};

class RaspberryBush : public Plants {
public:
	RaspberryBush() : Plants("Куст малины","маленький", "зеленый", 100) {}

	Harvest* getHarvest() override 
	{
		return new Harvest("малина", "красный", 0.05);
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	std::vector <Plants*> garden;          // создаем массив "Огород"

	garden.push_back(new AppleTree());     // добавляем в огород яблоню 
	garden.push_back(new RaspberryBush()); // и куст малины

	for (auto plant : garden)              // выводим все значения деревьев и плодов в нашем огороде
	{
		Harvest* harvest = plant->getHarvest();
		std::cout << "Название дерева: " << plant->getName() << std::endl;
		std::cout << "Размер дерева: " << plant->getSize() << std::endl;
		std::cout << "Цвет дерева: " << plant->getColor() << std::endl;
		std::cout << "Максимальное кол-во плодов: " << plant->getMaxHarvest() << std::endl;
		std::cout << "Название плода: " << harvest->getName() << std::endl;
		std::cout << "Цвет плода:" << harvest->getColor_() << std::endl; 
		std::cout << "Вес плода: " << harvest->getWeight() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;



	





	return 0;
}