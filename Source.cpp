#include<iostream>
#include"BinaryTree.h"

template <typename T>
void ShowValue(const T& value) {
	std::cout << value << " ";
}

template <typename T>
void Show(const BinaryTree<T>& tree) {
	std::cout << "Tree elements: ";
	tree.DoForAllElements(ShowValue<T>);
	std::cout << "\n";
}

class Sum {
private:
	static double sum;

public:
	static void add(double other) {
		sum += other;
	}
	static double getSum() {
		return sum;
	}
};
double Sum::sum = 0;

void Add(Sum &sum,double value) {
	sum.add(value);
}

int main() {
	BinaryTree<double>tree{ 1,8,4,2,6,4,7,3,0};

	BinaryTree<double>tree2(tree);

	std::cout << "tree2:\n";
	tree2.DoForAllElements(ShowValue<double>);
	std::cout << "\n";
	
	Show(tree2);

	tree2.DoForAllElements(Sum::add);
	
	std::cout << Sum::getSum()<<"\n";


	double sum = 0;

	tree2.DoForAllElements([&sum](double value) {sum += value; });

	std::cout << sum << "\n";
}