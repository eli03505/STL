#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Lesson
{
	string name;
public:
	Lesson() = default;
	Lesson(const string& name)
	{
		setName(name);
	}
	Lesson(const Lesson& other)
	{
		setName(other.name);
	}
	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void show()
	{
		cout << "Lesson Name:" << getName() << endl;
	}
};
class Exam
{
	int point;
	vector<Lesson> vector_lessons;
public:
	Exam() = default;

	Exam(int point)
	{
		setPoint(point);
	}

	Exam(const Exam& other)
	{		
		setPoint(other.point);
	}
	int getPoint()
	{
		return point;
	}
	void setPoint(int point)
	{
		this->point = point;
	}
	vector<Lesson> getVectorLessons()
	{
		return vector_lessons;
	}
	void setVectorLessons(vector<Lesson> vector_lessons)
	{
		this->vector_lessons = vector_lessons;
	}
	void addLessons(Lesson& lesson)
	{
		vector_lessons.push_back(lesson);
	}
	void addLessons(string name)
	{
		vector_lessons.push_back(Lesson(name));
	}
	void show()
	{
		for (auto i = vector_lessons.begin();
			i != vector_lessons.end(); i++)
		{
			i->show();
		}
		cout << "Point:" << getPoint() << endl;
	}

};

class BankCard
{
	string longCode;
	string password;
	double balance;
	int expiredMonth;
	int expiredYear;
public:
	BankCard() = default;

	BankCard(const string& longCode, const string& password, double balance,
		int expiredMonth, int expiredYear)
	{
		setLongCode(longCode);
		setPassword(password);
		setBalance(balance);
		setExpiredMonth(expiredMonth);
		setExpiredYear(expiredYear);
	}
	BankCard(const BankCard& other)
	{
		setLongCode(other.longCode);
		setPassword(other.password);
		setBalance(other.balance);
		setExpiredMonth(other.expiredMonth);
		setExpiredYear(other.expiredYear);
	}
	string getLongCode()
	{
		return longCode;
	}
	void setLongCode(string longCode)
	{
		this->longCode = longCode;
	}
	string getPassword()
	{
		return password;
	}
	void setPassword(string password)
	{
		this->password = password;
	}
	double getBalance()
	{
		return balance;
	}
	void setBalance(double balance)
	{
		this->balance = balance;
	}
	int getExpiredMonth()
	{
		return expiredMonth;
	}
	void setExpiredMonth(int expiredMonth)
	{
		this->expiredMonth = expiredMonth;
	}
	int getExpiredYear()
	{
		return expiredYear;
	}
	void setExpiredYear(int expiredYear)
	{
		this->expiredYear = expiredYear;
	}
	void show()
	{
		cout << "Code:" << getLongCode() << endl;
		cout << "Password:" << getPassword() << endl;
		cout << "Balance:" << getBalance() << endl;
		cout << "Expired Month:" << getExpiredMonth() << endl;
		cout << "Expired Year:" << getExpiredYear() << endl;
	}

};
class Student
{
	string name;
	string surname;
	string speciality;
	int score;
	double money;
	vector<BankCard> vector_cards;
	vector<Exam> vector_exams;
public:
	Student() = default;
	Student(const string& name, const string& surname, 
		const string speciality, int score, double money)
	{
		setName(name);
		setSurName(surname);
		setSpeciality(speciality);
		setScore(score);
		setMoney(money);
	}
	Student(const Student& other)
	{
		setName(other.name);
		setSurName(other.surname);
		setSpeciality(other.speciality);
		setScore(other.score);
		setMoney(other.money);
	}
	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getSurName()
	{
		return surname;
	}

	void setSurName(string surname)
	{
		this->surname = surname;
	}
	string getSpeciality()
	{
		return speciality;
	}
	void setSpeciality(string speciality)
	{
		this->speciality = speciality;
	}
	int getScore()
	{
		return score;
	}
	void setScore(int score)
	{
		this->score = score;
	}
	double getMoney()
	{
		return money;
	}
	void setMoney(double money)
	{
		this->money = money;
	}
	vector<BankCard> getVectorCard()
	{
		return vector_cards;
	}
	void setVectorCard(vector<BankCard> vector_cards)
	{
		this->vector_cards = vector_cards;
	}
	vector<Exam> getVectorExam()
	{
		return vector_exams;
	}
	void setVectorExam(vector<Exam> vector_exams)
	{
		this->vector_exams = vector_exams;
	}
	void addCard(BankCard& card)
	{
		vector_cards.push_back(card);
	}
	void addExam(Exam exam, Lesson lesson)
	{
		vector_exams.push_back(exam);
		for (auto i = vector_exams.begin();
			i != vector_exams.end(); i++)
		{
			i->addLessons(lesson);
		}
	}
	void addCard(const string& longCode, const string& password, double balance,
		int expiredMonth, int expiredYear)
	{
		vector_cards.push_back(BankCard(longCode, password, balance, expiredMonth, expiredYear));
	}
	void addExam(int point)
	{
		vector_exams.push_back(Exam(point));
	}
	int showBalance()
	{
		for (auto i = vector_cards.begin();
			i != vector_cards.end(); i++)
		{
			return i->getBalance();
		}
	}
	void showStudent()
	{
		cout << "****Bank Card****" << endl;
		cout << "Name:" << getName() << endl;
		cout << "Surname:" << getSurName() << endl;
		cout << "Speciality:" << getSpeciality() << endl;
		cout << "Score:" << getScore() << endl;
		cout << "Money:" << getMoney() << endl;

		for (auto i = vector_cards.begin();
			i != vector_cards.end(); i++)
		{
			i->show();
		}
		cout << "****Exam****" << endl;
		for (auto i = vector_exams.begin();
			i != vector_exams.end(); i++)
		{
			i->show();
		}
		cout << "Balance:" << showBalance() << endl;
	}
};

class Group
{
	string name;
	vector<Student> vector_students;
	vector<Lesson> vector_lessons;
public:
	Group() = default;
	Group(const string& name)
	{
		setName(name);
	}
	Group(const Group& other)
	{
		setName(other.name);
	}
	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;
	}
	vector<Student> getVectorStudents()
	{
		return vector_students;
	}

	void setVectorStudents(vector<Student> vector_students)
	{
		this->vector_students = vector_students;
	}
	vector<Lesson> getVectorLessons()
	{
		return vector_lessons;
	}

	void setVectorLessons(vector<Lesson> vector_lessons)
	{
		this->vector_lessons = vector_lessons;
	}

	void addStudent(Student& student, BankCard card, Exam exam, Lesson lesson)
	{
		vector_students.push_back(student);
		for (auto i = vector_students.begin();
			i != vector_students.end(); i++)
		{
			i->addCard(card);
			i->addExam(exam, lesson);
		}
	}
	void addLesson(Lesson& lesson)
	{
		vector_lessons.push_back(lesson);
	}

	void addStudent(const string& name, const string& surname, const string speciality, int score
		, double money)
	{
		vector_students.push_back(Student(name, surname, speciality, score, money));
	}

	void addLesson(string name)
	{
		vector_lessons.push_back(Lesson(name));
	}

	void show()
	{
		cout << "****Students****" << endl;
		for (auto i = vector_students.begin();
			i != vector_students.end(); i++)
		{
			i->showStudent();
		}
		cout << "****Lessons****" << endl;
		for (auto i = vector_lessons.begin();
			i != vector_lessons.end(); i++)
		{
			i->show();
		}
	}

};

class Teacher
{
	string name;
	string surname;
	int age;
	string department;
	int salary;
	vector<Group> vector_groups;
	vector<BankCard> vector_cards;

public:
	Teacher() = default;
	Teacher(const string& name, const string& surname, int age, const string& department, int salary)
	{
		setName(name);
		setSurName(surname);
		setAge(age);
		setDepartment(department);
		setSalary(salary);
	}

	Teacher(const Teacher& other)
	{
		setName(other.name);
		setSurName(other.surname);
		setAge(other.age);
		setDepartment(other.department);
		setSalary(other.salary);
	}
	string getName()
	{
		return name;
	}

	void setName(string name)
	{
		this->name = name;
	}
	string getSurName()
	{
		return surname;
	}

	void setSurName(string surname)
	{
		this->surname = surname;
	}

	int getAge()
	{
		return age;
	}

	void setAge(int age)
	{
		this->age = age;
	}


	string getDepartment()
	{
		return department;
	}

	void setDepartment(string department)
	{
		this->department = department;
	}

	int getSalary()
	{
		return salary;
	}

	void setSalary(int salary)
	{
		this->salary = salary;
	}

	vector<Group> getVectorGroups()
	{
		return vector_groups;
	}

	void setVectorGroups(vector<Group> vector_groups)
	{
		this->vector_groups = vector_groups;
	}
	void addGroup(Group& group, Student& student, BankCard card, Exam exam, Lesson lesson,
		Lesson l_group)
	{
		vector_groups.push_back(group);
		for (auto i = vector_groups.begin();
			i != vector_groups.end(); i++)
		{
			i->addStudent(student, card, exam, lesson);
			i->addLesson(l_group);
		}
	}
	void addGroup(string name)
	{
		vector_groups.push_back(Group(name));
	}


	void addCard(BankCard& card)
	{
		vector_cards.push_back(card);
	}

	void showGroup()
	{
		int group_count = vector_groups.size();
		for (auto i = vector_groups.begin();
			i != vector_groups.end(); i++)
		{
			i->show();
		}
	}

	void show()
	{
		cout << "****Teacher Bank Card****" << endl << endl;
		cout << "Name:" << getName() << endl;
		cout << "SurName:" << getSurName() << endl;
		cout << "Age:" << getAge() << endl;
		cout << "Department:" << getDepartment() << endl;
		cout << "Salary:" << getSalary() << endl;

		for (auto i = vector_cards.begin();
			i != vector_cards.end(); i++)
		{
			i->show();
		}
		cout << "\n****Groups****" << endl << endl;
		for (auto i = vector_groups.begin();
			i != vector_groups.end(); i++)
		{
			i->show();
		}

	}
};
class Bank
{
	vector<BankCard> vector_cards;
public:
	Bank() = default;

	vector<BankCard> getVectorBank()
	{
		return vector_cards;
	}

	void setVectorBank(vector<BankCard> vector_cards)
	{
		this->vector_cards = vector_cards;
	}


	void addBankCards(BankCard& card)
	{
		vector_cards.push_back(card);
	}


	void addBankCards(const string& longCode, const string& password, double balance,
		int expiredMonth, int expiredYear)
	{
		vector_cards.push_back(BankCard(longCode, password, balance, expiredMonth, expiredYear));
	}

	void show()
	{
		for (auto i = vector_cards.begin();
			i != vector_cards.end(); i++)
		{
			i->show();
		}
	}
};
class University
{
	string name;
	vector<Student> vector_students;
	vector<Teacher> vector_teachers;
	int score_student;
	int payments;
public:
	University() = default;

	University(string name)
	{
		setName(name);
	}

	vector<Student> getVectorStudent()
	{
		return vector_students;
	}

	void setVectorStudent(vector<Student> vector_students)
	{
		this->vector_students = vector_students;
	}

	void addStudent(Student& student, BankCard c, Exam e, Lesson l)
	{
		vector_students.push_back(student);
		for (auto i = vector_students.begin();
			i != vector_students.end(); i++)
		{
			i->addCard(c);
			i->addExam(e, l);
		}
	}
	void addTeacher(Teacher& teacher, Group g, Student s, BankCard b, Exam e,
		Lesson l_student, Lesson l_group, BankCard card_teacher)
	{
		vector_teachers.push_back(teacher);
		for (auto i = vector_teachers.begin();
			i != vector_teachers.end(); i++)
		{
			i->addGroup(g, s, b, e, l_student, l_group);
			i->addCard(card_teacher);
		}
	}

	void addStudent(const string& name, const string& surname, const string speciality, int score
		, double money)
	{
		vector_students.push_back(Student(name, surname, speciality, score, money));
	}


	string getName()
	{
		return name;
	}

	void setName(string& name)
	{
		this->name = name;
	}

	vector<Teacher> getVectorTeacher()
	{
		return vector_teachers;
	}

	void setVectorStudent(vector<Teacher> vector_teachers)
	{
		this->vector_teachers = vector_teachers;
	}


	void addTeacher(const string& name, const string& surname, int age, const string& department
		, int salary)
	{
		vector_teachers.push_back(Teacher(name, surname, age, department, salary));
	}

	int getUniversityScore() 
	{
		for (auto i = vector_students.begin();
			i != vector_students.end(); i++)
		{
			score_student = score_student + i->getScore();
		}
		return score_student;
	}

	int getAllPayments()
	{
		for (auto i = vector_students.begin();
			i != vector_students.end(); i++)
		{
			payments = payments + i->getMoney();
		}

		for (auto i = vector_teachers.begin();
			i != vector_teachers.end(); i++)
		{
			payments = payments + i->getSalary();
		}

		return payments;
	}
	void showAll()
	{
		cout << "Students:" << endl;
		for (auto i = vector_students.begin();
			i != vector_students.end(); i++)
		{
			i->showStudent();
		}

		cout << "Teachers:" << endl;
		for (auto i = vector_teachers.begin();
			i != vector_teachers.end(); i++)
		{
			i->show();
		}
	}
};
int main()
{
	BankCard c1("145298736", "1595", 1200, 10, 2023);
	BankCard c2("987654321", "1507", 1000, 12, 2021);
	BankCard c3("987654321", "1025", 900, 9, 2022);
	BankCard c4("123456789", "6325", 1100, 10, 2022);

	Student s1("ALi", "Ibadzade", "programmer", 80, 107);
	Student s2("Rzayev", "Metin", "Developer", 70, 70);
	Student s3("Huseyn", "Ibadov", "Menecer", 65, 130);
	Student s4("Yusif", "Sofiyev", "IT", 95, 200);


	Lesson l1("Math");
	Lesson l2("Physics");
	Lesson l3("Encript");
	Lesson l4("Chemical");

	Group g1("Group Name1");
	Group g2("Group Name2");

	Exam e1(90);
	Exam e2(85);
	Exam e3(80);

	Teacher t1("Metin", "Mexdiyev", 19, "Department1", 700);
	Teacher t2("Islam", "Alesgerov", 18, "Department2", 800);
	University uni("ADBTÝA");

	e1.addLessons(l1);
	e2.addLessons(l2);
	e1.show();

	s1.addCard(c1);
	s1.addExam(e1, l1);

	s1.showStudent();

	g1.addLesson(l1);
	g1.addLesson(l2);
	g1.addStudent(s1, c1, e1, l1);
	g1.addStudent(s2, c2, e2, l2);

	g1.show();

	t1.addCard(c3);
	t1.addGroup(g1, s3, c2, e3, l3, l4);

	t1.show();


	Bank b;
	b.addBankCards(c1);
	b.show();


	uni.addStudent(s1, c1, e1, l4);
	uni.addTeacher(t1, g1, s3, c2, e3, l3, l4, c3);

	cout << uni.getUniversityScore() << endl;
	cout << uni.getAllPayments() << endl;

}