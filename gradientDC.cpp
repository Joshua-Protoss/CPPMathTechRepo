#include "gradientDC.h"
#include <iostream>
#include <fstream>
#include <math.h>

// Initialize Constructor
gradientDC::gradientDC()
{
    // Default parameters
    m_nDims = 0;
    m_stepSize = 0.0;
    m_maxIter = 1;
    m_h = 0.001;
    m_gradientThresh = 1e-09;
}

// Destructor
gradientDC::~gradientDC()
{

}

// Function to set the object function
void gradientDC::SetObjectFcn(std::function<double(std::vector<double>*)> objectFcn)
{
    m_objectFcn = objectFcn;
}

// Function to set the start point and degree of freedom
void gradientDC::SetStartPoint(const std::vector<double> startPoint)
{
    // Copy the start point
    m_startPoint = startPoint;

    // Determine the number of degrees of freedom
    m_nDims = m_startPoint.size();
}

// Function to set the step size
void gradientDC::SetStepSize(double stepSize)
{
    m_stepSize = stepSize;
}

// Function to set the maximum number number of iterations
void gradientDC::SetMaxIterations(int maxIterations)
{
    m_maxIter = maxIterations;
}

// Function to set the gradient magnitude threshold (stopping condition)
// The optimization stops when the gradient magnitude falls below this value
void gradientDC::SetGradientThresh(double gradientThresh)
{
    m_gradientThresh = gradientThresh;
}
