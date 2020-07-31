#include<iostream>
using namespace std;
class swimmingPool {
private:
	double width;
	double height;
	double depth;
	double Filling;
	double draining;
public:
	swimmingPool() {
		width = 0.0;
		height = 0.0;
		depth = 0.0;
		Filling = 0.0;
		draining = 0.0;
	}
	swimmingPool(double w, double h, double d) {
		width = w;
		height = h;
		depth = d;
		cout << "If width if pool is " << width << " height is " << height << " and depth is " << depth << endl;
	}
	void fillpool() {
		double temp;
		Filling = (width * height)*depth;
		temp = Filling * 7.5;//to convert into gallons from cubic feet
		cout << "The water needed to fill a fully empty pool is " << temp << " gallons" << endl;
		cout << "The water needed to fill a partially empty pool is " << temp / 2 << " gallons" << endl;
	}
	void calctime() {
		double time;
		double temp;
		Filling = (width*height)*depth;
		temp = Filling * 7.5;//to convert into gallons from cubic feet
		//if 40 gallons water is filled/drained in 1 minute then
		time = temp / 40;
		cout << "In " << time << " minutes the pool is fully filled or drained" << endl;
		cout << "In " << time / 2 << " minutes the pool is partially filled of drained" << endl;
	}
	void addDrain(double time) { //in minutes
		//if 40 gallons water is filled/drained in 1 minute then
		double temp = time * 40;
		cout << temp << " gallons of water is drained in " << time << " minutes" << endl;
	}
};
int main() {
	swimmingPool sp(12, 12, 12);
	sp.fillpool();
	sp.calctime();
	sp.addDrain(20);
	system("pause");
	return 0;
}