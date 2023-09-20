/*
* Implementation file for FDM algorithms
*/

#include <iostream> // cout, DEBUGGING ONLY
#include <iomanip>
#include <vector>
#include "error_codes.hpp" // namespace err

/**
* solver_1
* Brute-force implementation of solving the heat equation on a
* massless wire. This follows the Python implementation.
* - Allocate memory for an TxN "matrix", with T timesteps and N
*    nodes.
* - Initialize boundary condition at left side of wire for all time
*    steps as 100 temperature units; this is a constant.
* - Create a double for-loop to iterate over time steps, and within
*    that, over nodes
* - Proceed with finite difference method node-by-node.
*
* ***** NOTES *****
* I use std::vector here to approximate the overhead of the Python
* script using a NumPy ND-array. This may be a poor approximation.
*
* Assumption: boundary condition at left side of wire at 100
* temperature units is a constant; everything else is initialized
* at 0.
*
*/
err::eErrorCode solver_1(int n_timesteps, std::vector<double> & temps_n, std::vector<double> & temps_n_plus_1, int n_nodes, float amp) {

    // set boundary at 100 temperature units
    temps_n[0]        = 100.0;
    temps_n_plus_1[0] = 100.0;

    /********** DEBUGGING ONLY **********/
    for (int i = 0; i<n_timesteps-1; ++i) {
        for (int j = 0; j<n_nodes; ++j) {

#ifdef DEBUG
            std::cout << std::fixed << std::setprecision(7) << (temps_n)[j] << " ";
#endif

            // left boudnary condition simply assigns the same value
            if (j==0) { temps_n_plus_1[j] = temps_n[j]; }

            // right boundary condition
            else if (i==n_nodes-1) {
                temps_n_plus_1[j] = amp * (temps_n[j-2] - 2*temps_n[j-1] + temps_n[j]);
            }

            else {
                temps_n_plus_1[j] = amp * (temps_n[j-1] - 2*temps_n[j] + temps_n[j+1]);
            }
        } // end node iteration
#ifdef DEBUG
        std::cout << "\n";
#endif

        // swap vectors to keep cycling through
        temps_n.swap(temps_n_plus_1);

    } // end timestep iteration
    std::flush(std::cout);

    /********** END DEBUGGING ONLY **********/


    return err::SUCCESS;

}

