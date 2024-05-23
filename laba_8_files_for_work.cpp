#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student {
	string surname, name, patronymic, date_of_birth, adress;
	int rating;

	void enter_info(string s, string n, string p, string d, string a, int r) {
		surname = s;
		name = n;
		patronymic = p;
		date_of_birth = d;
		adress = a;
		rating = r;
	}
};

int main() {

	setlocale(LC_ALL, "RU");
	system("chcp 1275>nul");
	system("cls");

	int n;
	student stud_mass[50]{};

	cout << "Введите количество студентов: "; cin >> n;

	for (int i = 0; i < n; i++) {

		string s, n, p, d, a;
		int r;

		cout << "Введите ФИО, дату рождения, адрес, рейтинг " << i + 1 << "-го студента: "; cin >> s >> n >> p >> d >> a >> r;
		stud_mass[i].enter_info(s, n, p, d, a, r);
	}

	int new_stud_mass[50]{};
	int k = 0;


	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (stud_mass[i].date_of_birth == stud_mass[j].date_of_birth) {
				new_stud_mass[k] = i;
				new_stud_mass[k + 1] = j;
				k += 2;
			}
		}
	}

	bool flag = false;
	int surname_index;
	string find_surname;

	cout << "Введите фамилию человека, перед которым надо поставить другого: "; cin >> find_surname;

	for (int i = 0; i < n; i++) {
		if (stud_mass[i].surname == find_surname) {
			surname_index = i;
			flag = true;
		}
	}

	if (flag) {
		for (int i = n; i > surname_index; i--) {
			stud_mass[i] = stud_mass[i - 1];
		}

		string new_s, new_n, new_p, new_d, new_a;
		int new_r;

		cout << "Введите ФИО, дату рождения, адрес, рейтинг нового студента: "; cin >> new_s >> new_n >> new_p >> new_d >> new_a >> new_r;
		stud_mass[surname_index].enter_info(new_s, new_n, new_p, new_d, new_a, new_r);

		n += 1;

		for (int i = 0; i < k; i++) {
			if (new_stud_mass[i] >= surname_index) {
				new_stud_mass[i] += 1;
			}
		}
	}

	ofstream f1("f1.txt");

	for (int i = 0; i < n; i++) {
		bool new_flag = true;
		for (int j = 0; j < k; j++) {
			if (i == new_stud_mass[j]) {
				new_flag = false;
			}
		}
		if (new_flag) {
			f1 << stud_mass[i].surname << " " << stud_mass[i].name << " " << stud_mass[i].patronymic <<
				" " << stud_mass[i].adress << " " << stud_mass[i].date_of_birth << " " << stud_mass[i].rating << endl;
		}
	}
	f1.close();
	return 0;
}


