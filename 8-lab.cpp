#include <iostream>

using namespace std;

struct grades
{
    int value = 0;
    string subject;
};

struct student
{
    int gropNumber = 0;
    string name;
    char surname[2] = {'x', 'x'};
    grades grades[5];
    double averageGrades = 0;
};

void zad1()
{
    bool flag = true;
    int size = 1;
    cout << "Введите кол-во студентов :";
    cin >> size;
    cout << endl;
    student buffer;
    student * studdentList = new student [size];

    for (int i = 0; i < size; i++)
    {
        cout << "Введите фамилию для студента #" << i+1 << " :";
        cin >> studdentList[i].name; 
        cout << "Введите инициалы для студента #" << i + 1 << " :"<< endl;
        for (int i2 = 0; i2 < 2; i2++)
        {
            if (i2 == 0)
            {
                cout << "Первая буква для имени :";
            }
            else 
            {
                cout << "Первая буква Фамилии :";
            }
            cin >> studdentList[i].surname[i2];
        }
        cout << "Теперь введите номер его группы :";
        cin >> studdentList[i].gropNumber;
        cout << "Теперь поочередно введите название предмета и оценку студента:" << endl;
        for (int i2 = 0; i2 < 5; i2++)
        {
            cout << endl << "ввод предмета #" << i2 + 1 << endl;
            cout << "Название предмета :";
            cin >> studdentList[i].grades[i2].subject;
            cout << "Оценка по предмету (от 1 до 5) :";
            bool x = true;
            do
            {
                x = true;
                cin >> studdentList[i].grades[i2].value;
                if (studdentList[i].grades[i2].value < 1 || studdentList[i].grades[i2].value > 5)
                {
                    x = false;
                    cout << "Оценка за зоной допустимого попробуйте еще :";
                }
            } while (!x);
            studdentList[i].averageGrades += studdentList[i].grades[i2].value;
        }
        studdentList[i].averageGrades /= 5;
    }

    if (size > 1)
    {
        for (int i = 0; i < size; i++)
        {
            for (int i2 = 0; i < size - 1; i++)
            {
                if (studdentList[i2].averageGrades > studdentList[i2 + 1].averageGrades)
                {
                    studdentList[i2] = buffer;
                    studdentList[i2] = studdentList[i2 + 1];
                    studdentList[i2 + 1] = buffer;
                }
            }
        }
    }

    cout << "Информация по введеным вами студентам упорядочным по среднему баллу:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << endl << "Фамилия и инициалы студента #" << i + 1 << " :" 
            << studdentList[i].name<<" "<< studdentList[i].surname[0]<<"."<< studdentList[i].surname[1] << endl;

        cout << "номер его группы :"<< studdentList[i].gropNumber << endl;
        cout << "Его средний бал равен :" << studdentList[i].averageGrades << endl;
        cout << "название предметов и оценок студента:" << endl;
        for (int i2 = 0; i2 < 5; i2++)
        {
            cout << endl << "предмета #" << i2 + 1 << endl;
            cout << "Название предмета :"<< studdentList[i].grades[i2].subject << endl;
            cout << "Оценка по предмету :" << studdentList[i].grades[i2].value << endl;
        }
    }

    cout << "Информация по введеным вами студентам с средним баллом 4 и выше :" << endl;
    for (int i = 0; i < size; i++)
    {
        if (studdentList[i].averageGrades >= 4)
        {
            flag = false;
            cout << endl << "Фамилия и инициалы студента #" << i + 1 << " :"
                << studdentList[i].name << " " << studdentList[i].surname[0] << "." << studdentList[i].surname[1] << endl;

            cout << "номер его группы :" << studdentList[i].gropNumber << endl;
            cout << "Его средний бал равен :" << studdentList[i].averageGrades << endl;
            cout << "название предметов и оценок студента:" << endl;
            for (int i2 = 0; i2 < 5; i2++)
            {
                cout << endl << "предмета #" << i2 + 1 << endl;
                cout << "Название предмета :" << studdentList[i].grades[i2].subject << endl;
                cout << "Оценка по предмету :" << studdentList[i].grades[i2].value << endl;
            }
        }
    }
    if (flag)
    {
        cout << "к сожаленнию студентов с средни баллов выше 4 нет";
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    zad1();
}
