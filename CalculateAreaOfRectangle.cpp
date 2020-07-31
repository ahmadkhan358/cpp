#include<iostream>

class calculate_area { //this class will calculate the area of rectangle
private:
	float length, width, area;
public:
	calculate_area() { //Constructor for initialization of variables 
		length = 0.0;
		width = 0.0;
		area = 0.0;
	}

	void get_values() {
		std::cout << "Enter length of rectangle" << std::endl;
		std::cin >> length;
		std::cout << "Enter width of rectangle" << std::endl;
		std::cin >> width;
	}

	void area_calculation() {
		area = length * width;
	}

	void display_area() {
		std::cout << "Area of rectangle is " << area << std::endl;
	}
};

int main() {
	calculate_area obj; //object of class "calculate_area"
	obj.get_values(); //to get length and width from user
	obj.area_calculation(); //to calculate the area
	obj.display_area(); //to display the calculated area
	system("pause");
	return 0;
}