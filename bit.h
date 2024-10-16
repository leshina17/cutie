#include <iostream>
#include <cstdint>

class BitField{
    private:
        size_t _size_mem; //сколько элементов в массиве
        uint16_t* _mem;
        size_t _size_bit;
        size_t Get_mem_index(size_t n) const {
            size_t index= n/(8*sizeof(uint16_t));
            if (n>=_size_bit)
                throw "bit out of range!!"; //бит вылетел за границу нашего массива, программа дольше работать не будет (если мы не отловим это исключение)
            return index;
        }; //вернуть индекс для конкретного бита в каком элементе этот бит
        uint16_t Get_mask(size_t n) const{ //const говорит что в этом методе не изменяются поля 
            uint16_t m=1<<(n%(sizeof(uint16_t)*8)); // return 1 << (n%16);
            return m;
        };

    public:
        BitField(size_t size_bit){//соз массив //here
            _size_bit=size_bit;
            _size_mem=(size_bit/(sizeof(uint16_t)*8))+(size_bit%(sizeof(uint16_t)*8)!=0);
            _mem=new uint16_t[_size_mem];
            for (size_t i=0; i<_size_mem; ++i)
            _mem[i]=0;
        }
        BitField(const BitField& tmp){//конст копирования //here
            _size_bit=tmp._size_bit;
            _size_mem=tmp._size_mem;
            _mem=new uint16_t[_size_mem];
            for (size_t i=0; i<_size_mem; ++i)
                _mem[i]=tmp._mem[i];
        }
        BitField& operator=(const BitField& tmp){ //here //опер присва
            if (_size_bit!=tmp._size_bit){
                delete [] _mem;
                _size_bit=tmp._size_bit;
                _size_mem=tmp._size_mem;
            _mem=new uint16_t[_size_mem];
            }    
            for (size_t i=0; i<_size_mem; ++i)
                    _mem[i]=tmp._mem[i];
            return *this;
        }
        ~BitField();
        size_t Get_size() const;
        uint8_t Get_bit(size_t n) const{ // проверить выход n and _size_n=bit, получить маску 000010 внизу, получить индекс в памяти в каком элементе, побитовая кон& &!=0
            if(n>=_size_bit)
                throw "bit out of range!!";
            return ((Get_mask(n)&_mem[Get_mem_index(n)])!=0);
        } // вывести бит по индексу
        void Set_bit(size_t n){
            if(n>=_size_bit)
                throw "bit out of range!!";
            _mem[Get_mem_index(n)] |= Get_mask(n);
        }// присв n биту значение 1
        void Cer_bit(size_t n){
        } //присв n биту значение 0   
};
// перегрузка оператора вывода в консоль: вывести все биты в битовом поле



// 0-15 (карт) справа: 15 14 ... 0          31 30 ... 16
// 0000000000000001 5
// 1000000000000000 в 15 бит установить единицу
// n=16   0000000000000001 и в 16 установит единицу тоже



// 0000000000000000  
// 0000000000100000 просто делаем & get_bit вроде
// рукод

// bool operator==(const bitf& tmp)
// bitf operaor~  отрицание