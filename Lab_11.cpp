// Task 01 - Time class overload
//#include <iostream>
//using namespace std;
//class Time
//{
//public:
//    Time() : hours{ 0 }, mins{ 0 }, sec{ 0 }
//    {
//        cout << "Class has been created" << endl;
//    }
//    Time(int h, int m, int s)
//    {
//        cout << "Class has been created" << endl;
//        if (s > 59)
//        {
//            int buf = s / 60;
//            m += buf;
//            s = s % 60;
//        }
//        if (m > 59)
//        {
//            int buf = m / 60;
//            h += buf;
//            m = m % 60;
//        }
//        cout << "sec " << s << endl;
//        cout << "min " << m << endl;
//        cout << "hours  " << h << endl;
//        Setsec(s);
//        Setmins(m);
//        Sethours(h);
//    }
//    Time(float hours)
//    {
//        cout << "Float type Class has been created" << endl;
//        float flhrs = hours + mins/60 + sec/3600;      // Casting everything into hours with mins and secs
//    }
//    void Sethours(int h)
//    {
//        hours = h;
//    }
//    void Setmins(int m)
//    {
//        mins = m;
//    }
//    void Setsec(int s)
//    {
//        sec = s;
//    }
//    int Gethours()
//    {
//        return hours;
//    }
//    int Getmin()
//    {
//        return mins;
//    }
//    int Getsec()
//    {
//        return sec;
//    }
//    void Printtime()
//    {
//        cout << hours << " : " << mins << " : " << sec << '\n';
//    }
//    Time Addtime(Time b)
//    {
//        Time t;
//        int temp_sec{ 0 }, temp_min{ 0 }, temp_hour{ 0 };
//        temp_sec = sec + b.Getsec();
//        if (temp_sec > 59)
//        {
//            int buf = temp_sec / 60;
//            temp_min += buf;
//            temp_sec = temp_sec % 60;
//        }
//        temp_min += mins + b.Getmin();
//        if (temp_min > 59)
//        {
//            int buf = temp_min / 60;
//            temp_hour += buf;
//            temp_min = temp_min % 60;
//        }
//        temp_hour += hours + b.Gethours();
//        t.Setsec(temp_sec);
//        t.Setmins(temp_min);
//        t.Sethours(temp_hour);
//        return t;
//    }
//    Time operator+ (const Time&) const;
//    Time operator- (const Time&) const;
//    Time operator+(double) const;
//    bool operator< (Time) const;
//    friend std::ostream& operator<< (std::ostream& out, const Time& t);
//
//
//    operator float() const
//            {
//                //Transfoming into hours float type
//                float fsec = sec / 3600;
//                float fmin = mins / 60;
//                float fhours = static_cast<float>(hours) + fsec + fmin;
//                return fhours;
//            }
//private:
//    int hours;
//    int mins;
//    int sec;
//};
//Time Time::operator+ (const Time& t2) const
//{
//    int temp_sec{ 0 }, temp_min{ 0 }, temp_hour{ 0 };
//    temp_sec = sec + t2.sec;
//    if (temp_sec > 59)
//    {
//        int buf = temp_sec / 60;
//        temp_min += buf;
//        temp_sec = temp_sec % 60;
//    }
//    temp_min += mins + t2.mins;
//    if (temp_min > 59)
//    {
//        int buf = temp_min / 60;
//        temp_hour += buf;
//        temp_min = temp_min % 60;
//    }
//    temp_hour += hours + t2.hours;
//    return Time(temp_sec, temp_min, temp_hour);
//}
//
//Time Time::operator- (const Time& t2) const
//{
//    int temp_sec{ 0 }, temp_min{ 0 }, temp_hour{ 0 };
//    temp_hour = hours - t2.hours;
//    if (temp_hour < 0)
//    {
//        return Time(0, 0, 0);
//    }
//    temp_min = mins - t2.mins;
//    if (temp_min < 0)
//    {
//        temp_hour --;
//        temp_min = mins + 60 - t2.mins;
//        if (temp_hour < 0)
//        {
//            return Time(0, 0, 0);
//        }
//    }
//    temp_sec = sec - t2.sec;
//    if (temp_sec < 0)
//    {
//        temp_min--;
//        temp_sec = sec + 60 - t2.sec;
//        if (temp_min < 0)
//        {
//            return Time(0, 0, 0);
//        }
//    }
//    return Time(temp_sec, temp_min, temp_hour);
//}
//Time Time::operator+(double mult) const
//{
//    Time result;
//    result.hours = hours + static_cast<int>(mult);
//    result.mins = mins + ((int)(mult - (int)mult)/60);
//    result.sec = sec + ((mult - (int)mult) / 3600);
//    return result;
//}
//
//bool Time::operator< (Time t1) const
//{
//    if ((hours * 3600 + mins * 60 + sec) < (t1.hours * 3600 + t1.mins * 60 + t1.sec))
//        return true;
//    else return false;
//}
//
//std::ostream& operator<< (std::ostream& out, const Time& t)
//{
//    out << t.hours << " : " << t.mins << " : " << t.sec << endl;
//    return out;
//}
//
//int main()
//{
//    Time t1, t2;
//    Time t3 = 2.35F;
//    cout << t1;
//
//}

// Task 2 - Sorting points in vector
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // для алгоритма сортировки
class Point
{
public:
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	double DistToPoint()
	{
		double d = sqrt((0 - x) * (0 - x) + (0 - y) * (0 - y));
		return d;
	}
	bool operator< (Point);
	friend std::ostream& operator<< (std::ostream& out, const Point& p);
};
bool Point::operator< (Point p1)
{
	if (DistToPoint() < p1.DistToPoint())
		return true;
	else return false;
}
std::ostream& operator<< (std::ostream& out, const Point& p)
{
    out << p.x << " , " << p.y << std::endl;
    return out;
}

int main()
{
	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для // класса Point
	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для // класса Point
	return 0;
}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//struct StudentGrade
//{
//	string name;
//	char grade;
//};
//class GradeMap
//{
//private:
//	vector<StudentGrade> m_map;
//public:
//	GradeMap()
//	{ }
//	char& operator[](const string& name);
//};
//char& GradeMap::operator[](const string& name)
//{
//	// Найдём ли мы имя ученика в векторе
//	for (auto& ref : m_map)
//	{
//		// Если нашли, то возвращаем ссылку на его оценку
//		if (ref.name == name)
//			return ref.grade;
//	}
//	// Не нашли - создаём новый StudentGrade для нового ученика
//	StudentGrade temp{ name, ' ' };
//	// Помещаем его в конец вектора
//	m_map.push_back(temp);
//	// И возвращаем ссылку на его оценку
//	return m_map.back().grade;
//}
//
//int main()
//{
//	GradeMap grades;
//	grades["John"] = 'A';
//	grades["Martin"] = 'B';
//	cout << "John has a grade of " << grades["John"] << endl;
//	cout << "Martin has a grade of " << grades["Martin"] << endl;
//	cout << "New name and grade?" << endl;
//	string name;
//	char grade;
//	cin >> name >> grade;
//	grades[name] = grade;
//	std::cout << name << " has a grade of " << grades[name] << endl;
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//class Distance
//{
//private:
//    int feet;
//    float inches;
//    const float MTF;
//public:
//    // конструктор по умолчанию
//    Distance() : feet(0), inches(0.0), MTF(3.280833F) { }
//    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F)
//    { }
//    Distance(float meters) : MTF(3.280833F)
//    {
//        float fltfeet = MTF * meters; // перевод в футы
//        feet = int(fltfeet); // число полных футов
//        inches = 12 * (fltfeet - feet); // остаток - это дюймы
//    }
//    void getdist()
//    {
//        cout << "“\nEnter amount of foots : “";
//        cin >> feet;
//        cout << "“\nEnter amonnt of inches : “";
//        cin >> inches;
//    }
//    void showdist()
//    {
//        cout << feet << " - " << inches << " \n";
//    }
//    operator float() const
//    {
//        float fracfeet = inches / 12;
//        fracfeet += static_cast<float>(feet);
//        return fracfeet / MTF;
//    }
//    Distance operator+ (const Distance&) const;
//    friend std::ostream& operator<< (std::ostream& out, const Distance& dist);
//};
//Distance Distance::operator+ (const Distance& d2) const
//{
//    int f = feet + d2.feet;
//    float i = inches + d2.inches;
//    if (i >= 12.0)
//    {
//        i -= 12.0;
//        f++;
//    }
//    return Distance(f, i);
//}
//std::ostream& operator<< (std::ostream& out, const Distance& dist)
//{
//    out << dist.feet << "\ " << dist.inches << " \n";
//    return out;
//}
//
//
//int main()
//{
//    Distance dist2, dist3, Dist4;
//    //dist1.getdist();
//    //dist2.getdist();
//    //dist3 = dist1 + dist2;
//    //dist3.showdist();
//    //cout << "\ndist1 = " << dist3;
//    Distance dist1 = 2.35F;
//    float mtrs;
//    mtrs = static_cast<float>(dist1);
//    mtrs = dist2;
//    dist2.showdist();
//
//}


