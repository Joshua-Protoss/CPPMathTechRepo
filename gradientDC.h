#ifndef GRADIENTDC_H
#define GRADIENTDC_H

#include <vector>
#include <functional>

class gradientDC
{
    public:
        // Constructor (default) / destructor
        gradientDC();
        ~gradientDC();

        // Function to add a pointer to the object function
        void SetObjectFcn(std::function<double(std::vector<double>*)> objectFcn);

};

#endif
