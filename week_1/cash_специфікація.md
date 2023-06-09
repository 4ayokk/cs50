# Cash Специфікація

Напишіть програму cash.c, яка питатиме у користувача, скільки решти необхідно видати, 
а потім видає мінімальну кількість монеток, за допомогою яких цей обсяг решти можна видати.

Використовуйте функцію `get_float` для того, щоб отримати вхідні дані від користувача, та `printf`, аби вивести ваш результат. 
Припускайте, що вам доступні монетки номіналом 25, 10, 5 та 1 центи.
Ми просимо вас використовувати `get_float` для того, щоб ви могли працювати з доларами і центами, відкинувши знак долара ($). 
Іншими словами, якщо певному клієнтові винні $9.75 (наприклад, газета коштувала 25 центів, але клієнт платить 10-доларовою купюрою), 
припускайте, що на вхід вашій програмі поступить величина 9.75 а не $9.75 чи 975. 
Якщо певному клієнтові винні 9 доларів рівно, припускайте, що на вхід вашій програмі поступить величина 9.00 чи 9, але, знову ж таки, не $9 або 900.

Звичайно, через природу чисел з рухомою комою, ваша програма швидше за все коректно спрацює із вводом 9.0 та 9.000, 
але вам не потрібно хвилюватись про перевірку того, чи ввід користувача є відформатованим так, як має бути відформатований грошовий ввід.
Вам не потрібно перевіряти, чи вміщаються користувацькі дані у тип даних float. Використання get_float перевірить, 
чи є вхідні дані дробовими (або ж цілими, що також допустимо для нашої задачі), але не перевірить, чи є вони невід'ємними.
    
Якщо користувач не вводить невід'ємну суму, ви повинні знову і знову просити його ввести коректну суму доти, доки це не станеться.

Ми хочемо автоматизувати перевірки вашого коду, 
тож впевніться, що останній рядок виводить лише одне число: мінімальну кількість монеток, після якої виводиться \n.
   
Остерігайтесь неточності чисел з рухомою комою. Згадайте floats.c з лекції, 
в котрій якщо x дорівнює 2 і y дорівнює 10, x / y не дорівнює точно дві десятих! 
Тож, перед тим, як видати решту, варто конвертувати введені долари на центи (тобто з float до int) 
аби уникнути невеличких помилок, які можуть накопичуватись!

Також пам’ятайте, що потрібно округлити до центів за допомогою round, яка оголошена у бібліотеці math.h. 
Наприклад, якщо dollars це float з вхідними даними від користувача (наприклад, 0.20), тоді код

` int coins = round(dollars * 100); `

безпечно конвертує 0.20 (або навіть 0.200000002980232238769531250) до 20.

Ваша програма має поводитись, як у прикладах нижче.
```
$ ./cash
Change owed: 0.41
4
```

```
$ ./cash
Change owed: -0.41
Change owed: foo
Change owed: 0.41
4
```
Посилання на курс: https://courses.prometheus.org.ua/courses/course-v1:Prometheus+CS50+2019_T1/course/
