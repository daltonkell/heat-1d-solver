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
err::eErrorCode solver_1(int n_timesteps, int n_nodes, float amp) {

    // create vector of vector<float> n_timesteps x n_nodes to represent
    // a "temperature matrix"
    std::vector<std::vector<float>> *t_matrix_p =
        new std::vector<std::vector<float>>(n_timesteps, std::vector<float>(n_nodes));

    // set boundary at 100 temperature units
    for (int i=0; i<n_timesteps; ++i) {
#ifdef DEBUG
        std::cout << i << std::endl;
#endif
        (*t_matrix_p)[i][0] = 100.0;
    }

    /********** DEBUGGING ONLY **********/
    for (int i = 0; i<n_timesteps-1; ++i) {
        for (int j = 0; j<n_nodes; ++j) {

#ifdef DEBUG
            std::cout << std::fixed << std::setprecision(5) << (*t_matrix_p)[i][j] << " ";
#endif

            // left boudnary condition
            if (j==0) { (*t_matrix_p)[i+1][j] = (*t_matrix_p)[i][j]; }

            // right boundary condition
            else if (i==n_nodes-1) {
                (*t_matrix_p)[i+1][j] = amp * ((*t_matrix_p)[i][j-2] - 2*(*t_matrix_p)[i][j-1] + (*t_matrix_p)[i][j]);
            }

            else {
                (*t_matrix_p)[i+1][j] = amp * ((*t_matrix_p)[i][j-1] - 2*(*t_matrix_p)[i][j] + (*t_matrix_p)[i][j+1]);
            }
        }
#ifdef DEBUG
        std::cout << "\n";
#endif
    }
    std::flush(std::cout);
    /********** DEBUGGING ONLY **********/

    delete t_matrix_p;

    return err::SUCCESS;

}

