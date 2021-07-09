#ifndef LIB_MARLINHELP_WHIZARD_WEIGHTFILEREADER
#define LIB_MARLINHELP_WHIZARD_WEIGHTFILEREADER 1

// Standard library
#include <string>
#include <vector>

namespace MarlinHelp {
namespace Whizard {

class WeightFileReader {
  /** Reader for Whizard rescan weight files.
   **/
  std::vector<std::vector<double>> m_weights{};

public:
  WeightFileReader() = default;
  WeightFileReader(const std::string &wf_path);

  int n_events() const { return m_weights.size(); };
  int n_points() const { return m_weights.at(0).size(); };
  std::vector<double> operator[](int i) const { return m_weights[i]; }
};

} // namespace Whizard
} // namespace MarlinHelp

#endif