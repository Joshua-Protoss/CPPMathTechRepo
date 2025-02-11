#include <math.h>
#include <complex>
#include <vector>
#include <iostream>
#include <iomanip>

std::vector<std::complex<double>> dft(std::vector<std::complex<double>> X){
    // Determine number of samples
    int N = X.size();
    int K = N;

    // Allocate memory for internals
    std::complex<double> intSum;

    // Allocate memory for output
    std::vector<std::complex<double>> output;
    output.reserve(K);

    // Loop through K
    for (int k=0; k<K; k++)
    {
        // Loop through N
        intSum = std::complex<double>(0, 0);
        for (int n =0; n<N; n++)
        {
            double realPart = cos(((2*M_PI)/N) * k * n);
            double imagPart = sin(((2*M_PI)/N) * k * n);
            std::complex<double> w (realPart, -imagPart);
            intSum += X[n] * w;
        }
        output.push_back(intSum);
    }
    return output;
}

int main()
{
    // Create test signal
    int N = 1000;
    std::vector<std::complex<double>> signal;
    signal.reserve(N);

    double sigK = 3.0; // double sigPhase = M_PI/4.0; add phase
    double sigPhase = 0.0;

    for (int x=0; x<N; ++x)
    {
        auto currentSample = std::complex<double>
            (cos((2*M_PI/static_cast<double>(N)) * sigK
            * static_cast<double>(x) + sigPhase), 0.0 );
        signal.push_back(currentSample);
    }

    // Compute DFT
    std::vector<std::complex<double>> Fx = dft(signal);

    // Diplay the first six values (real and imaginary components)
    std::cout << "First 6 samples from the output..." << std::endl;
    std::cout << "\n" << "k\t" << std::setw(12) << "Real\t" << std::setw(12) << "Imag" << std::endl;

    for (int i=0; i<6; ++i){
        std::cout << i << "\t" << std::setw(12) << Fx[i].real() / static_cast<double>(N) << "\t"
            << std::setw(12) << Fx[i].imag() / static_cast<double>(N) 
            << std::endl;
    } 
    return 0;

}
