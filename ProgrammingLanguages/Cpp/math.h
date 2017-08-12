/**
 * Math Library for artist
 */

#ifdef Q_MATH_H
#define Q_MATH_H

/**
 * Absolute of a value without if else or builtin library
 * See more: https://stackoverflow.com/questions/9772348/get-absolute-value-without-using-abs-function-nor-if-statement
 */
template <class T>
T abs(int num) {
    return num  * ((num > 0) - (num < 0));
}

/**
 * Max of two number without if-else of builtin library, in one - line
 */
template <class T>
T max(T a, T b) {
    return  ((a + b) + (a - b) * (((a - b) > 0) - ((a - b) < 0))) / 2;
}

#endif // Q_MATH_H
