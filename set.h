#include "bit.h"

class Set{
    private:
        BitField _bitField;
        size_t _maxPower;// gggg
    public:
        Set(size_t mp);
        Set(const Set&  set);
        Set(const BitField& bf);//конструктор преобразования
        operator BitField(); //перегрузка (), чтобы static cast работал
        
        size_t GetMaxPower();
        void InsertElem(uint64_t elem);
        void DeleteElem(uint64_t elem);
        bool IsMember(uint64_t elem);

        bool operator==(const Set& tmp);
        Set& operator=(const Set& tmp);
        Set& operator+(const Set& tmp); // объединение множеств
        Set operator+(uint16_t elem); //добавление элемента
        Set operator-(uint16_t elem); //удаление элемента
        Set operator*(const Set& elem); //пересечение
        Set operator~();

        friend std::istream& operator>>(std::istream& istr, Set& set);
        friend std::ostream& operator<<(std::ostream& istr, const Set& set);
};