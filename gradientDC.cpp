#include "gradientDC.h"
#include <iostream>
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

// Function to perform the actual optimization
bool gradientDC::Optimize(std::vector<double> *funcLoc, double *funcVal)
{
    // Set the currentPoint to the startPoint
    m_currentPoint = m_startPoint;

    // Loop up to max iterations or untill threshold reached
    int iterCount = 0;
    double gradientMagnitude = 1.0;
    while ((iterCount < m_maxIter) && (gradientMagnitude > m_gradientThresh))
    {
        // Compute the gradient vector
        std::vector<double> gradientVector = ComputeGradientVector();
        gradientMagnitude = ComputeGradientMagnitude(gradientVector);

        // Compute the new point
        std::vector<double> newPoint = m_currentPoint;
        for (int i=0; i<m_nDims; ++i)
        {
            newPoint[i] += -(gradientVector[i] * m_stepSize);
        }

        // Update the current point
        m_currentPoint = newPoint;

        // Increment the iteration counter
        iterCount++;
    }

    // Return the results
    *funcLoc = m_currentPoint;
    *funcVal = m_objectFcn(&m_currentPoint);

    return 0;
}

/* Function to compute the gradient of the object function in the specified dimension*/
double gradientDC::ComputedGradient(int dim)
{
    // Make a copy of the current location
    std::vector<double> newPoint = m_currentPoint;

    // Modify the copy, according to h and dim
    newPoint[dim] += m_h;

    // Compute the two function values for these points
    double funcVal1 = m_objectFcn(&m_currentPoint);
    double funcVal2 = m_objectFcn(&newPoint);

    // Compute the approximate numerical gradient
    return (funcVal2 - funcVal1) / m_h;
}

// Function to compute the gradient vector
std::vector<double> gradientDC::ComputeGradientVector()
{
    std::vector<double> gradientVector = m_currentPoint;
    for (int i=0; i<m_nDims; ++i)
        gradientVector[i] = ComputedGradient(i);
    return gradientVector;
}

// Function to compute the gradient magnitude
double gradientDC::ComputeGradientMagnitude(std::vector<double> gradientVector)
{
    double vectorMagnitude = 0.0;
    for (int i=0; i<m_nDims; ++i)
        vectorMagnitude += gradientVector[i] * gradientVector[i];
    return sqrt(vectorMagnitude);
}
