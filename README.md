## Лабораторная работа №2

**Вариант:** `(4 + 7) mod 10 + 1 = 2`

<ins>Цель задания:</ins> Исследование алгоритмов решения задач методом поиска.

<ins>Описание предметной области.</ins> Имеется транспортная сеть, связывающая
города СНГ. Сеть представлена в виде таблицы связей между городами. Связи
являются двусторонними, т.е. допускают движение в обоих направлениях.  Необходимо
проложить маршрут из одной заданной точки в другую.

**Этап 1.** Неинформированный поиск. На этом этапе известна только
топология связей между городами. Выполнить:

 - поиск в ширину; 
 - поиск глубину;
 - поиск с ограничением глубины; 
 - поиск с итеративным углублением; 
 - двунаправленный поиск.

Отобразить движение по дереву на его графе с указанием сложности каждого вида
поиска. Сделать выводы.

**Этап 2.** Информированный поиск. Воспользовавшись информацией о
протяженности связей от текущего узла, выполнить:

 - жадный поиск по первому наилучшему соответствию; 
 - затем, использую информацию о расстоянии до цели по прямой от каждого узла,
   выполнить поиск методом минимизации суммарной оценки `А*`.

Отобразить на графе выбранный маршрут и сравнить его сложность с
неинформированным поиском. Сделать выводы.

Таблица связей между городами

| Город 1     | Город 2      | Расстояние, км |
| :---:       | :---:        | :---:          |
| Вильнюс     | Брест        | 531            |
| Витебск     | Брест        | 638            |
| Витебск     | Вильнюс      | 360            |
| Воронеж     | Витебск      | 869            |
| Воронеж     | Волгоград    | 581            |
| Волгоград   | Витебск      | 1455           |
| Витебск     | Ниж.Новгород | 911            |
| Вильнюс     | Даугавпилс   | 211            |
| Калининград | Брест        | 699            |
| Калининград | Вильнюс      | 333            |
| Каунас      | Вильнюс      | 102            |
| Киев        | Вильнюс      | 734            |
| Киев        | Житомир      | 131            |
| Житомир     | Донецк       | 863            |
| Житомир     | Волгоград    | 1493           |
| Кишинев     | Киев         | 467            |
| Кишинев     | Донецк       | 812            |
| С.Петербург | Витебск      | 602            |
| С.Петербург | Калининград  | 739            |
| С.Петербург | Рига         | 641            |
| Москва      | Казань       | 815            |
| Москва      | Ниж.Новгород | 411            |
| Москва      | Минск        | 690            |
| Москва      | Донецк       | 1084           |
| Москва      | С.Петербург  | 664            |
| Мурманск    | С.Петербург  | 1412           |
| Мурманск    | Минск        | 2238           |
| Орел        | Витебск      | 522            |
| Орел        | Донецк       | 709            |
| Орел        | Москва       | 368            |
| Одесса      | Киев         | 487            |
| Рига        | Каунас       | 267            |
| Таллинн     | Рига         | 308            |
| Харьков     | Киев         | 471            |
| Харьков     | Симферополь  | 639            |
| Ярославль   | Воронеж      | 739            |
| Ярославль   | Минск        | 940            |
| Уфа         | Казань       | 525            |
| Уфа         | Самара       | 461            |

Варианты заданий:

| Номер варианта | Исходный пункт | Пункт назначения |
| :---:          | :---:          | :---:            |
| 1              | Мурманск       | Одесса           |
| 2              | С.Петербург    | Житомир          |
| 3              | Самара         | Ярославль        |
| 4              | Рига           | Уфа              |
| 5              | Казань         | Таллин           |
| 6              | Симферополь    | Мурманск         |
| 7              | Рига           | Одесса           |
| 8              | Вильнюс        | Одесса           |
| 9              | Брест          | Казань           |
| 10             | Харьков        | Ниж.Новгород     |

Расстояние до цели по прямой взять из подходящей географической карты.

Правило выбора варианта задания. Дату рождения подвергнуть следующей
свертке: `(dd + mm) mod 10 + 1 = номер варианта`