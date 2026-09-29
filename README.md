# Лабораторная работа 2

---

## Задание 1

Пять ключевых слов для каждого языка:

| Язык | Ключевые слова |
|---|---|
| C++ | `int`, `return`, `if`, `while`, `class` |
| Java | `int`, `return`, `if`, `while`, `class` |
| Python | `def`, `return`, `if`, `for`, `class` |

Во всех трех языках все пять ключевых слов нельзя использовать как имя переменной, так как ключевое слово имеет специальное значение в синтаксисе языка, поэтому объявить переменную с таким именем нельзя.

---

## Задание 2

### C++

```cpp
int a = 1, b = 2;
int c = a++b;
```

Последовательность токенов:

```
int | c | = | a | ++ | b | ;
```

В C++ последовательность `a++b` разбирается именно как `a | ++ | b`. Оператор `++` является унарным и применяется к `a`, после чего сразу встречается `b`, но между ними нет оператора. Поэтому выражение синтаксически неверно.

### Python

```python
a = 1
b = 2
c = a++b
```

Последовательность токенов:

```text
c | = | a | + | + | b
```

В Python `++` не является отдельным оператором. Здесь это два оператора `+`: первый — бинарный, второй — унарный. Поэтому выражение разбирается как:

```python
c = a + (+b)
```

При `a = 1` и `b = 2` получаем `c = 3`.

Таким образом, программа на Python синтаксически корректна и выполняется без ошибки.

## Задание 3

Программа:

```cpp
int a = 1, b = 2;
int c = a+++b;
```

Токенизация строки:

```
int | c | = | a | ++ | + | b | ;
```

Токенизатор выбирает максимально длинный подходящий токен. Поэтому первые два плюса образуют оператор `++`, а третий — оператор `+`.

1. `a++` использует старое значение `a`, то есть `1`, и после этого увеличивает `a` до `2`.
2. Полученное старое значение `1` складывается с `b`, равным `2`.
3. Поэтому `c = 3`.

Пробелы могут изменить разбиение. Например:

```cpp
int c = a + ++b;
```

Токены здесь:

```
a | + | ++ | b
```

Теперь сначала увеличивается `b`: `b` становится `3`, затем вычисляется `a + 3`, поэтому `c = 4`.

Таким образом, вставка пробелов *может* изменить токенизацию и смысл программы.

---

## Задание 4

### Круглые скобки как оператор

1. Вызов функции `f(x)`:

Здесь `()` — оператор вызова функции.

2. Изменение порядка вычисления `a = (b + c) * d;`.

Здесь скобки задают группировку выражения.

### Круглые скобки не как оператор

В конструкции `if` скобки являются частью синтаксиса условной инструкции:

```cpp
if (x > 0) {
    cout << x;
}
```

### Квадратные скобки как оператор

Индексация массива `a[i]`:

Здесь `[]` — оператор индексирования.

### Квадратные скобки не как оператор

В объявлении массива `int a[10];`:

`[10]` задаёт размер массива и является частью синтаксиса объявления, а не операцией индексирования уже существующего объекта.

---

## Задание 5

Программа:

```python
print(*map(sum, zip(
    *[map(int, input().split()) for i in (1, 2, 3)]
)))
```

Ключевые слова: `for, in`.
Идентификаторы: `print, map, sum, zip, int, input, split, i`.
Литералы: `1, 2, 3`.
Оператор: `*`.

- `i` — переменная цикла
- `print` — функция вывода
- `map` — функция преобразования/отображения элементов
- `sum` — функция суммирования
- `zip` — функция объединения последовательностей по позициям
- `int` — функция преобразования в целое число
- `input` — функция чтения строки
- `split` — метод строки, разбивающий ее

### Вызываемые функции и параметры

```python
print(...)
```

Печатает данную через запятую или при распаковке последовательность с заданными сепаратором и концом (аргументом является последовательность, полученная после распаковки `map`).

```python
map(sum, ...)
```

Для каждого элемента переданной вторым аргументом последовательности применяет функцию (`sum`), поданную первым аргументом.

```python
zip(...)
```

Объединяет полученные через запятую или при распаковке (три) последовательности по позициям.

```python
map(int, ...)
```

Преобразует элементы подаваемой последовательности (в данном случае, строки) в целые числа.

```python
input()
```

Считывает одну строку.

```python
input().split()
```

Разбивает введённую строку по пробелам (по умолчанию).

```python
sum(...)
```

Явно не вызывается, но при выполнении складывает элементы одной из последовательностей, передаваемых в `map`.

### Что делает программа

Программа три раза читает строку чисел:

```python
for i in (1, 2, 3)
```

Переменная `i` нужна только для выполнения цикла три раза.

Для каждой строки:

1. `input()` читает строку
2. `split()` разбивает её на отдельные значения по пробелам
3. `map(int, ...)` превращает значения в числа

Получаются три последовательности чисел. `zip` объединяет их по столбцам. Затем `map(sum, ...)` считает сумму каждого столбца. `print(*...)` распаковывает полученные суммы и выводит их через пробел.

Например, для ввода:

```
1 2 3
10 20 30
100 200 300
```

получится `111 222 333`.

---

## Задание 6

В C++ используются два вида комментариев:

```cpp
// однострочный комментарий
```

и

```cpp
/* многострочный комментарий */
```

Комментарии не участвуют в дальнейшем разборе программы.

### 1. Строковый литерал

```cpp
cout << "Hello /* Это комментарий */ world";
```

Синтаксически **верно.**

`/* Это комментарий */` находится внутри строкового литерала, поэтому это обычный текст строки, а не комментарий.

### 2. Однострочный комментарий

```cpp
// /*
 Это комментарий
*/
```

Синтаксически **неверно.**

После `//` до конца первой строки всё является комментарием. `/*` поэтому не открывает многострочный комментарий. Следующие строки уже не являются частью `//`-комментария, а отдельный `*/` не имеет соответствующего `/*`.

### 3. Вложенный многострочный комментарий

```cpp
/* Я комментирую программы /* комментарий */ */
```

Синтаксически **неверно.**

Многострочные комментарии в C++ не поддерживают вложенность. Первый `*/` завершает комментарий, а последний `*/` остаётся лишним.

### 4. Однострочный комментарий

```cpp
// Я комментирую программы /* комментарий */
```

Синтаксически **верно.**

Вся строка после `//` игнорируется. Последовательность `/* ... */` внутри неё ничего не меняет.

### 5. Многострочный комментарий с `//`

```cpp
/* Я комментирую свои программы
// Это комментарий до конца строки */
*/
```

Синтаксически **неверно.**

`//` внутри уже открытого `/* ... */` не создаёт отдельного комментария: весь текст до первого `*/` остаётся частью многострочного комментария. После этого остаётся ещё один `*/`, для которого нет открывающего `/*`.

---

## Задание 7

В правиле `iteration-statement` четыре варианта циклов:

```
iteration-statement:
    while ( condition ) statement
    do statement while ( expression ) ;
    for ( init-statement conditionopt ; expressionopt ) statement
    for ( for-range-declaration : for-range-initializer ) statement
```

Таким образом, есть **четыре** синтаксических вида инструкций циклов.

### 1. Цикл `while`

Правило:

```
while ( condition ) statement
```

Сначала записывается `while`, затем в круглых скобках — условие `condition`, после него — выполняемая инструкция `statement`.

Пример:

```cpp
int x = 1;

while (x < 1000) {
    cout << x;
    x *= 2;
}
```

### 2. Цикл `do ... while`

Правило:

```
do statement while ( expression ) ;
```

Сначала записывается `do`, затем инструкция `statement`. После неё записывается `while`, условие в круглых скобках и `;`.

Главное отличие от `while`: тело цикла выполняется до проверки условия.

Пример:

```cpp
int x = 1;

do {
    cout << x;
    x *= 2;
} while (x < 1000);
```

### 3. Обычный цикл `for`

Правило:

```
for ( init-statement conditionopt ; expressionopt ) statement
```

В круглых скобках находятся:

- начальная инструкция `init-statement`;
- необязательное условие `condition`;
- необязательное выражение `expression`.

После второй части обязательно ставится `;`, затем идёт тело цикла.

Пример:

```cpp
for (int i = 0; i < 10; ++i) {
    cout << i;
}
```

### 4. Цикл `for` по диапазону

Правило:

```
for ( for-range-declaration : for-range-initializer ) statement
```

Объявляется переменная цикла, после `:` задаётся объект или диапазон, по которому выполняется перебор.

Пример:

```cpp
int a[] = {1, 2, 3};

for (int x : a) {
    cout << x;
}
```

---

## Задание 8

Нужно построить абстрактное синтаксическое дерево для выражения `a = -x + y * (z - 1);`

Сначала учитываем приоритет операций:

1. скобки `(z - 1)`;
2. унарный `-x`;
3. умножение `y * (z - 1)`;
4. сложение `-x + ...`;
5. присваивание результата переменной `a`.

Упрощённое абстрактное синтаксическое дерево:

```
=
├── a
└── +
    ├── unary-
    │   └── x
    └── *
        ├── y
        └── -
            ├── z
            └── 1
```

Токены, не влияющие на структуру исполняемого кода напрямую, в абстрактном дереве не нужны. Например, `;` и скобки группировки не становятся отдельными узлами.

---

## Задание 9

Для разбора выбрана короткая программа на C++, в которой есть `for`, вложенное `if` и несколько вычислений:

```cpp
#include <iostream>

int main() {
    int s = 0;

    for (int i = 1; i <= 5; ++i) {
        int x = i * 2;

        if (x % 3 == 0) {
            s = s + x;
        } else {
            s = s + x * 2;
        }
    }

    std::cout << s;
    return 0;
}
```

Программа вычисляет сумму по четным `x` из отрезка `[2, 10]`: если `x` делится на 3, к `s` прибавляется `x`, иначе — `2 * x`.

### 9.1. Последовательность токенов

Комментарии и пробельные символы в последовательность токенов не входят.

```
# | include | < | iostream | >
int | main | ( | ) | {
int | s | = | 0 | ;
for | ( |
    int | i | = | 1 | ;
    i | <= | 5 | ;
    ++ | i |
) {
    int | x | = | i | * | 2 | ;

    if | ( | x | % | 3 | == | 0 | ) {
        s | = | s | + | x | ;
    } else {
        s | = | s | + | x | * | 2 | ;
    }
}
std | :: | cout | << | s | ;
return | 0 | ;
}
```

Основные классы токенов:

- ключевые слова: `int, for, if, else, return`;
- идентификаторы: `main, s, i, x, std, cout`;
- литералы: `0, 1, 2, 3, 5`;
- операторы: `=, <=, ++, *, %, ==, +, <<`;
- пунктуаторы: `(`, `)`, `{`, `}`, `;`, `::`, `,`, а также служебные символы директивы `#include`.

### 9.2 Полное синтаксическое дерево разбора

```
program
└── translation_unit
    ├── preprocessor_directive
    │   ├── '#'
    │   ├── '<'
    │   ├── identifier: iostream
    │   └── '>'
    └── function_definition
        ├── type_specifier: int
        ├── identifier: main
        ├── '('
        ├── parameter_list: ε
        ├── ')'
        └── compound_statement
            ├── '{'
            ├── statement_list
            │   ├── variable_declaration
            │   │   ├── type_specifier: int
            │   │   ├── identifier: s
            │   │   ├── '='
            │   │   ├── expression
            │   │   │   └── assignment_expression
            │   │   │       └── conditional_expression
            │   │   │           └── logical_or_expression
            │   │   │               └── logical_and_expression
            │   │   │                   └── equality_expression
            │   │   │                       ── relational_expression
            │   │   │                           └── additive_expression
            │   │   │                               └── multiplicative_expression
            │   │   │                                   └── unary_expression
            │   │   │                                       └── postfix_expression
            │   │   │                                           └── primary_expression
            │   │   │                                               └── constant: 0
            │   │   └── ';'
            │   └── statement_list
            │       ├── for_statement
            │       │   ├── 'for'
            │       │   ├── '('
            │       │   ├── for_init
            │       │   │   └── variable_declaration
            │       │   │       ├── type_specifier: int
            │       │   │       ├── identifier: i
            │       │   │       ├── '='
            │       │   │       ├── expression
            │       │   │       │   └── assignment_expression
            │       │   │       │       ── conditional_expression
            │       │   │       │           └── logical_or_expression
            │       │   │       │               └── logical_and_expression
            │       │   │       │                   ── equality_expression
            │       │   │       │                       └── relational_expression
            │       │   │       │                           └── additive_expression
            │       │   │       │                               └── multiplicative_expression
            │       │   │       │                                   └── unary_expression
            │       │   │       │                                       └── postfix_expression
            │       │   │       │                                           └── primary_expression
            │       │   │       │                                               └── constant: 1
            │       │   │       └── ';'
            │       │   ├── for_condition
            │       │   │   └── expression
            │       │   │       └── assignment_expression
            │       │   │           └── conditional_expression
            │       │   │               └── logical_or_expression
            │       │   │                   └── logical_and_expression
            │       │   │                       └── equality_expression
            │       │   │                           └── relational_expression
            │       │   │                               ├── relational_expression
            │       │   │                               │   └── additive_expression
            │       │   │                               │       └── multiplicative_expression
            │       │   │                               │           └── unary_expression
            │       │   │                               │               └── postfix_expression
            │       │   │                               │                   └── primary_expression
            │       │   │                               │                       └── identifier: i
            │       │   │                               ├── '<='
            │       │   │                               └── additive_expression
            │       │   │                                   └── multiplicative_expression
            │       │   │                                       └── unary_expression
            │       │   │                                           └── postfix_expression
            │       │   │                                               └── primary_expression
            │       │   │                                                   └── constant: 5
            │       │   ├── ';'
            │       │   ├── for_increment
            │       │   │   └── expression
            │       │   │       └── assignment_expression
            │       │   │           └── conditional_expression
            │       │   │               └── logical_or_expression
            │       │   │                   ── logical_and_expression
            │       │   │                       └── equality_expression
            │       │   │                           └── relational_expression
            │       │   │                               └── additive_expression
            │       │   │                                   └── multiplicative_expression
            │       │   │                                       └── unary_expression
            │       │   │                                           ├── unary_operator: ++
            │       │   │                                           └── unary_expression
            │       │   │                                               └── postfix_expression
            │       │   │                                                   └── primary_expression
            │       │   │                                                       └── identifier: i
            │       │   ├── ')'
            │       │   └── compound_statement
            │       │       ├── '{'
            │       │       ├── statement_list
            │       │       │   ├── variable_declaration
            │       │       │   │   ├── type_specifier: int
            │       │       │   │   ├── identifier: x
            │       │       │   │   ├── '='
            │       │       │   │   ├── expression
            │       │       │   │   │   └── assignment_expression
            │       │       │   │   │       └── conditional_expression
            │       │       │   │   │           └── logical_or_expression
            │       │       │   │   │               └── logical_and_expression
            │       │       │   │   │                   └── equality_expression
            │       │       │   │   │                       └── relational_expression
            │       │       │   │   │                           └── additive_expression
            │       │       │   │   │                               └── multiplicative_expression
            │       │       │   │   │                                   ├── multiplicative_expression
            │       │       │   │   │                                   │   └── unary_expression
            │       │       │   │   │                                   │       └── postfix_expression
            │       │       │   │   │                                   │           └── primary_expression
            │       │       │   │   │                                   │               └── identifier: i
            │       │       │   │   │                                   ├── '*'
            │       │       │   │   │                                   └── unary_expression
            │       │       │   │   │                                       └── postfix_expression
            │       │       │   │   │                                           └── primary_expression
            │       │       │   │   │                                               └── constant: 2
            │       │       │   │   └── ';'
            │       │       │   └── statement_list
            │       │       │       ├── if_statement
            │       │       │       │   ├── 'if'
            │       │       │       │   ├── '('
            │       │       │       │   ├── expression
            │       │       │       │   │   └── assignment_expression
            │       │       │       │   │       └── conditional_expression
            │       │       │       │   │           └── logical_or_expression
            │       │       │       │   │               └── logical_and_expression
            │       │       │       │   │                   └── equality_expression
            │       │       │       │   │                       ├── equality_expression
            │       │       │       │   │                       │   └── relational_expression
            │       │       │       │   │                       │       └── additive_expression
            │       │       │       │   │                       │           └── multiplicative_expression
            │       │       │       │   │                       │               ├── multiplicative_expression
            │       │       │       │   │                       │               │   └── unary_expression
            │       │       │       │   │                       │               │       ── postfix_expression
            │       │       │       │   │                       │               │           └── primary_expression
            │       │       │       │   │                       │               │               └── identifier: x
            │       │       │       │   │                       │               ├── '%'
            │       │       │       │   │                       │               └── unary_expression
            │       │       │       │   │                       │                   └── postfix_expression
            │       │       │       │   │                       │                       └── primary_expression
            │       │       │       │   │                       │                           └── constant: 3
            │       │       │       │   │                       ├── '=='
            │       │       │       │   │                       └── relational_expression
            │       │       │       │   │                           └── additive_expression
            │       │       │       │   │                               └── multiplicative_expression
            │       │       │       │   │                                   └── unary_expression
            │       │       │       │   │                                       └── postfix_expression
            │       │       │       │   │                                           └── primary_expression
            │       │       │       │   │                                               └── constant: 0
            │       │       │       │   ├── ')'
            │       │       │       │   ├── compound_statement
            │       │       │       │   │   ├── '{'
            │       │       │       │   │   ├── statement_list
            │       │       │       │   │   │   └── assignment_statement
            │       │       │       │   │   │       ├── identifier: s
            │       │       │       │   │   │       ├── '='
            │       │       │       │   │   │       ├── expression
            │       │       │       │   │   │       │   └── assignment_expression
            │       │       │       │   │   │       │       └── conditional_expression
            │       │       │       │   │   │       │           └── logical_or_expression
            │       │       │       │   │   │       │               └── logical_and_expression
            │       │       │       │   │   │       │                   └── equality_expression
            │       │       │       │   │   │       │                       └── relational_expression
            │       │       │       │   │   │       │                           └── additive_expression
            │       │       │       │   │   │       │                               ├── additive_expression
            │       │       │       │   │   │       │                               │   └── multiplicative_expression
            │       │       │       │   │   │       │                               │       └── unary_expression
            │       │       │       │   │   │       │                               │           └── postfix_expression
            │       │       │       │   │   │       │                               │               └── primary_expression
            │       │       │       │   │   │       │                               │                   └── identifier: s
            │       │       │       │   │   │       │                               ├── '+'
            │       │       │       │   │   │       │                               └── multiplicative_expression
            │       │       │       │   │   │       │                                   └── unary_expression
            │       │       │       │   │   │       │                                       └── postfix_expression
            │       │       │       │   │   │       │                                           └── primary_expression
            │       │       │       │   │   │       │                                               ── identifier: x
            │       │       │       │   │   │       └── ';'
            │       │       │       │   │   └── '}'
            │       │       │       │   ├── else_clause
            │       │       │       │   │   ├── 'else'
            │       │       │       │   │   └── compound_statement
            │       │       │       │   │       ├── '{'
            │       │       │       │   │       ├── statement_list
            │       │       │       │   │       │   └── assignment_statement
            │       │       │       │   │       │       ├── identifier: s
            │       │       │       │   │       │       ├── '='
            │       │       │       │   │       │       ├── expression
            │       │       │       │   │       │       │   └── assignment_expression
            │       │       │       │   │       │       │       └── conditional_expression
            │       │       │       │   │       │       │           └── logical_or_expression
            │       │       │       │   │       │       │               └── logical_and_expression
            │       │       │       │   │       │       │                   └── equality_expression
            │       │       │       │   │       │       │                       └── relational_expression
            │       │       │       │   │       │       │                           └── additive_expression
            │       │       │       │   │       │       │                               ├── additive_expression
            │       │       │       │   │       │       │                               │   └── multiplicative_expression
            │       │       │       │   │       │       │                               │       └── unary_expression
            │       │       │       │   │       │       │                               │           └── postfix_expression
            │       │       │       │   │       │       │                               │               └── primary_expression
            │       │       │       │   │       │       │                               │                   ── identifier: s
            │       │       │       │   │       │       │                               ├── '+'
            │       │       │       │   │       │       │                               └── multiplicative_expression
            │       │       │       │   │       │       │                                   ├── multiplicative_expression
            │       │       │       │   │       │       │                                   │   └── unary_expression
            │       │       │       │   │       │       │                                   │       └── postfix_expression
            │       │       │       │   │       │       │                                   │           └── primary_expression
            │       │       │       │   │       │       │                                   │               └── identifier: x
            │       │       │       │   │       │       │                                   ├── '*'
            │       │       │       │   │       │       │                                   └── unary_expression
            │       │       │       │   │       │       │                                       └── postfix_expression
            │       │       │       │   │       │       │                                           └── primary_expression
            │       │       │       │   │       │       │                                               └── constant: 2
            │       │       │       │   │       │       └── ';'
            │       │       │       │   │       └── '}'
            │       │       │       │   └── '}'
            │       │       │       └── '}'
            │       └── '}'
            ├── statement_list
            │   └── expression_statement
            │       ├── expression
            │       │   └── assignment_expression
            │       │       └── conditional_expression
            │       │           └── logical_or_expression
            │       │               └── logical_and_expression
            │       │                   └── equality_expression
            │       │                       └── relational_expression
            │       │                           └── additive_expression
            │       │                               └── multiplicative_expression
            │       │                                   └── unary_expression
            │       │                                       └── postfix_expression
            │       │                                           ├── postfix_expression
            │       │                                           │   └── primary_expression
            │       │                                           │       └── identifier: std
            │       │                                           ├── '::'
            │       │                                           └── identifier: cout
            │       │   ├── '<<'
            │       │   └── expression
            │       │       └── assignment_expression
            │       │           └── conditional_expression
            │       │               └── logical_or_expression
            │       │                   └── logical_and_expression
            │       │                       └── equality_expression
            │       │                           └── relational_expression
            │       │                               └── additive_expression
            │       │                                   └── multiplicative_expression
            │       │                                       └── unary_expression
            │       │                                           └── postfix_expression
            │       │                                               └── primary_expression
            │       │                                                   └── identifier: s
            │       └── ';'
            └── statement_list
                └── return_statement
                    ├── 'return'
                    ├── expression
                    │   └── assignment_expression
                    │       └── conditional_expression
                    │           └── logical_or_expression
                    │               └── logical_and_expression
                    │                   ── equality_expression
                    │                       └── relational_expression
                    │                           └── additive_expression
                    │                               └── multiplicative_expression
                    │                                   └── unary_expression
                    │                                       ── postfix_expression
                    │                                           └── primary_expression
                    │                                               └── constant: 0
                    └── ';'
            └── '}'
```

### 9.3 Абстрактное синтаксическое дерево

```
function-definition
├── name: main
├── return-type: int
└── body
    ├── declaration
    │   ├── type: int
    │   ├── name: s
    │   └── init: 0
    ├── for-loop
    │   ├── init
    │   │   ├── type: int
    │   │   ├── name: i
    │   │   └── init: 1
    │   ├── condition
    │   │   └── <=
    │   │       ├── i
    │   │       └── 5
    │   ├── increment
    │   │   └── ++
    │   │       └── i
    │   └── body
    │       ├── declaration
    │       │   ├── type: int
    │       │   ├── name: x
    │       │   └── init
    │       │       └── *
    │       │           ├── i
    │       │           ── 2
    │       └── if-else
    │           ├── condition
    │           │   └── ==
    │           │       ├── %
    │           │       │   ├── x
    │           │       │   └── 3
    │           │       └── 0
    │           ├── then
    │           │   └── =
    │           │       ├── s
    │           │       └── +
    │           │           ├── s
    │           │           └── x
    │           └── else
    │               ── =
    │                   ├── s
    │                   └── +
    │                       ├── s
    │                       └── *
    │                           ├── x
    │                           └── 2
    ├── expression-statement
    │   └── <<
    │       ├── cout
    │       └── s
    └── return
        └── 0
```

### 9.4 Соответствия с ассемблерным кодом

| Элемент AST | Соответствующий код в `a.s` | Пояснение |
|---|---|---|
| `declaration: int s = 0` | `stur wzr, [x29, #-4]` / `str wzr, [sp, #8]` | Запись нуля (регистр `wzr`) в ячейку памяти, отведённую под переменную `s` |
| `init: int i = 1` | `mov w8, #1` / `str w8, [sp, #4]` | Загрузка константы 1 в регистр `w8` и сохранение в ячейку переменной `i` |
| `condition: i <= 5` | `ldr w8, [sp, #4]` / `subs w8, w8, #5` / `b.gt LBB0_7` | Загрузка `i`, вычитание 5 с установкой флагов; переход к выходу из цикла, если `i > 5` |
| `increment: ++i` | `ldr w8, [sp, #4]` / `add w8, w8, #1` / `str w8, [sp, #4]` (блок `LBB0_6`) | Загрузка `i`, инкремент на 1, сохранение результата обратно в память |
| `x = i * 2` | `ldr w8, [sp, #4]` / `lsl w8, w8, #1` / `str w8, [sp]` | Загрузка `i`, умножение на 2 через логический сдвиг влево на 1 бит, сохранение в ячейку `x` |
| `x % 3 == 0` | `ldr w8, [sp]` / `mov w10, #3` / `sdiv w9, w8, w10` / `mul w9, w9, w10` / `subs w8, w8, w9` / `cbnz w8, LBB0_4` | Вычисление остатка от деления `x` на 3 как `x - (x/3)*3`; переход к ветке `else`, если остаток не равен нулю |
| `s = s + x` (ветка `then`) | `ldr w8, [sp, #8]` / `ldr w9, [sp]` / `add w8, w8, w9` / `str w8, [sp, #8]` (блок `LBB0_3`) | Загрузка `s` и `x`, их сложение, сохранение результата обратно в `s` |
| `s = s + x * 2` (ветка `else`) | `ldr w8, [sp, #8]` / `ldr w9, [sp]` / `add w8, w8, w9, lsl #1` / `str w8, [sp, #8]` (блок `LBB0_4`) | Загрузка `s` и `x`, сложение `s` с `x*2` (умножение реализовано через `lsl #1`), сохранение в `s` |
| `cout << s` | `ldr w1, [sp, #8]` / `adrp x0, __ZNSt3__14coutE@GOTPAGE` / `ldr x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]` / `bl __ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi` | Загрузка значения `s` в регистр аргумента `w1`, получение адреса `std::cout`, вызов метода `operator<<(int)` |
| `return 0` | `mov w0, #0` | Запись 0 в регистр возвращаемого значения `w0` |

