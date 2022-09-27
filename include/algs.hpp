/**
 * Header file for different algorithms to compute 1-D finite difference method solution.
 */

#ifndef ALGS_H
#define ALGS_H

#include <vector>
#include "error_codes.hpp" // namespace err


/**
* solver_1
* Rudimentary iterative solver. Create T x X matrix (vector of vector)
* to perform the finite difference method.
*
*
*/
err::eErrorCode solver_1(int n_timesteps, int n_nodes, float amp);

#endif
