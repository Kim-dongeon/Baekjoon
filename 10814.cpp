#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct _Person
{
	int age;
	string name;
}Person;

bool cmp(const Person &p1, const Person &p2)
{
	return p1.age < p2.age;
}
int main()
{
	int N;
	cin >> N;
	vector<Person> v;
	while (N--)
	{
		Person temp;
		cin >> temp.age >> temp.name;
		v.push_back(temp);
	}
	stable_sort(v.begin(), v.end(), cmp);

	cout << v.size() << "   " << N << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

}