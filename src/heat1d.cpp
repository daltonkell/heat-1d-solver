/*
 * Finite Difference Method solver for 1-D heat equation on a massless wire.
 */

#include <iostream>  // output streams: cout, flush; TODO clog, cerr
#include <cmath>     // pow
#include <string>
#include "algs.hpp"
#include "error_codes.hpp" // namespace err


/*
 * Constants
 */

// diffusivity
const double kappa = 1.0E-2;

float calc_amplitude(double kappa, double t_step, double x_step) {
    return ((kappa*t_step) / pow(x_step, 2));
}

int main(int argc, char* argv[]) {

    /*
     * check for number of arguments; as a rudimentary program,
     * there should be 3:
     * 1: program name
     * 2: timesteps
     * 3: nodes
     */
    if (argc != 4) {
        std::cout << "ERROR: supply n_timesteps, n_nodes, solver choice (1 | 2)" << std::endl;
        return err::INVALID_PARAMETERS;
    }

    /*
     * VARIABLE DECLARATIONS
     */

    bool stable     = true;       // stability testing
    float amp       = 0.0;        // amplitude
    int n_timesteps = 0;          // number time steps
    int n_nodes     = 0;          // number nodes
    int alg_choice  = 0;          // solver algorithm choice
    std::string stability_string; // string to contain stability test message
    err::eErrorCode return_code;  // return code for main program

    /*
     * "PREPROCESSING"
     */

    n_timesteps = std::stoi(argv[1]);
    n_nodes     = std::stoi(argv[2]);
    alg_choice  = std::stoi(argv[3]);

    // tell the users what they put in
    std::cout << "Number timesteps: " << n_timesteps << "\n"
              << "Number nodes:     " << n_nodes
              << std::endl;

    amp = calc_amplitude(kappa, 1, 1);
    std::cout << "Amplitude: " << amp << "\n";
    stable = (amp <= 1.0);
    if (stable) {
        stability_string = "PARAMETERS ARE STABLE!";
    } else {
        stability_string = "PARAMETERS ARE NOT STABLE!";
    }
    std::cout << stability_string << std::endl;;

    if (!stable) return err::UNSTABLE_PARAMETERS;

    // allocate memory here for past and current timesteps; each vector will
    // have the same number of nodes
    std::vector<double> v_nodes_tstep_n(n_nodes);
    std::vector<double> v_nodes_tstep_n_plus_1(n_nodes);

    // outfile prefix; each timestep will have a file
    std::string datafile_pref{"test"};

    // execute solver on it
    switch (alg_choice) {
        case 1:
            // brute force solver
            return_code = solver_1(n_timesteps, v_nodes_tstep_n, v_nodes_tstep_n_plus_1, n_nodes, amp, datafile_pref);
            break;
        case 2:
            // OpenMP enabled solver
            return_code = solver_2(n_timesteps, v_nodes_tstep_n, v_nodes_tstep_n_plus_1, n_nodes, amp, datafile_pref);
            break;
        default:
            return_code = err::BAD_SOLVER_CHOICE;
    }

    // vector cleanup part of destructor

    return return_code;
}
