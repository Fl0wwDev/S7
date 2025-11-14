#ifndef MATRIXBASE_H
#define MATRIXBASE_H


template <typename T>
class MatrixBase{
    protected:
        std::size_t rows;
        std::size_t cols;
        std::vector<T, T> data;
    public:
        MatrixBase();
        virtual void addElement(std:size_t i, std:size_t j) ;
        virtual getElement();
        virtual std::size_t getRows() const;
        virtual std::size_t getCols() const;

        virtual void display()



};

#endif