/**
 * Header file for different algorithms to compute 1-D finite difference method solution.
 */

#ifndef ALGS_H
#define ALGS_H

#include <vector>
#include <string>
#include "error_codes.hpp" // namespace err


/**
* solver_1
* Rudimentary iterative solver. Create T x X matrix (vector of vector)
* to perform the finite difference method.
*
*
*/
err::eErrorCode solver_1(
    int n_timesteps,
    std::vector<double> & temps_n,
    std::vector<double> & temps_n_plus_1,
    int n_nodes,
    float amp,
    std::string & data_file_prefix
);

#endif
