#include <iostream>
#include "smart_ptr.h"
#include <memory>

using namespace std;

int main(){
	
	smart_ptr<int> p1(new int(1));
	smart_ptr<int> p2(new int(2));
	smart_ptr<int> p3;

	cout << "p1: " << *p1 << "  use_count: " << p1.use_count()<< endl;
	cout << "p2: " << *p2 << "  use_count: " << p2.use_count() << endl;
	//cout << "p3: " << *p3 << "  use_count: " << p3.use_count() << endl;


	p3 = p1;
	cout << endl;
	cout << "p1: " << *p1 << "  use_count: " << p1.use_count() << endl;
	cout << "p3: " << *p3 << "  use_count: " << p3.use_count() << endl;
	
	*p3 = 3;
	cout << endl;
	cout << "p1: " << *p1 << "  use_count: " << p1.use_count() << endl;
	cout << "p3: " << *p3 << "  use_count: " << p3.use_count() << endl;

	p1 = p2;
	cout << endl;
	cout << "p1: " << *p1 << "  use_count: " << p1.use_count() << endl;
	cout << "p2: " << *p2 << "  use_count: " << p2.use_count() << endl;
	cout << "p3: " << *p3 << "  use_count: " << p3.use_count() << endl;

	{
		smart_ptr<int> p4 = p1;
		cout << endl;
		cout << "p1: " << *p1 << "  use_count: " << p1.use_count() << endl;
		cout << "p2: " << *p2 << "  use_count: " << p2.use_count() << endl;
		cout << "p3: " << *p3 << "  use_count: " << p3.use_count() << endl;
		cout << "p4: " << *p4 << "  use_count: " << p4.use_count() << endl;
	}

	cout << endl;
	cout << "p1: " << *p1 << "  use_count: " << p1.use_count() << endl;
	cout << "p2: " << *p2 << "  use_count: " << p2.use_count() << endl;
	cout << "p3: " << *p3 << "  use_count: " << p3.use_count() << endl;

	return 0;
}
