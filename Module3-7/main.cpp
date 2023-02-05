//
//  main.cpp
//  Module3-7
//
//  Created by Ольга Полевик on 07.06.2021.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale (LC_ALL, "");
    int size = 0;
    char act = 0;
    int shift = 0;
    while (true)
    {
        cout << "Для шифрования выберите s, для дешифрования выберите d, для выхода другую клавишу" << endl;
        cin >> act;
        if ((act != 's') && (act != 'd'))
        {
            break;
        }
        
        cout << "Введите количество символов строки: " << endl;
        cin >> size;
        
        cout << "Введите величину сдвига " << endl;
        cin >> shift;
        
        char *arr = new char[size + 1];
        for (int i = 0; i < size; ++i)
        {
            char c = 0;
            while (true)
            {
                cout << "Введите символы a-z или A-Z: " << endl;
                cin >> c;
                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                {
                    cout << "Символ введен верно " << c << endl;
                    break;
                }
            }
            arr[i] = c;
            /*cout << "Введите символы a-z или A-Z: " << endl;
            cin >> arr[i];*/
        }
        arr[size] = 0;

        if (act == 's')
        {
            for (int i = 0; i < size; ++i)
            {
                if (arr[i] >= 'a' && arr[i] <= 'z')
                {
                    arr[i] = (arr[i] + shift - 97) % 26 + 97;
                }
                if (arr[i] >= 'A' && arr[i] <= 'Z')
                {
                    arr[i] = (arr[i] + shift - 65) % 26 + 65;
                }
            }
        }
        if (act == 'd')
        {
            for (int i = 0; i < size; ++i)
            {
                if (arr[i] >= 'a' && arr[i] <= 'z')
                {
                    arr[i] = (arr[i] - shift - 122) % 26 + 122;
                }
                if (arr[i] >= 'A' && arr[i] <= 'Z')
                {
                    arr[i] = (arr[i] - shift - 90) % 26 + 90;
                }
            }
        }
        cout << arr << endl;
        delete[] arr;
    }
    cout << "Работа завершена, спасибо!" << endl;
    return 0;
}
