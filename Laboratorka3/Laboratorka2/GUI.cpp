﻿#include "GUI.h" // Подключаем файл заголовка для формы
#include "Algorithms.h" // А это уже файл заголовка для алгоритмов
#include <string>
using namespace System; // Нужные пространства имен для работы с формами и не только
using namespace System::Windows::Forms;

/*const  rozmir = 11;*/ // Размерность матрицы растояний ? для алгоритма (я хз крч как он работает)

 double graph[rozmir][rozmir] = { // Сама матрица магических циферок
       {0, 2, 1.7, 0.9, 0, 2.5, 5, 1, 0, 2.5, 0},
       {0, 0, 0.6, 1.3, 0, 0, 0, 2, 0.95, 0, 0.6},
       {1.7, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
       {0.9, 1.3, 0, 0, 0, 0, 0, 1, 0.55, 0, 0},
       {0, 0, 0.5, 0, 0, 0, 0, 1.1, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0.75, 0},
       {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {1, 2, 0, 0, 1.1, 0, 0, 0, 0, 0, 0},
       {1.3, 0.95, 0, 0.55, 0.75, 0, 0, 0, 0, 0, 0},
       {2.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0},
       {0, 0.6, 0, 0, 0, 0.8, 0, 0, 0, 0, 0}
};

std::string Places[] = { // Упорядоченые названия местечек по которым будем бегать 
        "Red University", "Andriivska Church",
        "St. Michael's Cathedral", "Golden Gate", "Lyadski Gate",
        "Funicular", "KPI", "Fountain on Khreshchatyk", "St. Sophia Cathedral",
        "National Philharmonic", "One Street Museum"
};

// Кста важная пометка, т.к вот это все добро считает с нуля, а дорогой наш человечек, или, прости Господи, программист - с 1, 
// то при вводе в функцию над отнимать единицу, а то будем считать не те маршруты

// (Если еще будут нужны пояснения, в хедере алгоритмов я дописал прояснений) 
// Пожелаем ООО "Фронтовики" (ООО аббревиатура от "Оксана Овсянник и О, назар") успешно держать лабораторный фронт

// - Андрей Григорьевич


[STAThreadAttribute]
void main(cli::array < String^>^ args)
{
    // Без цієї штуки форма не буде працювати
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Laboratorka2::Main form;
    Application::Run(% form);
    
}
