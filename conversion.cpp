#include "conversion.h"


QString from10To(int x, int ssNow, int ssWant)
{
    int x_temp, temp = 0; // объявление переменных
    QString reponse; // обявление переменных для ответа
    x_temp = x;

    while (x_temp != 0) // цикл выполняется, пока дубликат переменной числа не равен 0
    {
        temp = x_temp % ssWant; // присваиваем переменной остаток
        x_temp /= ssWant; // уменьшаем дубликат переменной числа

        if (temp > 9) // если остаток >9, то цифра переводится в соответствующую букву латинского алфавита и добавляется в ответ
        {
            reponse.push_back(char(65 + temp - 10));
        }
        else // если остаток 0 <= temp <= 9, то цифра переводится в строку, затем С-строку, затем снимается константноть и разыменовывается
        {
            reponse.push_back(*const_cast<char*>(std::to_string(temp).c_str()));
        }
    }
    std::reverse(reponse.begin(), reponse.end());
    return reponse;
}


QString conversion(Ui::MainWindow* ui)
{
    int ssNow, ssWant, x;

    ssWant = ui->lineEdit_3->text().toInt();
    x =      ui->lineEdit->text().toInt();
    ssNow =  ui->lineEdit_2->text().toInt();

    if (ssNow == 10)
        {
            return from10To(x, ssNow, ssWant);
        }
        else
        {
            int countNumber = 0, ss10 = 0;

            while (x)
            {
                int lastNumber = x % 10;
                x /= 10;
                ss10 += lastNumber * pow(ssNow, countNumber++);
            }
            return from10To(ss10, 10, ssWant);
        }
}



