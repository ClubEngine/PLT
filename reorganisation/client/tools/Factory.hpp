#ifndef FACTORY_HPP
#define FACTORY_HPP

template<class Product, class ProductID> class Factory
{
    public:
        Factory()
        {
        }
        virtual ~Factory()
        {
        }
    protected:
        virtual Product* create(ProductID id) = 0;
};

#endif
