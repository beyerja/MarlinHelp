#include <MarlinHelp/Whizard/WeightFileReader.h>

// Standard library
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace MarlinHelp {
namespace Whizard {

//------------------------------------------------------------------------------

WeightFileReader::WeightFileReader(const std::string &wf_path) {
  /** Constructor tries to read and interpret the weight file.
   **/

  // Input file stream
  std::ifstream wf(wf_path);

  // Weights for current event
  std::vector<double> w_evt{};

  int i_p;  // Index of rescan point
  double w; // Rescan point weight

  // Interpret each line of the file (first 2 numbers -> point index and weight)
  std::string line{};
  while (std::getline(wf, line)) {
    std::istringstream iss(line);
    if (!(iss >> i_p >> w)) {
      throw std::runtime_error("Can't interpret weight file line.");
    }

    // Use point index to figure out when event is over
    if (i_p == 0) {
      if (!w_evt.empty()) {
        m_weights.push_back(w_evt);
      }
      w_evt = {};
      continue; // Don't use this one, is SM -> w = 1
    } else {
      w_evt.push_back(w);
    }
  }

  // Save also last event weight (doesn't get triggered by next event)
  if (!w_evt.empty()) {
    m_weights.push_back(w_evt);
  }
}

//------------------------------------------------------------------------------

} // namespace Whizard
} // namespace MarlinHelp
