[![Build Status](https://travis-ci.com/let-robots-reign/technopark_c_cpp.svg?branch=assignment-2)](https://travis-ci.com/let-robots-reign/technopark_c_cpp)
[![codecov](https://codecov.io/gh/let-robots-reign/technopark_c_cpp/branch/assignment-2/graph/badge.svg)](https://codecov.io/gh/let-robots-reign/technopark_c_cpp)

# ИЗ №2
Вариант #65
В вашем распоряжении — массив из 10 млн. структур, содержащих числовой идентификатор записи (комментария) в социальной сети, а также поля с семантикой средней оценки (целое 0 или вещественное от 1,0 до 5,0) и числа поданных голосов (неотрицательное целое). Составьте наивный алгоритм подсчета количества записей, не получивших ни единой оценки, а затем реализуйте параллельный алгоритм с использованием нескольких потоков с учетом возможной реорганизации структуры и выравнивания ее элементов по линиям кэш-памяти.