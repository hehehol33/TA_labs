﻿#pragma once

#include <iostream>
#include <chrono>

// Я подучил классы,так чт нынче код будет адекватнее


// Класс для Очереди через массивы
class ArrQueue {
private: 
    unsigned short queue_size; // Размер очереди
    unsigned short* Shrt_queue = nullptr; // Тут будет наш динамический массив
    unsigned int exec_time; // Пишем время исполнения (хотя тут и шорта хватило б с головой, больше 65к ток вывод в консось)
    // А эт шаблон, клевая штука, в нее вбил замер времени, чтоб не повторятся 
    template<typename Func> 
    void measureExecutionTime(Func&& func); 

public: // Пошли методы
    ArrQueue(); // Конструктор, задает размер в нуль и создает диннамический массив 
    void Enqueue(const unsigned short& entity); // Метод, добавляющий елемент в очередь (даже через ссылку, иб шаблон по другому не сделаем)
    unsigned short Dequeue(); // Метод, убирающий с очереди элемент, возвращает назад какой конкретно грохнул
    void ShowQueue(); // Только для консоси, выводит содержимое очереди
    unsigned int ExecTime() const; // Возвращает назад время затраченое на выполнение задачки (почти любого метода в классе)
    unsigned short* GetQueue(); // Возвращает указатель на масссив очереди
    unsigned short getSize(); // Возвращает размер очереди 
    ~ArrQueue(); // Деконструктор, подчищает динамичекскую память дабы не улететь в утечку
};

struct Node { // Структура для работы через указатели
    unsigned short data; // Значение
    Node* next; // Указатель на структуру перед ним же 
    Node(unsigned short value) : data(value), next(nullptr) {} // Конструктор для структуры, нужен для того, чтоб новые элементы можно было обьявить просто значением, а не строчить нулптр
};

// Сам клас для очереди через указатели (справедливости ради, очередь через массивы без указателей тоже никуда)
class NodeQueue { 
private:
    // Тут без конструкторов, задаем что нужно тут
    Node* head = nullptr; // Храним в классе его верхушку
    Node* tail = nullptr; // И хвост
    unsigned int exec_time; // Аналогично первому, время исполнения
    unsigned short size; // Размер, лениво используется, некоторые методы все еще на nullptr-ах
    // Шаблон аналогичен первому классу 
    template<typename Func> 
    void measureExecutionTime(Func&& func);

public:
    void Enqueue(unsigned short& element); // Добавляем, коль уж соизволите
    unsigned short Dequeue(); // Бог дал, Бог взял, и говорит что именно
    unsigned short* GetQueue(); // Собирает очередь в массив и возврщает его, чтоб можно было пользовать нормально, а не просить фронт е**тся с пачкой указателей
    void ShowQueue(); // Для консося вывод, в теории на его базе можно собрать быренький вывод для форм, но ну его лесом
    unsigned short getSize() const; // Даем размер очереди
    unsigned int ExecTime() const; // Отдаем посчитаное время исполнения
    ~NodeQueue(); // Деконструктор, чистит пачку указателей
};