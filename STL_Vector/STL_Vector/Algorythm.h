#pragma once
template <typename T, class T1>
T Find_if(T begin, T end, T1 other)
{
    while (begin != end)
    {
        if (other(*begin))
        {
            return begin;
        }
        ++begin;
    }
    return end;
}
template<class T>
T Min_element(T begin, T end)
{
    T Min = begin;
    ++begin;
    while (begin != end)
    {
        if (*begin < *Min)
        {
            Min = begin;
        }
        ++begin;
    }
   return Min;
}
template<class T>
T Max_element(T begin, T end)
{
    T Max = begin;
    ++begin;
    while (begin != end)
    {
        if (*begin > * Max)
        {
            Max = begin;
        }
        ++begin;
    }
    return Max;
}

// http://www.cplusplus.com/reference/algorithm/for_each/?kw=for_each
template<class T, class T1>
T1 For_each(T begin, T end, T1 other)
{
    while (begin != end)
    {
        other(*begin);
        ++begin;
    }
    // КОМПИЛЯТОР В ДАННОМ СЛУЧАЕ ПО УМОЛЧАНИЮ ДОЛЖЕН ПРИМЕНЯТЬ move
    // ПОЧИТАЙ 5.3 У МЕЙЕРСА ПРО ОПТИМИЗАЦИЮ ВОЗВРАЩАЕМЫХ ЗНАЧЕНИЙ ИЗ ФУНКЦИИ
    return move(other);
}
template<class T, class T2>
void sort(T begin, T end, T2 other)
{
    while (end - begin != (end - begin) / 2)
    {
        T cur = begin, c_end = end - 1;
        while (c_end != cur)
        {
            if (other(*cur, *c_end))
            {
                T t = end;
                *t = *cur;
                *cur = *c_end;
                *c_end = *t;
            }
            --c_end;
        }
        ++begin;
    }
}

// http://www.cplusplus.com/reference/algorithm/copy_if/?kw=copy_if
template<class T, class T1,class T2>
T1 copy_if(T begin, T end, T1 pos, T2 other)
{
    while (begin != end)
    {
        if (other(*begin))
        {
            *pos = *begin;
            ++pos;
        }
        ++begin;
    }
    return pos;
}
