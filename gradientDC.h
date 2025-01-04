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

        // Function to set the start point (initial) -> set the number of degree of freedom.
        void SetStartPoint(const std::vector<double> startPoint);

        // Function to set the step size
        void SetStepSize(double stepSize);

        // Function to set the maximum number of iterations
        void SetMaxIterations(int maxIterations);

        // Function to set the gradient magnitude threshold (stopping condition)
        void SetGradientThresh(double gradientThresh);

        // Funcion to perform the optimization
        bool Optimize(std::vector<double> *funcloc, double *funcVal);


};

#endif
