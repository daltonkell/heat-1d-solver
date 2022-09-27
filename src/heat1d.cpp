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
    if (argc != 3) {
        std::cout << "ERROR: you must supply n_timesteps and n_nodes" << std::endl;
        return err::INVALID_PARAMETERS;
    }

    /*
     * VARIABLE DECLARATIONS
     */

    bool stable     = true;       // stability testing
    float amp       = 0.0;        // amplitude
    int n_timesteps = 0;          // number time steps
    int n_nodes     = 0;          // number nodes
    std::string stability_string; // string to contain stability test message
    err::eErrorCode return_code;  // return code for main program

    /*
     * "PREPROCESSING"
     */

    n_timesteps = std::stoi(argv[1]);
    n_nodes     = std::stoi(argv[2]);

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

    return_code = solver_1(n_timesteps, n_nodes, amp);

    return return_code;
}
