#include <iostream>
using namespace std;

struct Car {
private:
	double _length, _engine_displacement;
	int _clearance, _engine_power, _wheel_diameter;
	string _color, _gearbox_type;

public:
	Car() {
		_length = 1;
		_clearance = 5;
		_engine_displacement = 1;
		_engine_power = 100;
		_wheel_diameter = 10;
		_color = "white";
		_gearbox_type = "auto";
	}
	Car(double length) : Car() {
		setLength(length);
	}
	Car(double length, int clearance) : Car(length) {
		setClearance(clearance);
	}
	Car(double length, int clearance, 
		double engine_displacement) : Car(length, clearance) {
		setDisplacement(engine_displacement);
	}
	Car(double length, int clearance, 
		double engine_displacement, int engine_power) : 
		Car(length, clearance, engine_displacement) {

		setPower(engine_power);
	}

	Car(double length, int clearance,
		double engine_displacement, int engine_power, int wheel_diameter) :
		Car(length, clearance, engine_displacement, engine_power) {

		setWheel(wheel_diameter);
	}
	Car(double length, int clearance,
		double engine_displacement, int engine_power, 
		int wheel_diameter, string color) :
		Car(length, clearance, engine_displacement, engine_power, wheel_diameter) {

		setColor(color);
	}
	Car(double length, int clearance,
		double engine_displacement, int engine_power,
		int wheel_diameter, string color, string gearbox_type) :
		Car(length, clearance, engine_displacement, engine_power, wheel_diameter, color) {

		setGearbox(gearbox_type);
	}
	//Getters
	double getLength() { return _length; }
	int getClearance() { return _clearance; }
	double getDisplacement() { return _engine_displacement; }
	int getPower() { return _engine_power; }
	int getWheel() { return _wheel_diameter; }
	string getColor() { return _color; }
	string getGearbox() { return _gearbox_type; }

	//Setters
	void setLength(double length) {
		if (length > 0) {
			_length = length;
		}
		else {
			_length = 1;
		}
	}

	void setClearance(int clearance) {
		if (clearance > 5) {
			_clearance = clearance;
		}
		else {
			_clearance = 5;
		}
	}
	void setDisplacement(double engine_displacement) {
		if (engine_displacement > 1) {
			_engine_displacement = engine_displacement;
		}
		else {
			_engine_displacement = 1;
		}
	}
	void setPower(int engine_power) {
		if (engine_power > 50) {
			_engine_power = engine_power;
		}
		else {
			_engine_power = 50;
		}
	}

	void setWheel(int wheel_diameter) {
		if (wheel_diameter > 10) {
			_wheel_diameter = wheel_diameter;
		}
		else {
			_wheel_diameter = 10;
		}
	}

	void setColor(string color) {
		_color = color;
	}

	void setGearbox(string gearbox_type) {
		if (gearbox_type == "auto" || gearbox_type == "mechanic") {
			_gearbox_type = gearbox_type;
		}
		else {
			_gearbox_type = "auto";
		}
	}

};

void set_value(Car &car) {
	int choice_set;
	do
	{
		cout << "Choose option \n1- set length \n2 - set ground clearance (ride height)"
			<< " \n3 - set engine displacement \n4- set engine power"
			<< " \n5 - set wheel diameter \n6- set colour"
			<< " \n7 - set gearbox type \n8- exit"
			<< " \nWrite your choice: ";
		cin >> choice_set;

	} while (choice_set < 1 || choice_set>8);

	switch (choice_set)
	{
	case 1: {
		double length;
		cout << "Enter value: ";
		cin >> length;
		car.setLength(length);
	}break;

	case 2: {
		int clearance;
		cout << "Enter value: ";
		cin >> clearance;
		car.setClearance(clearance);
	}break;

	case 3: {
		double displacement;
		cout << "Enter value: ";
		cin >> displacement;
		car.setDisplacement(displacement);
	}break;

	case 4: {
		int power;
		cout << "Enter value: ";
		cin >> power;
		car.setPower(power);
	}break;

	case 5: {
		int diameter;
		cout << "Enter value: ";
		cin >> diameter;
		car.setWheel(diameter);
	}break;

	case 6: {
		string colour;
		cout << "Enter value: ";
		cin >> colour;
		car.setColor(colour);
	}break;

	case 7: {
		string gearbox;
		cout << "Enter value(auto or mechanic): ";
		cin >> gearbox;
		car.setGearbox(gearbox);
	}break;
	}
	cout << endl << endl;
}


void get_value(Car car) {
	int choice_get;
	do
	{
		cout << "Choose option \n1- get length \n2 - get ground clearance (ride height)"
			<< " \n3 - get engine displacement \n4- get engine power"
			<< " \n5 - get wheel diameter \n6- get colour"
			<< " \n7 - get gearbox type \n8- exit"
			<< " \nWrite your choice: ";
		cin >> choice_get;
	} while (choice_get < 1 || choice_get>8);

	switch (choice_get)
	{
	case 8: {
		break;
	}break;
		  cout << "Your value: ";
	case 1: {
		cout << car.getLength();
	}break;

	case 2: {
		cout << car.getClearance();
	}break;

	case 3: {
		cout << car.getDisplacement();
	}break;

	case 4: {
		cout << car.getPower();
	}break;

	case 5: {
		cout << car.getWheel();
	}break;

	case 6: {
		cout << car.getColor();
	}break;

	case 7: {
		cout << car.getGearbox();
	}break;
	}
	cout << endl << endl;
}

void all_get(Car car) {
	cout << "Car structure: " << endl;
	cout << "Length: " << car.getLength() << endl;
	cout << "Ground clearance (ride height): " << car.getClearance() << endl;
	cout << "Engine displacement: " << car.getDisplacement() << endl;
	cout << "Engine power: " << car.getPower() << endl;
	cout << "Wheel diameter: " << car.getWheel() << endl;
	cout << "Colour: " << car.getColor() << endl;
	cout << "Gearbox type: " << car.getGearbox() << endl;
	cout << endl << endl;
}


void find_value(Car car) {
	int choice_find;
	bool is_found = true;
	do
	{
		cout << "Choose option \n1- find length \n2 - find ground clearance (ride height)"
			<< " \n3 - find engine displacement \n4- find engine power"
			<< " \n5 - find wheel diameter \n6- find colour"
			<< " \n7 - find gearbox type \n8- exit"
			<< " \nWrite your choice: ";
		cin >> choice_find;
	} while (choice_find < 1 || choice_find > 8);

	switch (choice_find)
	{
	case 8: {
		break;
	}break;

	cout << "Enter your value: ";
	case 1: {
		double length;
		cin >> length;
		if (length == car.getLength())
		{
			is_found = true;
		}
		else {
			is_found = false;
		}
	}break;

	case 2: {
		int clearance;
		cin >> clearance;
		if (clearance == car.getClearance())
		{
			is_found = true;
		}
		else {
			is_found = false;
		}
	}break;

	case 3: {
		double displacement;
		cin >> displacement;
		if (displacement == car.getDisplacement())
		{
			is_found = true;
		}
		else {
			is_found = false;
		}
	}break;

	case 4: {
		int power;
		cin >> power;
		if (power == car.getPower())
		{
			is_found = true;
		}
		else {
			is_found = false;
		}
	}break;

	case 5: {
		int wheel;
		cin >> wheel;
		if (wheel == car.getWheel())
		{
			is_found = true;
		}
		else {
			is_found = false;
		}
	}break;

	case 6: {
		string color;
		cin >> color;
		if (color == car.getColor())
		{
			is_found = true;
		}
		else {
			is_found = false;
		}
	}break;

	case 7: {
		string gearbox; 
		cin >> gearbox;
		if (gearbox == car.getGearbox())
		{
			is_found = true;
		}
		else {
			is_found = false;
		}
	}break;
	}

	(is_found) ? cout << "Your value is found" : cout << "Your value is not found";
	cout << endl << endl;
}

int main()
{
	Car car1(2.5, 10, 5, 100, 15, "black", "mechanic");
	all_get(car1);
	cout << endl << endl;


	bool cont = true;
	do//main cycle- to end
	{
		int choice_mode;
		do//cycle to get mode
		{
			cout << "Choose option \n0-exit \n1- set value \n2 - get value"
				<<" \n3- find value \n4- see all \nWrite your choice: ";
			cin >> choice_mode;
		} while (choice_mode < 0 || choice_mode > 4);
		cout << endl << endl;
		switch (choice_mode)
		{
			case 0:
			{
				cont = false;

			}break;

			case 1:
			{
				set_value(car1);

			}break;

			case 2:
			{
				get_value(car1);

			}break;

			case 3:
			{
				find_value(car1);

			}break;

			case 4:
			{
				all_get(car1);

			}break;
		}

	} while (cont != false);

	
	system("pause");
	return 0;
}