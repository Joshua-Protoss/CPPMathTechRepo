#include "gradientDC.cpp"
#include <iostream>
#include <functional>

// Define the object function
double ObjectFcn(std::vector<double> *funcLoc)
{
    // y = x^2
    double x = funcLoc->at(0);
    return (x * x);

}

int main(int argc, char* argv[])
{
    // Create a function pointer for our object function
    std::function<double(std::vector<double>*)> p_ObjectFcn{ObjectFcn};

    // Create a test instance of the gradientDC class
    gradientDC solver;

    // Assign the object function
    solver.SetObjectFcn(p_ObjectFcn);

    // Set a start point
    std::vector<double> startPoint = {-1.0};
    solver.SetStartPoint(startPoint);

    // Set the maximum number of iterations
    solver.SetMaxIterations(50);

    // Set the step size
    solver.SetStepSize(0.2);

    // Optimize function
    std::vector<double> funcLoc;
    double funcVal;
    solver.Optimize(&funcLoc, &funcVal);

    // Show result
    std::cout << "Function location: " << funcLoc[0] << std::endl;
    std::cout << "Function value: " << funcVal << std::endl;

    return 0;
}
